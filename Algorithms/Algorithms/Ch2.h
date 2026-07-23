#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <utility>
#include <map>
#include <unordered_map>

void RomanToInt(std::string str);

template<typename T>
class Graph
{
public:
    
    struct Vertex
    {
        T item = T();
        int indegree = 0;
        bool visited = false;
    };

private:
    std::vector<std::vector<int>> matrix;
    std::vector<Vertex> vertices;

public:
    Graph(int vertexCount)
        : matrix(vertexCount, std::vector<int>(vertexCount, 0))
    {
        vertices.reserve(vertexCount);
    }

    void InsertVertex(const Vertex& vertex)
    {
        if (vertices.size() >= matrix.size())
        {
            return;
        }

        vertices.push_back(vertex);
    }

    void InsertEdge(int from, int to)
    {
        if (matrix[from][to] == 0)
        {
            matrix[from][to] = 1;
            vertices[to].indegree++;
        }
    }

    bool HasEdge(int from, int to) const
    {
        return matrix[from][to] != 0;
    }

    void ResetVisited()
    {
        for (int i = 0; i < vertices.size(); i++)
        {
            vertices[i].visited = false;
        }
    }

    void DFS(int start_index)
    {   
        vertices[start_index].visited = true;
        std::cout << start_index << " ";

        for (int i = 0; i < vertices.size(); i++)
        {
            if (matrix[start_index][i] == 1 && vertices[i].visited == false)
            {
                DFS(i);
            }
        }
    }

    void BFS(int start_index)
    {
        std::queue<int> q;

        q.push(start_index);
        vertices[start_index].visited = true;
        
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();

            std::cout << vertices[cur].item << " ";

            for (int i = 0; i < static_cast<int>(vertices.size()); i++)
            {
                if (matrix[cur][i] == 1 && vertices[i].visited == false)
                {
                    q.push(i);
                    vertices[i].visited = true;
                }
            }
        }
    }

private:

    void AllPath(int current, int end, std::vector<int>& path)
    {
        vertices[current].visited = true;
        path.push_back(current);

        if (current == end)
        {
            for (int i = 0; i < path.size(); i++)
            {
                std::cout << path[i] << " ";
            }
            std::cout << std::endl;
        }
        else
        {
            for (int i = 0; i < static_cast<int>(vertices.size()); i++)
            {
                if (matrix[current][i] == 1 && vertices[i].visited == false)
                {
                    AllPath(i, end, path);
                }
            }
        }

        path.pop_back();
        vertices[current].visited = false;
    }

public:

    void AllPath(int start, int end)
    {
        ResetVisited();

        std::vector<int> path;
        AllPath(start, end, path);
    }

    void TopologicalSort_q()
    {
        std::queue<int> q;
        std::vector<Vertex> temp = vertices;

        for (int i = 0; i < static_cast<int>(temp.size()); i++)
        {
            if (temp[i].indegree == 0 && temp[i].visited == false)
            {
                q.push(i);
                temp[i].visited = true;
            }
        }

        while (!q.empty())
        {
            int cur = q.front();
            q.pop();

            std::cout << cur << " ";

            for (int j = 0; j < static_cast<int>(temp.size()); j++)
            {
                if (matrix[cur][j] == 1)
                {
                    temp[j].indegree--;

                    if (temp[j].indegree == 0 && temp[j].visited == false)
                    {
                        q.push(j);
                        temp[j].visited = true;
                    }
                }
            }
        }
    }

    void TopologicalSortDFSRecursive(
        int current, 
        std::vector<bool>& visited,  
        std::stack<int>& result)
    {
        visited[current] = true;

        for (int next = 0;
            next < static_cast<int>(vertices.size());
            next++)
        {
            if (matrix[current][next] == 1 &&
                visited[next] == false)
            {
                TopologicalSortDFSRecursive(next, visited, result);
            }
        }

        result.push(current);
    }

    void TopologicalSort_DFS()
    {
        std::vector<bool> visited(vertices.size(), false);
        std::stack<int> result;

        for (int i = 0;
            i < static_cast<int>(vertices.size());
            i++)
        {
            if (visited[i] == false)
            {
                TopologicalSortDFSRecursive(i, visited, result);
            }
        }

        while (!result.empty())
        {
            int current = result.top();
            result.pop();

            std::cout << current << ' ';
        }
    }

    void ShortestPathBFS(int start, int destination)
    {
        std::queue<int> q;
        std::vector<bool> visited(vertices.size(), false);
        std::vector<int> parent(vertices.size(), -1);

        visited[start] = true;
        q.push(start);

        while (!q.empty())
        {
            int current = q.front();
            q.pop();

            if (current == destination)
            {
                break;
            }

            for (int next = 0;
                next < static_cast<int>(vertices.size());
                next++)
            {
                if (matrix[current][next] == 1 &&
                    !visited[next])
                {
                    visited[next] = true;
                    parent[next] = current;
                    q.push(next);
                }
            }
        }

        if (!visited[destination])
        {
            std::cout << "No Path found\n";
            return;
        }

        std::vector<int> path;

        for (int current = destination;
            current != -1;
            current = parent[current])
        {
            path.push_back(current);
        }

        for (auto it = path.rbegin(); it != path.rend(); ++it)
        {
            std::cout << *it << ' ';
        }
    }

    bool CycleDFS(int start_index, std::vector<int>& state, std::vector<int>& path)
    {
        state[start_index] = 1;
        path.push_back(start_index);

        for (int i = 0; i < static_cast<int>(vertices.size()); i++)
        {
            if (matrix[start_index][i] == 1 && state[i] == 0)
            {
                if (CycleDFS(i, state, path))
                {
                    return true;
                }
                else
                {
                    continue;
                }

            }

            if (matrix[start_index][i] == 1 && state[i] == 1)
            {
                path.push_back(i);
                return true;
            }
        }

        path.pop_back();
        state[start_index] = 2;
        return false;
    }


    void DetectCycle(int start)
    {
        std::vector<int> state(static_cast<int>(vertices.size()), 0);
        std::vector<int> path;
        
        bool result = CycleDFS(start, state, path);

        std::cout << "Path : ";
        for (int i = 0; i < static_cast<int>(path.size()); i++)
        {
            std::cout << path[i] << " ";
        }
        std::cout << std::endl;

        std::cout << result << std::endl;
    }

    void ConnectedComponents()
    {
        int j = 1;

        for (int i = 0; i < static_cast<int>(vertices.size()); i++)
        {
            if (vertices[i].visited == false)
            {
                std::cout << "component " << j << " : ";
                DFS(i);
                std::cout << std::endl;
                j++;
            }
        }
    }


    bool CanReach(int start, int target)
    {
        vertices[start].visited = true;

        if (start == target)
        {
            return true;
        }

        for (int i = 0; i < static_cast<int>(vertices.size()); i++)
        {
            if (matrix[start][i] == 1 && vertices[i].visited == false)
            {
                if (CanReach(i, target))
                {
                    return true;
                }
            }
        }

        return false;
    }

    bool IsStronglyConnected(int vertex1, int vertex2)
    {
        ResetVisited();
        bool vertex1ToVertex2 = CanReach(vertex1, vertex2);

        ResetVisited();
        bool vertex2ToVertex1 = CanReach(vertex2, vertex1);

        return vertex1ToVertex2 && vertex2ToVertex1;
    }

    std::vector<std::vector<int>> StrongComponents()
    {
        int vertex_count = static_cast<int>(vertices.size());

        std::vector<bool> assigned(vertex_count, false);
        std::vector<std::vector<int>> components;

        for (int i = 0; i < vertex_count; i++)
        {
            if (assigned[i])
            {
                continue;
            }

            std::vector<int> component;

            for (int j = 0; j < vertex_count; j++)
            {
                if (assigned[j])
                {
                    continue;
                }

                if (IsStronglyConnected(i, j))
                {
                    component.push_back(j);
                    assigned[j] = true;
                }
            }

            components.push_back(component);
        }

        return components;
    }

    void BruteForceStrongComponents()
    {
        std::vector<std::vector<int>> components = StrongComponents();
        int j = 1;

        for (int i = 0; i < static_cast<int>(components.size()); i++)
        {
            std::cout << "Components " << j << " : { ";

            for (const auto& e : components[i])
            {
                std::cout << e << " ";
            }

            std::cout << "}" << std::endl;
            j++;
        }
    }

    std::vector<std::vector<int>> TransposeMatrix()
    {
        int vertex_count = int(vertices.size());
        std::vector<std::vector<int>> TM(vertex_count,
            std::vector<int>(vertex_count, 0));

        for (int i = 0; i < vertex_count; i++)
        {
            for (int j = 0; j < vertex_count; j++)
            {
                TM[j][i] = matrix[i][j];
            }
        }

        return TM;
    }

    void FinishOrderDFS(int current, std::vector<int>& order)
    {
        int vertex_count = static_cast<int>(vertices.size());
        vertices[current].visited = true;

        for (int i = 0; i < vertex_count; i++)
        {
            if (matrix[current][i] == 1 && vertices[i].visited == false)
            {
                FinishOrderDFS(i, order);
            }
        }

        order.push_back(current);
    }

    void TransposeDFS(int current, std::vector<int>& component,
        const std::vector<std::vector<int>>& TM)
    {
        vertices[current].visited = true;
        
        component.push_back(current);

        for (int j = 0; j < static_cast<int>(vertices.size()); j++)
        {
            if (TM[current][j] == 1 &&
                vertices[j].visited == false)
            {
                TransposeDFS(j, component, TM);
            }
        }
    }


    void Kosaraju()
    {
        std::vector<int> order;
        std::vector<std::vector<int>> components;
        int vertex_count = static_cast<int>(vertices.size());

        ResetVisited();

        for (int i = 0; i < vertex_count; i++)
        {
            if (vertices[i].visited == false)
            {
                FinishOrderDFS(i, order);
            }
        }

        std::vector<std::vector<int>> tm = TransposeMatrix();
        int order_count = static_cast<int>(order.size());

        ResetVisited();

        for (int i = order_count - 1; i >= 0; i--)
        {
            int vertex_index = order[i];
            std::vector<int> component;
            
            if (vertices[vertex_index].visited == false)
            {
                TransposeDFS(vertex_index, component, tm);
                components.push_back(component);
            }
        }

        int j = 1;

        for (int i = 0; i < static_cast<int>(components.size()); i++)
        {
            std::cout << "Components " << j << " : { ";

            for (const auto& e : components[i])
            {
                std::cout << e << " ";
            }

            std::cout << "}" << std::endl;
            j++;
        }
    }
};
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
        std::cout << vertices[start_index].item << " ";

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

    void Path(int current, int end, std::vector<int>& path)
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
                    Path(i, end, path);
                }
            }
        }

        path.pop_back();
        vertices[current].visited = false;
    }

public:

    void Path(int start, int end)
    {
        ResetVisited();

        std::vector<int> path;
        Path(start, end, path);
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

};
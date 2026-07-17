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

};
#include "Ch2.h"

void RomanToInt(std::string str)
{
	std::unordered_map<char, int> um{
	{'I', 1} ,{'V', 5}, {'X', 10},
	{'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
	};

	int result = um[str[0]];

	for (int i = 1; i < str.length(); i++)
	{
		if (result >= um[str[i]])
		{
			result += um[str[i]];
		}
		else
		{
			result = um[str[i]] - result;
		}
	}
	
	std::cout << "Result Value : " << result << std::endl;
}



// std::vector<std::vector<Edge>> graph(vertex_count);

std::vector<int> Dijkstra(
	const std::vector<std::vector<Edge>>& graph,
	int start)
{
	const int INF = std::numeric_limits<int>::max() / 2;
	int vertex_count = static_cast<int>(graph.size());
	std::vector<int> distance(vertex_count, INF);

	distance[start] = 0;
	using pair = std::pair<int, int>; // {현재까지 거리, 버텍스 번호}

	std::priority_queue<pair, std::vector<pair>, std::greater<pair>> pq;

	pq.push({ distance[start], start });

	while (!pq.empty())
	{
		pair cur = pq.top();
		int current = cur.second;
		pq.pop();

		if (distance[current] < cur.first)
		{
			continue;
		}

		for (int i = 0; i < int(graph[current].size()); i++)
		{
			int next = graph[current][i].to;
			int new_distance = distance[current] + graph[current][i].weight;

			if (new_distance < distance[next])
			{
				distance[next] = new_distance;
				pq.push({ distance[next], next });
			}
		}
	}

	return distance;
}


void Print_Dijkstra(const std::vector<std::vector<Edge>>& graph, int start)
{
	std::vector<int> distance = Dijkstra(graph, start);

	const int INF = std::numeric_limits<int>::max() / 2;
	int i = 0;

	for (const auto& d : distance)
	{
		if (d == INF)
		{
			std::cout << "Can't reach  Vertex[" << i << "]" << std::endl;
			i++;
		}
		else
		{
			std::cout << "Vertex[" << i << "]'s min_distance : " << d << std::endl;
			i++;
		}
	}
}

#include "Ch3.h"

int BottomUpFibo(int n)
{
	std::vector<int> fibo;

	fibo.push_back(0);
	fibo.push_back(1);

	for (int i = 2; i <= n; i++)
	{
		int e = fibo[i - 2] + fibo[i - 1];
		fibo.push_back(e);
	}

	return fibo[n];
}

int TopDownFibo_(int n, std::vector<int>& memo)
{
	if (n == 0)
	{
		return 0;
	}

	if (n == 1)
	{
		return 1;
	}

	if (memo[n] != -1)
	{
		return memo[n];
	}

	memo[n] = TopDownFibo_(n - 2, memo) + TopDownFibo_(n - 1, memo);

	return memo[n];
}

int TopDownFibo(int n)
{
	std::vector<int> memo(n + 1, -1);

	return TopDownFibo_(n, memo);
}

//vector<int> price_table = { 0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30 };

int Cut_MaxPrice(int length)
{
	// length == 0~10
	std::vector<int> price_table = { 0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30 };
	std::vector<int> memo(length + 1);

	memo[0] = 0;

	for (int cur_length = 1; cur_length <= length; cur_length++)
	{
		int max_price = 0;

		for (int i = 1; i <= cur_length; i++)
		{
			int temp = price_table[i] + memo[cur_length - i];
			max_price = max_price > temp ? max_price : temp;
		}

		memo[cur_length] = max_price;
	}

	return memo[length];
}

std::vector<int> BellmanFord(const std::vector<Edge_>& edges, 
	int start, int vertex_count)
{
	const int INF = std::numeric_limits<int>::max() / 2;
	std::vector<int> distance(vertex_count, INF);

	distance[start] = 0;

	int edge_count = static_cast<int>(edges.size());

	for (int i = 0; i < vertex_count - 1; i++)
	{
		for (int j = 0; j < edge_count; j++)
		{
			if (distance[edges[j].from] == INF)
			{
				continue;
			}

			int new_distance = distance[edges[j].from] + edges[j].weight;

			if (new_distance < distance[edges[j].to])
			{
				distance[edges[j].to] = new_distance;
			}
		}
	}
	return distance;
}

void Print_BF(const std::vector<Edge_>& edges,
	int start, int vertex_count)
{
	std::vector<int> distance = BellmanFord(edges, start, vertex_count);
	int edge_count = static_cast<int>(edges.size());
	const int INF = std::numeric_limits<int>::max() / 2;

	for (int j = 0; j < edge_count; j++)
	{
		if (distance[edges[j].from] == INF)
		{
			continue;
		}

		int new_distance = distance[edges[j].from] + edges[j].weight;

		if (new_distance < distance[edges[j].to])
		{
			std::cout << "Negative Cycle" << std::endl;
			return;
		}
	}


	for (int i = 0; i < distance.size(); i++)
	{
		std::cout  << i  << " : " << distance[i] << std::endl;
	}
}

void PrintMatrix(std::vector<std::vector<int>>& matrix)
{
	int row_size = int(matrix.size());
	int col_size = int(matrix[0].size());
	const int INF = std::numeric_limits<int>::max() / 2;


	for (int i = 0; i < row_size; i++)
	{
		for (int j = 0; j < col_size; j++)
		{
			if (matrix[i][j] == INF)
			{
				std::cout << "INF" << '\t';
			}
			else
			{
				std::cout << matrix[i][j] << '\t';
			}
		}
		std::cout << std::endl;
	}
}

void FloydWarshall(std::vector<std::vector<int>>& distance, int vertex_count)
{

	const int INF = std::numeric_limits<int>::max() / 2;

	for (int k = 0; k < vertex_count; k++)
	{
		for (int i = 0; i < vertex_count; i++)
		{
			for (int j = 0; j < vertex_count; j++)
			{
				if (distance[i][k] == INF || distance[k][j] == INF)
				{
					continue;
				}

				int d_ij = distance[i][j];
				int d_ik_kj = distance[i][k] + distance[k][j];
				int min = d_ij < d_ik_kj ? d_ij : d_ik_kj;
				distance[i][j] = min;
			}
		}
	}
}

void Print_FloydWarshall(std::vector<Edge_>& edges, int vertex_count)
{
	const int INF = std::numeric_limits<int>::max() / 2;

	std::vector<std::vector<int>> distance(vertex_count,
		std::vector<int>(vertex_count, INF));

	for (int i = 0; i < vertex_count; i++)
	{
		distance[i][i] = 0;
	}

	for (int i = 0; i < static_cast<int>(edges.size()); i++)
	{
		int from = edges[i].from;
		int to = edges[i].to;
		int weight = edges[i].weight;
		distance[from][to] = weight;
	}

	FloydWarshall(distance, vertex_count);
	PrintMatrix(distance);
}


std::string LCS(const std::string& str1, const std::string& str2)
{
	int n1 = str1.length();
	int n2 = str2.length();

	if (n1 == 0 || n2 == 0)
	{
		return "";
	}

	if (str1[n1 - 1] == str2[n2 - 1])
	{
		std::string r = LCS(str1.substr(0, n1 - 1), str2.substr(0, n2 - 1));
		r.append(1, str1[n1 - 1]);
		return r;
	}
	else
	{
		std::string r1 = LCS(str1, str2.substr(0, n2 - 1));
		std::string r2 = LCS(str1.substr(0, n1 - 1), str2);

		std::string result = r1.length() > r2.length() ? r1 : r2;
		return result;
	}
}


int UnboundedBag(const std::vector<int>& value, const std::vector<int>& weight,
	int cur_weight, std::vector<int>& memo)
{
	if (cur_weight <= 0)
	{
		return 0;
	}

	if (memo[cur_weight] != -1)
	{
		return memo[cur_weight];
	}

	memo[cur_weight] = 0;

	for (int i = 0; i < int(value.size()); i++)
	{	
		if (weight[i] <= 0)
		{
			continue;
		}

		if (cur_weight - weight[i] < 0)
		{
			continue;
		}

		int temp = value[i] + UnboundedBag(value, weight, cur_weight - weight[i], memo);
		memo[cur_weight] = memo[cur_weight] > temp ? memo[cur_weight] : temp;
	}
	return memo[cur_weight];
}

int UnboundedBag2(const std::vector<int>& value, const std::vector<int>& weight,
	int cur_weight)
{
	if (cur_weight <= 0)
	{
		return 0;
	}

	std::vector<int> memo(cur_weight + 1, 0);

	for (int i = 1; i <= cur_weight; i++)
	{
		int max_value = 0;

		for (int j = 0; j < int(value.size()); j++)
		{
			if (weight[j] <= 0)
			{
				continue;
			}

			if (i - weight[j] < 0)
			{
				continue;
			}

			int temp = value[j] + memo[i - weight[j]];
			max_value = max_value > temp ? max_value : temp;
		}

		memo[i] = max_value;
	}
	return memo[cur_weight];
}


int ZeroOneBag(const std::vector<int>& value, const std::vector<int>& weight,
	int cur_item ,int cur_weight, std::vector<std::vector<int>>& memo)
{
	if (cur_weight <= 0 || cur_item <= 0)
	{
		return 0;
	}

	if (memo[cur_item][cur_weight] != -1)
	{
		return memo[cur_item][cur_weight];
	}

	memo[cur_item][cur_weight] = 0;

	if (cur_weight - weight[cur_item - 1] < 0)
	{
		memo[cur_item][cur_weight] = ZeroOneBag(value, weight, cur_item - 1, cur_weight, memo);
		return memo[cur_item][cur_weight];
	}

	int temp1 = value[cur_item - 1] + ZeroOneBag(value, weight, cur_item - 1, 
		cur_weight - weight[cur_item - 1], memo);

	int temp2 = ZeroOneBag(value, weight, cur_item - 1, cur_weight, memo);

	int max_value = temp1 > temp2 ? temp1 : temp2;
	memo[cur_item][cur_weight] = max_value;

	return memo[cur_item][cur_weight];
}


int ZeroOneBag2(const std::vector<int>& value, const std::vector<int>& weight,
	int cur_weight)
{
	int item_count = static_cast<int>(value.size());
	std::vector<std::vector<int>> memo(item_count + 1, std::vector<int>(cur_weight + 1, 0));

	for (int i = 1; i <= item_count; i++)//int w = 0; w <= cur_weight; w++
	{
		for (int w = 0; w <= cur_weight; w++)//int i = 1; i <= item_count; i++
		{
			int m = 0;

			if (w - weight[i - 1] < 0)
			{
				memo[i][w] = memo[i - 1][w];
				continue;
			}

			int temp1 = value[i - 1] + memo[i - 1][w - weight[i - 1]];
			int temp2 = memo[i - 1][w];
			m = temp1 > temp2 ? temp1 : temp2;

			memo[i][w] = m;
		}
	}

	return memo[item_count][cur_weight];
}


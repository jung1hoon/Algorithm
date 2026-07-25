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
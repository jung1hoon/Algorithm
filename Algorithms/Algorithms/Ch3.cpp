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
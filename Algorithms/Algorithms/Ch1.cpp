#include "Ch1.h"



std::string Add(std::string str1, std::string str2)
{
	std::string result;

	int N = str1.size() > str2.size() ? str1.size() : str2.size();

	if (str1.size() < N)
	{
		str1.insert(0, N - str1.size(), '0');
	}

	if (str2.size() < N)
	{
		str2.insert(0, N - str2.size(), '0');
	}

	int carry = 0;

	for (int t = N - 1; t >= 0; t--)
	{
		int r = (str1[t] - '0') + (str2[t] - '0') + carry;

		//std::string temp = std::to_string(r);

		//if (temp.size() == 2)
		//{
		//	carry = temp[0] - '0';

		//	result.insert(0, 1, temp[1]);
		//}
		//else
		//{
		//	carry = 0;

		//	result.insert(0, 1, temp[0]);
		//}
		int digit = r % 10;
		carry = (r / 10) % 10;

		result.insert(0, 1, char(digit + '0'));
	}
	
	if (carry != 0)
	{
		result.insert(0, 1, char(carry + '0'));
	}

	return result;
}


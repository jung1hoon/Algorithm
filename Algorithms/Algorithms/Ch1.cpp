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

// str1 >= str2 라고 가정
std::string Subtract(std::string str1, std::string str2)
{
	if (str1 == str2)
	{
		return "0";
	}

	int n = str1.size();

	if (str1.size() < str2.size())
	{
		exit(-1);
	}
	else if (str1.size() > str2.size())
	{
		str2.insert(0, n - str2.size(), '0');
	}

	std::string result;

	for (int i = n - 1; i >= 0; i--)
	{
		int r = 0;

		if ((str1[i] - '0') < (str2[i] - '0'))
		{
			r = ((str1[i] - '0') + 10) - (str2[i] - '0');

			int j = i;

			while (j - 1 >= 0 && str1[j - 1] == '0')
			{
				str1[j - 1] = '9';
				j--;
			}

			if (j - 1 >= 0)
			{
				str1[j - 1]--;
			}

		}
		else
		{
			r = (str1[i] - '0') - (str2[i] - '0');
		}


		result.insert(0, 1, char(r + '0'));

	}

	int t = 0;

	while (result[t] == '0')
	{
		t++;
	}

	if (t != 0)
	{
		result = result.substr(t, n - t);
	}

	return result;
}

std::string Multiply(std::string str1, std::string str2)
{
	if (str1 == "0" || str2 == "0")
	{
		return "0";
	}

	std::string result("0");
	std::string temp;

	int n1 = str1.size();
	int n2 = str2.size();

	int count = 0;

	for (int i = n2 - 1; i >= 0; i--)
	{
		int carry = 0;
		temp.clear();

		for (int j = n1 - 1; j >= 0; j--)
		{
			int r = (str1[j] - '0') * (str2[i] - '0') + carry;

			carry = r / 10;

			int digit = r % 10;

			temp.insert(0, 1, char(digit + '0'));
		}

		if (carry != 0)
		{
			temp.insert(0, 1, char(carry + '0'));
		}

		for (int k = 0; k < count; k++)
		{
			temp.push_back('0');
		}
		count++;

		result = Add(result, temp);
	}
	return result;
}


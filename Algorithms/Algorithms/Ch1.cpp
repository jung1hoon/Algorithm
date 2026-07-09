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

std::string Karatsuba(std::string str1, std::string str2)
{
	if (str1 == "0" || str2 == "0")
	{
		return "0";
	}

	int N = std::max(str1.size(), str2.size());
	str1.insert(0, N - str1.size(), '0');
	str2.insert(0, N - str2.size(), '0');

	if (N == 1)
	{
		std::string result;
		int r = (str1[0] - '0') * (str2[0] - '0');
		for (int exp = 1; r / exp > 0; exp *= 10)
		{
			result.insert(0, 1, char(((r / exp) % 10) + '0'));
		}
		return result;
	}

	int mid = N / 2;

	std::string a = str1.substr(0, mid);
	std::string b = str1.substr(mid, N - mid);
	std::string c = str2.substr(0, mid);
	std::string d = str2.substr(mid, N - mid);

	std::string ac = Karatsuba(a, c);
	std::string bd = Karatsuba(b, d);
	std::string z = Karatsuba(Add(a, b), Add(c, d));

	std::string temp = Subtract(z, Add(ac, bd));

	ac.append((N - mid) * 2, '0');	// *
	temp.append((N - mid), '0');	// *

	std::string result = Add(Add(ac, temp), bd);

	return result;
}


void Merge(int arr[], int left, int mid, int right)
{
	std::vector<int> temp;

	int i = left;
	int j = mid + 1;

	while (i <= mid && j <= right)
	{
		if (arr[i] <= arr[j])
		{
			temp.push_back(arr[i]);
			i++;
		}
		else
		{
			temp.push_back(arr[j]);
			j++;
		}
	}

	while (i <= mid)
	{
		temp.push_back(arr[i]);
		i++;
	}

	while (j <= right)
	{
		temp.push_back(arr[j]);
		j++;
	}

	for (int k = 0; k < static_cast<int>(temp.size()); k++)
	{
		arr[left + k] = temp[k];
	}
}

void MergeSort(int arr[], int left, int right)
{
	if (left >= right)
	{
		return;
	}

	int mid = left + (right - left) / 2; // int 오버플로우 방지

	MergeSort(arr, left, mid);
	MergeSort(arr, mid + 1, right);

	Merge(arr, left, mid, right);
}

void MergeSort2(int arr[], int size)
{
	int width = 1;

	while (width < size)
	{
		for (int left = 0; left < size; left += width * 2)
		{
			int mid = std::min(left + width - 1, size - 1);
			int right = std::min(left + width * 2 - 1, size - 1);

			if (mid < right)
			{
				Merge(arr, left, mid, right);
			}
		}

		width *= 2;
	}
}

void PrintArr(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

int Count_O_n(int arr[], int size, int x)
{
	int count = 0;

	for (int i = 0; i < size; i++)
	{
		if (arr[i] == x)
		{
			count++;
		}
	}

	return count;
}

int BinarySearch(int arr[], int left_, int right_, int x)
{
	int left = left_;
	int right = right_;
	
	while (left <= right)
	{
		int mid = left + (right - left) / 2;

		if (arr[mid] < x)
		{
			left = mid + 1;
		}
		else if (arr[mid] > x)
		{
			right = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

int BinarySearchFirst(int arr[], int left_, int right_, int x)
{
	int left = left_;
	int right = right_;

	while (left <= right)
	{
		int mid = left + (right - left) / 2;

		if (arr[mid] < x)
		{
			left = mid + 1;
		}
		else if (arr[mid] > x)
		{
			right = mid - 1;
		}
		else if ((mid == left_ || arr[mid - 1] < x) && arr[mid] == x)
		{
			return mid;
		}
		else
		{
			right = mid - 1;
		}
	}
	return -1;
}

int BinarySearchLast(int arr[], int left_, int right_, int x)
{
	int left = left_;
	int right = right_;

	while (left <= right)
	{
		int mid = left + (right - left) / 2;

		if (arr[mid] < x)
		{
			left = mid + 1;
		}
		else if (arr[mid] > x)
		{
			right = mid - 1;
		}
		else if ((mid == right_ || arr[mid + 1] > x) && arr[mid] == x)
		{
			return mid;
		}
		else
		{
			left = mid + 1;
		}
	}
	return -1;
}


int Count_O_logn_n(int arr[], int left_, int right_, int x)
{
	if (arr[left_] > x || arr[right_] < x)
	{
		return 0;
	}

	int left = left_;
	int right = right_;
	int count = 0;
	int mid = left + (right - left) / 2;

	while (left <= right && arr[mid] != x)
	{
		if (arr[mid] < x)
		{	
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
		mid = left + (right - left) / 2;
	}

	if (left > right)
	{
		return 0;
	}

	for (int i = left; i <= right ; i++)
	{
		if (arr[i] == x)
		{
			count++;
		}
	}

	return count;
}

int Count_O_logn_n2(int arr[], int left_, int right_, int x)
{
	int index = BinarySearch(arr, left_, right_, x);
	int count = 0;

	if (index == -1)
	{
		return 0;
	}

	int i = index - 1;
	int j = index;

	while (i >= 0 && arr[i] == x)
	{
		count++;
		i--;
	}

	while (j <= right_ && arr[j] == x)
	{
		count++;
		j++;
	}

	return count;
}


int Count_O_logn(int arr[], int left_, int right_, int x)
{
	int first_index = BinarySearchFirst(arr, left_, right_, x);
	int last_index = BinarySearchLast(arr, left_, right_, x);

	if (first_index == -1)
	{
		return 0;
	}

	return last_index - first_index + 1;
}
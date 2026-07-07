#include "Ch1.h"

using namespace std;

int main()
{
	int arr[] = { 1,9,3,4,9,6,7,8,9 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int x = 9;

	sort(arr, arr + size, [](int a, int b) {return a < b;});
	PrintArr(arr, size);

	cout << "O(n) : " << Count_O_n(arr, size, x) << endl;
	cout << "O(logn + n){1} : " << Count_O_logn_n(arr, 0, size - 1, x) << endl;
	cout << "O(logn + n){2} : " << Count_O_logn_n2(arr, 0, size - 1, x) << endl;

	cout << "Answer : " << count(arr, arr + size, x) << endl;

	return 0;
}

#include "Ch1.h"

using namespace std;

int main()
{
	vector<int> arr = { 7,4,5,100,9,6,6,3,2,5 };

	int size = arr.size();

	PrintVec(arr);
	
	int r = K_th_SelectionSort(arr, 0, size - 1, 3);

	PrintVec(arr);

	cout << "result : " << r << endl;

	PrintMinMax(arr);

	return 0;
}

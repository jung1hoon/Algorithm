#include "Ch1.h"
#include "Ch2.h"

using namespace std;

int main()
{
	using Vertex = Graph<char>::Vertex;

	Graph<char> g(6);

	g.InsertVertex(Vertex{ 'A',false });
	g.InsertVertex({ 'B', false });
	g.InsertVertex(Vertex{ 'C',false });
	g.InsertVertex({ 'D', false });
	g.InsertVertex(Vertex{ 'E',false });
	g.InsertVertex({ 'F', false });

	g.InsertEdge(4,0);
	g.InsertEdge(4,1);
	g.InsertEdge(0,2);
	g.InsertEdge(5,0);
	g.InsertEdge(5,2);
	g.InsertEdge(2,3);
	g.InsertEdge(2,1);
	g.InsertEdge(3,1);

	g.TopologicalSort_DFS();



	return 0;
}


//vector<int> arr = { 3,2,1,6,19,4,12,14,9,15,7,8,11,3,13,2,5,10 };
//vector<int> arr2 = { 2,5,8,4,6,7,0,2,1,4,5,6,7 };

//int size = arr.size();
//int size2 = arr2.size();

//PrintVec(arr);
//
//int r = K_th_SelectionSort(arr, 3, size - 1, size - 3);

//PrintVec(arr);

//cout << "result : " << r << endl;

//PrintMinMax(arr);

//int r2 = MedianByPartition(arr, 3, size - 1);
//cout << "result2 : " << r2 << endl;

//CountingSort(arr, 0, size - 1);
//PrintVec(arr);


//std::vector<std::string> str = {
//"COW", "DOG", "SEA", "RUG", "ROW", "MOB",
//"BOX", "TAB", "BAR", "EAR", "TAR", "DIG",
//"BIG", "TEA", "NOW", "FOX"
//};

//RadixSort_str(str, 0, str.size() - 1, 3);
//PrintVec(str);
////BAR BIG BOX COW DIG DOG EAR FOX MOB NOW ROW RUG SEA TAB TAR TEA

//std::vector<float> arr3 = {
//	0.78f, 0.17f, 0.39f, 0.26f, 0.72f,
//	0.94f, 0.21f, 0.12f, 0.23f, 0.67f
//};

//BucketSort(arr3, 0, arr3.size() - 1);
//PrintVec(arr3);

	//std::unordered_map<char, int> um{
	//	{'I', 1} ,{'V', 5}, {'X', 10},
	//	{'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
	//};

	//RomanToInt("LVIII");


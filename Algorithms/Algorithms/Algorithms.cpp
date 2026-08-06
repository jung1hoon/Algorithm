#include "Ch1.h"
#include "Ch2.h"
#include "Ch3.h"

using namespace std;

int main()
{
	vector<int> values = { 6, 5, 3 }; // 아이템의 가치
	vector<int> weights = { 3, 2, 1 }; // 아이템의 무게
	int W = 5; // 가방 용량

	int item_size = static_cast<int>(values.size());

	//int W = 10; // 42
	//vector<int> weights = { 6, 2,  4,  3, 11 };
	//vector<int> values = { 20, 8, 14, 13, 35 };

	std::vector<std::vector<int>> memo(item_size + 1, std::vector<int>(W + 1, -1));

	cout << ZeroOneBag(values, weights, item_size, W, memo) << endl;
	cout << ZeroOneBag2(values, weights, W) << endl;

	//cout << UnboundedBag(values, weights, W, memo) << endl;
	//cout << UnboundedBag2(values, weights, W) << endl;

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



//---------------------------------------------------------------------------


//using Vertex = Graph<char>::Vertex;
//
//Graph<char> g(13);
//
//// 정점 0 ~ 12
//for (int i = 0; i < 13; i++)
//{
//	g.InsertVertex(Vertex{ static_cast<char>('A' + i), 0, false });
//}
//
//// 0번 정점
//g.InsertEdge(0, 1);
//g.InsertEdge(0, 5);
//
//// 2번 정점
//g.InsertEdge(2, 0);
//g.InsertEdge(2, 3);
//
//// 3번 정점
//g.InsertEdge(3, 2);
//g.InsertEdge(3, 5);
//
//// 4번 정점
//g.InsertEdge(4, 2);
//g.InsertEdge(4, 3);
//
//// 5번 정점
//g.InsertEdge(5, 4);
//
//// 6번 정점
//g.InsertEdge(6, 0);
//g.InsertEdge(6, 4);
//g.InsertEdge(6, 8);
//g.InsertEdge(6, 9);
//
//// 7번 정점
//g.InsertEdge(7, 6);
//g.InsertEdge(7, 9);
//
//// 8번 정점
//g.InsertEdge(8, 6);
//
//// 9번 정점
//g.InsertEdge(9, 10);
//g.InsertEdge(9, 11);
//
//// 10번 정점
//g.InsertEdge(10, 12);
//
//// 11번 정점
//g.InsertEdge(11, 4);
//g.InsertEdge(11, 12);
//
//// 12번 정점
//g.InsertEdge(12, 9);
//
//g.BruteForceStrongComponents();
//std::cout << std::endl;
//g.Kosaraju();


//---------------------------------------------------------------


//std::vector<std::vector<Edge>> graph(5);
//
//graph[0].push_back({ 1, 4 });
//graph[0].push_back({ 2, 2 });
//graph[2].push_back({ 1, 1 });
//graph[1].push_back({ 3, 5 });
//graph[2].push_back({ 3, 8 });
//graph[3].push_back({ 4, 2 });
//
//Print_Dijkstra(graph, 0);

//--------------------------------------------------------
// 
// 
////	std::vector<int> price_table = { 0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30 };
//
//for (int i = 0; i <= 10; i++)
//{
//	cout << "Optimal_Price" << "[" << i << "] : " << Cut_MaxPrice(i) << endl;
//}


//----------------------------------------------------


//int vertex_count = 5;
//
//std::vector<Edge_> edges =
//{
//    {0, 1, 4},
//    {0, 2, 10},
//    {0, 4, 20},
//
//    {1, 2, 3},
//    {1, 3, 8},
//
//    {2, 3, 2},
//
//    {3, 4, 1},
//
//    {4, 1, 2}
//};
//
//Print_FloydWarshall(edges, vertex_count);

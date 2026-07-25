#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <utility>
#include <map>
#include <unordered_map>
#include <functional>
#include <limits>

int BottomUpFibo(int n);
int TopDownFibo_(int n, std::vector<int>& memo);
int TopDownFibo(int n);

int Cut_MaxPrice(int length);

struct Edge_
{
    int from;
    int to;
    int weight;
};

std::vector<int> BellmanFord(const std::vector<Edge_>& edges,
    int start, int vertex_count);

void Print_BF(const std::vector<Edge_>& edges,
    int start, int vertex_count);

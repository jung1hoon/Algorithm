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

void PrintMatrix(std::vector<std::vector<int>>& matrix);
void FloydWarshall(std::vector<std::vector<int>>& distance, int vertex_count);
void Print_FloydWarshall(std::vector<Edge_>& edges, int vertex_count);

std::string LCS(const std::string& str1, const std::string& str2);



int UnboundedBag(const std::vector<int>& value, const std::vector<int>& weight,
    int cur_weight, std::vector<int>& memo);
int UnboundedBag2(const std::vector<int>& value, const std::vector<int>& weight,
    int cur_weight);

int ZeroOneBag(const std::vector<int>& value, const std::vector<int>& weight,
    int cur_item, int cur_weight, std::vector<std::vector<int>>& memo);
int ZeroOneBag2(const std::vector<int>& value, const std::vector<int>& weight,
    int cur_weight);
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <utility>

std::string Add(std::string str1, std::string str2);
std::string Subtract(std::string str1, std::string str2);
std::string Multiply(std::string str1, std::string str2);
std::string Karatsuba(std::string str1, std::string str2);

void Merge(int arr[], int left, int mid, int right);
void MergeSort(int arr[], int left, int right);
void MergeSort2(int arr[], int size);

int Count_O_n(int arr[], int size, int x);
int Count_O_logn_n(int arr[], int left, int right, int x);
int Count_O_logn_n2(int arr[], int left_, int right_, int x);
int Count_O_logn(int arr[], int left_, int right_, int x);

void PrintArr(int arr[], int size);
void PrintVec(const std::vector<int>& arr);
void swap(int& a, int& b);

void SelectionSortPass(std::vector<int>& arr, int left, int right);
int K_th_SelectionSort(std::vector<int>& arr, int left_, int right_, int k);
void PrintMinMax(const std::vector<int>& arr);
int PartitionByPivot(std::vector<int>& arr, int left, int right);
int MedianByPartition(std::vector<int>& arr, int left_, int right_);

void QuickSort(std::vector<int>& arr, int left, int right);


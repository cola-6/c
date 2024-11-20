#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//插入排序
void InsertSort(int* a, int n);
//希尔排序
void ShellSort(int* a, int n);
void PrintArray(int* a, int n);
//选择排序
void SelectSort(int* a, int n);
//快速排序
void QuickSort(int* a, int left, int right);
//快排非递归
void QuickSortNonR(int* a, int left, int right);
//归并排序递归实现
void MergeSort(int* a, int n);
//归并非递归实现
void MergeSortNonR(int* a, int n);
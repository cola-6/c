#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//��������
void InsertSort(int* a, int n);
//ϣ������
void ShellSort(int* a, int n);
void PrintArray(int* a, int n);
//ѡ������
void SelectSort(int* a, int n);
//��������
void QuickSort(int* a, int left, int right);
//���ŷǵݹ�
void QuickSortNonR(int* a, int left, int right);
//�鲢����ݹ�ʵ��
void MergeSort(int* a, int n);
//�鲢�ǵݹ�ʵ��
void MergeSortNonR(int* a, int n);
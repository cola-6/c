#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
//数组实现栈
typedef int STDataType;
typedef struct stack
{
	STDataType* a;
	int top;//指向栈顶元素，初始化为-1，指向栈顶元素的下一个位置，初始化为0
	int capacity;//因为需要扩容
}ST;

//初始化
void STInit(ST* pst);
//销毁
void STDestroy(ST* pst);
//插入
void STPush(ST* pst, STDataType x);
//删除
void STPop(ST* pst);
//取栈顶数据
STDataType STTop(ST* pst);
//判空
bool STEmpty(ST* pst);
//获取数据个数
int STSize(ST* pst);
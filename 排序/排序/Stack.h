#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
//����ʵ��ջ
typedef int STDataType;
typedef struct stack
{
	STDataType* a;
	int top;//ָ��ջ��Ԫ�أ���ʼ��Ϊ-1��ָ��ջ��Ԫ�ص���һ��λ�ã���ʼ��Ϊ0
	int capacity;//��Ϊ��Ҫ����
}ST;

//��ʼ��
void STInit(ST* pst);
//����
void STDestroy(ST* pst);
//����
void STPush(ST* pst, STDataType x);
//ɾ��
void STPop(ST* pst);
//ȡջ������
STDataType STTop(ST* pst);
//�п�
bool STEmpty(ST* pst);
//��ȡ���ݸ���
int STSize(ST* pst);
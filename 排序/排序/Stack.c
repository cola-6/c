#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"

//��ʼ��
void STInit(ST* pst)
{
	assert(pst);
	pst->a = NULL;
	//topָ��ջ��Ԫ�ص���һ��λ��(��size������ͬ)
	pst->top = 0;
	pst->capacity = 0;
}
//����
void STDestroy(ST* pst)
{
	assert(pst);
	free(pst->a);
	pst->a = NULL;
	pst->capacity = pst->top = 0;
}
//����
void STPush(ST* pst, STDataType x)
{
	assert(pst);
	//����
	if (pst->top == pst->capacity)
	{
		int newcapacity = pst->capacity == 0 ? 4 : 2 * pst->capacity;
		STDataType* tmp = (STDataType*)realloc(pst->a, newcapacity * sizeof(STDataType));
		if (tmp == NULL)
		{
			perror("realloc fail!");
			return;
		}
		pst->a = tmp;
		pst->capacity = newcapacity;
	}
	pst->a[pst->top] = x;
	pst->top++;
}
//ɾ��
void STPop(ST* pst)
{
	assert(pst);
	assert(pst->top > 0);
	pst->top--;
}
//ȡջ������
STDataType STTop(ST* pst)
{
	assert(pst);
	return pst->a[pst->top - 1];
}
//�п�
bool STEmpty(ST* pst)
{
	assert(pst);
	return pst->top == 0;
}
//��ȡ���ݸ���
int STSize(ST* pst)
{
	assert(pst);
	return pst->top;
}
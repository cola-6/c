#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"

//初始化
void STInit(ST* pst)
{
	assert(pst);
	pst->a = NULL;
	//top指向栈顶元素的下一个位置(和size意义相同)
	pst->top = 0;
	pst->capacity = 0;
}
//销毁
void STDestroy(ST* pst)
{
	assert(pst);
	free(pst->a);
	pst->a = NULL;
	pst->capacity = pst->top = 0;
}
//插入
void STPush(ST* pst, STDataType x)
{
	assert(pst);
	//扩容
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
//删除
void STPop(ST* pst)
{
	assert(pst);
	assert(pst->top > 0);
	pst->top--;
}
//取栈顶数据
STDataType STTop(ST* pst)
{
	assert(pst);
	return pst->a[pst->top - 1];
}
//判空
bool STEmpty(ST* pst)
{
	assert(pst);
	return pst->top == 0;
}
//获取数据个数
int STSize(ST* pst)
{
	assert(pst);
	return pst->top;
}
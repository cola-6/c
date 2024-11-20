#define _CRT_SECURE_NO_WARNINGS 1
#include"sort.h"
#include"Stack.h"
#include"string.h"
//排序，先单躺后整体

void InsertSort(int* a, int n);
void PrintArray(int* a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
//插入排序
//时间复杂度：最坏 逆序: O(N^2), 最好，顺序: O(N)
void InsertSort(int* a, int n)
{
    // end最后是n-2, 数组a[0] - a[n-1]
    for (int i = 0; i < n - 1; i++)  
    {
    //[0,end]有序， end+1位置的值插入 [0,end], 保持有序
        int end = i;
        int tmp = a[end + 1];
        while (end >= 0)
        {
            if (tmp < a[end])
            {
                a[end + 1] = a[end];
                end--;
            }
            else
            {
                break;
            }
        }
        a[end + 1] = tmp;
    }
}

//插入排序逆序效率太低 
//希尔排序
//时间复杂度 O(N^1.3)
// + 1 是为了保证最后一个gap一定是1 然后进入循环
        // gap > 1 时是预排序
        // gap == 1 时是插入排序
void ShellSort(int* a, int n)
{
    int gap = n;
    while (gap > 1)
    {
        gap = gap / 3 + 1;
        for (int i = 0; i < n - gap; i++)
        {
            int end = i;
            int tmp = a[end + gap];
            while (end >= 0)
            {
                if (tmp < a[end])
                {
                    a[end + gap] = a[end];
                    end = end - gap;
                }
                else
                {
                    break;
                }
            }
            a[end + gap] = tmp;
        }
    }
}

void Swap(int* a, int* b)
{
    int tmp = 0;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
//选择排序优化版
void SelectSort(int* a, int n)
{
    int begin = 0, end = n - 1;
    while (begin < end)
    {
        int mini = begin, maxi = begin;
        for (int i = begin + 1; i <= end; i++)
        {
            if (a[i] < a[mini])
            {
                mini = i;
            }
            if (a[i] > a[maxi])
            {
                maxi = i;
            }
        }

        Swap(&a[begin], &a[mini]);
        if (maxi == begin)
        {
            //maxi == mini
            Swap(&a[end], &a[mini]);
        }
        else
        {
            Swap(&a[end], &a[maxi]);
        }
        begin++;
        end--;
    }
}
//三数取中
int GetMidi(int* a, int left, int right)
{
    int midi = (left + right) / 2;
    //left midi right
    if (a[left] < a[midi])
    {
        if (a[midi] < a[right])
        {
            return midi;
        }
        else if(a[left] < a[right])//left < midi right < midi
        {
            return right;
        }
        else
        {
            return left;
        }
    }
    else//left > midi
    {
        if (a[midi] > a[right])
        {
            return midi;
        }
        else if(a[left] > a[right])//left > midi right > midi
        {
            return right;
        }
        else//left > midi right > left
        {
            return left;
        }
    }
}
//快速排序 
//避免有序情况下，效率退化 三数取中
//如果面试手撕，不用写三数取中和小区间优化，后续讲一讲就ok
// //void QuickSort(int* a, int left, int right)
//{
//	//递归结束条件
//	if (left >= right)
//	{
//		return;
//	}
//	//小区间优化，不再递归分割排序，减少递归次数
//	if ((right - left + 1) < 10)
//	{
//		InsertSort(a + left, right - left + 1);
//	}
//	else
//	{
//		//三数取中
        /*int midi = GetMidi(a, left, right);
        Swap(&a[left], &a[midi]);*/
        //int keyi = left;
        //int begin = left, end = right;
        //while (begin < end)
        //{
        //	//右边找小
        //	while (begin < end && a[end] >= a[keyi])
        //	{
        //		end--;
        //	}
        //	//左边找大
        //	while (begin < end && a[begin] <= a[keyi])
        //	{
        //		begin++;
        //	}

        //	Swap(&a[begin], &a[end]);
        //}
        //Swap(&a[keyi], &a[begin]);
        //keyi = begin;
//		//[left, keyi - 1]  keyi  [keyi + 1, right]
//		QuickSort(a, left, keyi - 1);
//		QuickSort(a, keyi + 1, right);
//	}
//}

// 快速排序hoare版本
int PartSort1(int* a, int left, int right)
{
    //三数取中
    int midi = GetMidi(a, left, right);
    Swap(&a[left], &a[midi]);
    int keyi = left;
    int begin = left, end = right;
    while (begin < end)
    {
        //右边找小
        while (begin < end && a[end] >= a[keyi])
        {
            end--;
        }
        //左边找大
        while (begin < end && a[begin] <= a[keyi])
        {
            begin++;
        }

        Swap(&a[begin], &a[end]);
    }
    Swap(&a[keyi], &a[begin]);
    return begin;
}
// 快速排序前后指针法
int PartSort2(int* a, int left, int right)
{
    //三数取中
    int midi = GetMidi(a, left, right);
    Swap(&a[left], &a[midi]);
    int keyi = left;
    int prev = left;
    int cur = prev + 1;
    while (cur <= right)
    {
        if (a[cur] < a[keyi] && ++prev != cur)
        {
            Swap(&a[prev], &a[cur]);
        }
        cur++;
    }
    Swap(&a[keyi], &a[prev]);
    return prev;
}

void QuickSort(int* a, int left, int right)
{
    //递归结束条件
    if (left >= right)
    {
        return;
    }
    int keyi = PartSort2(a, left, right);
    //[left, keyi - 1]  keyi  [keyi + 1, right]
    QuickSort(a, left, keyi - 1);
    QuickSort(a, keyi + 1, right);
}


//快速排序非递归
void QuickSortNonR(int* a, int left, int right)
{
    ST st;
    STInit(&st);
    STPush(&st, right);
    STPush(&st, left);
    while (!STEmpty(&st))
    {
        int begin = STTop(&st);
        STPop(&st);
        int end = STTop(&st);
        STPop(&st);
        int keyi = PartSort2(a, begin, end);
        //[begin, keyi - 1] keyi [keyi + 1, end]
        if (keyi + 1 < end)
        {
            STPush(&st, end);
            STPush(&st, keyi + 1);
        }
        if (begin < keyi - 1)
        {
            STPush(&st, keyi - 1);
            STPush(&st, begin);
        }
    }
    STDestroy(&st);
}

//时间复杂度： O(N*logN)
//空间复杂度： O(N) 额外开辟了一个数组
void _MergeSort(int* a, int* tmp, int begin, int end)
{
    if (begin == end)
        return;
    int mid = (begin + end) / 2;
    //如果[begin, mid] [mid + 1, end]有序就可以进行归并了
    //类似后序遍历
    _MergeSort(a, tmp, begin, mid);
    _MergeSort(a, tmp, mid + 1, end);
    //有序了
    //归并
    int begin1 = begin, end1 = mid;
    int begin2 = mid + 1, end2 = end;
    int i = begin;
    while (begin1 <= end1 && begin2 <= end2)
    {
        if (a[begin1] < a[begin2])
        {
            tmp[i++] = a[begin1++];
        }
        else
        {
            tmp[i++] = a[begin2++];
        }
    }
    while (begin1 <= end1)
    {
        tmp[i++] = a[begin1++];
    }
    while (begin2 <= end2)
    {
        tmp[i++] = a[begin2++];
    }
    memcpy(a + begin, tmp + begin, (end - begin + 1) * sizeof(int));
}

//归并排序递归实现
void MergeSort(int* a, int n)
{
    int* tmp = (int*)malloc(sizeof(int) * n);
    if (tmp == NULL)
    {
        perror("malloc fail!");
        return;
    }
    int begin = 0;
    int end = n - 1;
    _MergeSort(a, tmp, begin, end);
    free(tmp);
    tmp = NULL;
}
//归并非递归实现
void MergeSortNonR(int* a, int n)
{
    int* tmp = (int*)malloc(sizeof(int) * n);
    if (tmp == NULL)
    {
        perror("malloc fail!");
        return;
    }
    //gap--每组归并数据的数据个数
    int gap = 1;
    while (gap < n)
    {
        //11归并
        for (int i = 0; i < n; i += 2 * gap)
        {
            //i代表每次归并的起始位置
            //[begin1,end1] [begin2,end2]
            int begin1 = i, end1 = i + gap - 1;
            int begin2 = i + gap, end2 = i + 2 * gap - 1;
            //第二组都越界不存在，那这一组都不需要归并
            if (begin2 >= n)
            {
                break;
            }
            //第二组只有begin2没越界，end2越界了，需要修正一下继续归并
            if (end2 >= n)
            {
                end2 = n - 1;
            }
            int j = i;
            while (begin1 <= end1 && begin2 <= end2)
            {
                if (a[begin1] < a[begin2])
                {
                    tmp[j++] = a[begin1++];
                }
                else
                {
                    tmp[j++] = a[begin2++];
                }
            }
            while (begin1 <= end1)
            {
                tmp[j++] = a[begin1++];
            }
            while (begin2 <= end2)
            {
                tmp[j++] = a[begin2++];
            }
            memcpy(a + i, tmp + i, sizeof(int) * (end2 - i + 1));//若是出来后整体再拷贝会有问题
        }
        gap *= 2;
    }
    free(tmp);
    tmp = NULL;
}
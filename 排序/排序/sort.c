#define _CRT_SECURE_NO_WARNINGS 1
#include"sort.h"
#include"Stack.h"
#include"string.h"
//�����ȵ��ɺ�����

void InsertSort(int* a, int n);
void PrintArray(int* a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
//��������
//ʱ�临�Ӷȣ�� ����: O(N^2), ��ã�˳��: O(N)
void InsertSort(int* a, int n)
{
    // end�����n-2, ����a[0] - a[n-1]
    for (int i = 0; i < n - 1; i++)  
    {
    //[0,end]���� end+1λ�õ�ֵ���� [0,end], ��������
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

//������������Ч��̫�� 
//ϣ������
//ʱ�临�Ӷ� O(N^1.3)
// + 1 ��Ϊ�˱�֤���һ��gapһ����1 Ȼ�����ѭ��
        // gap > 1 ʱ��Ԥ����
        // gap == 1 ʱ�ǲ�������
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
//ѡ�������Ż���
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
//����ȡ��
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
//�������� 
//������������£�Ч���˻� ����ȡ��
//���������˺������д����ȡ�к�С�����Ż���������һ����ok
// //void QuickSort(int* a, int left, int right)
//{
//	//�ݹ��������
//	if (left >= right)
//	{
//		return;
//	}
//	//С�����Ż������ٵݹ�ָ����򣬼��ٵݹ����
//	if ((right - left + 1) < 10)
//	{
//		InsertSort(a + left, right - left + 1);
//	}
//	else
//	{
//		//����ȡ��
        /*int midi = GetMidi(a, left, right);
        Swap(&a[left], &a[midi]);*/
        //int keyi = left;
        //int begin = left, end = right;
        //while (begin < end)
        //{
        //	//�ұ���С
        //	while (begin < end && a[end] >= a[keyi])
        //	{
        //		end--;
        //	}
        //	//����Ҵ�
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

// ��������hoare�汾
int PartSort1(int* a, int left, int right)
{
    //����ȡ��
    int midi = GetMidi(a, left, right);
    Swap(&a[left], &a[midi]);
    int keyi = left;
    int begin = left, end = right;
    while (begin < end)
    {
        //�ұ���С
        while (begin < end && a[end] >= a[keyi])
        {
            end--;
        }
        //����Ҵ�
        while (begin < end && a[begin] <= a[keyi])
        {
            begin++;
        }

        Swap(&a[begin], &a[end]);
    }
    Swap(&a[keyi], &a[begin]);
    return begin;
}
// ��������ǰ��ָ�뷨
int PartSort2(int* a, int left, int right)
{
    //����ȡ��
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
    //�ݹ��������
    if (left >= right)
    {
        return;
    }
    int keyi = PartSort2(a, left, right);
    //[left, keyi - 1]  keyi  [keyi + 1, right]
    QuickSort(a, left, keyi - 1);
    QuickSort(a, keyi + 1, right);
}


//��������ǵݹ�
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

//ʱ�临�Ӷȣ� O(N*logN)
//�ռ临�Ӷȣ� O(N) ���⿪����һ������
void _MergeSort(int* a, int* tmp, int begin, int end)
{
    if (begin == end)
        return;
    int mid = (begin + end) / 2;
    //���[begin, mid] [mid + 1, end]����Ϳ��Խ��й鲢��
    //���ƺ������
    _MergeSort(a, tmp, begin, mid);
    _MergeSort(a, tmp, mid + 1, end);
    //������
    //�鲢
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

//�鲢����ݹ�ʵ��
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
//�鲢�ǵݹ�ʵ��
void MergeSortNonR(int* a, int n)
{
    int* tmp = (int*)malloc(sizeof(int) * n);
    if (tmp == NULL)
    {
        perror("malloc fail!");
        return;
    }
    //gap--ÿ��鲢���ݵ����ݸ���
    int gap = 1;
    while (gap < n)
    {
        //11�鲢
        for (int i = 0; i < n; i += 2 * gap)
        {
            //i����ÿ�ι鲢����ʼλ��
            //[begin1,end1] [begin2,end2]
            int begin1 = i, end1 = i + gap - 1;
            int begin2 = i + gap, end2 = i + 2 * gap - 1;
            //�ڶ��鶼Խ�粻���ڣ�����һ�鶼����Ҫ�鲢
            if (begin2 >= n)
            {
                break;
            }
            //�ڶ���ֻ��begin2ûԽ�磬end2Խ���ˣ���Ҫ����һ�¼����鲢
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
            memcpy(a + i, tmp + i, sizeof(int) * (end2 - i + 1));//���ǳ����������ٿ�����������
        }
        gap *= 2;
    }
    free(tmp);
    tmp = NULL;
}
#pragma once
#include<iostream>
#include<string>//�ַ���
#include<ctime>//ʱ�� �����
#include<stdlib.h>//�����
#include<malloc.h>
#include<fstream>
#include"myarray.hpp"
#include<vector>//����
#include<list>
#include<stack>
#include<set>
#include<algorithm>//��׼�㷨
#define NUM 100
#define DEC 10

void print_(int* arr,int digit)
{
	
}

class fastpower {
public:
    /**
     * ������
     * @param sa string�ַ���
     * @param sb string�ַ���
     * @param n int����
     * @return long������
     */
    const long long int M = 10000000033;
    long long power(long long base, long long power)
    {
        long long result = 1;
        while (power > 0) {
            if (power & 1) {					//��1   �˴��ȼ���if(power%2==1)
                result = result * base % M ;
            }
            power >>= 1;						//�˴��ȼ���power=power/2  ����һλ
            base = base*base% M;
        }
        return result;
    }
    long long str_to_long(string str)
    {
        long long int result = 0, digit = 1;
        for (int i = str.size()-1; i >= 0; digit *= 10, i--)
        {
            result += digit * (str[i] - '0');
        }
        return result;
    }
    long long solve(string sa, string sb, int n)
    {
        // write code here
        long long int a = str_to_long(sa);
        long long int b = str_to_long(sb);
        cout << a << " " << b << endl;
        long long int result = 0;
        for (long long int i = a; i < b; i++)
        {
            result += (i + 1) * power(n, i);
            result = result % M;
        }
        return result;
    }
};
class quicksort
{
public:
    void sort(int arr[], int l, int r)
	{
		if (l < r)
		{
			srand((unsigned int)time(NULL));
			swap(arr, ((int)rand() % (r - l + 1)) + l, r);	//���ȡһλ��Ϊ�м�λ�������һλ����
			int left = l;									//leftά���������λ��
			int less = l - 1;								//lessΪС���������һ��ֵ less<mid
			int more = r;									//moreΪ���������ǰһ��ֵ more>mid
			while (l < more)
			{
				if (arr[l] < arr[r])
				{
					swap(arr, ++less, l++);					//С������ȼ�less����ʱlessΪ���������һ��ֵ���ٻ�less��l����l++��ֱ��l��more���
				}
				else if (arr[l] > arr[r])
				{
					swap(arr, --more, l);					//��������ȼ�more����ʱmoreΪr���һ��δ�����ֵ���ٰ�l��ֵ����more�ϣ�ע���ʱl��ֵ��δ����l��++
				}
				else
				{
					l++;									//�������l++��lʼ��Ϊ��������һ��ֵ
				}
			}
			swap(arr, r, more);								//������ɺ��ú��r��more����
			sort(arr, left, less);					//leftΪ��������ˣ�lessΪ������ǰһ��λ��
			sort(arr, more + 1, r);						//rΪ�������Ҷˣ�more+1Ϊ��������һ��λ��
		}
	}
private:
	void swap(int arr[], int a, int b)
	{
		int tmp = arr[a];
		arr[a] = arr[b];
		arr[b] = tmp;
	}
};
class radixsort
{
public:
	void radix(int arr0[], int l, int r)
	{
		int digits = find_digits(arr0,l,r);
		int* container = new int[r - l + 1];
		for (int i = 0; i < digits; i++)
		{
			int a[DEC];									//Ƶ�α�
			for (int p = 0; p < DEC; p++)				//��ʼ��
			{
				a[p] = 0;
			}
			for (int j = l; j <= r; j++)				//�����õ�Ƶ�α�
			{
				a[get_one_digit(arr0[j], i)]++;
			}
			for (int k = 1; k < DEC; k++)				//����ۼ� �õ�ǰ׺�� ������a[i]��ʾ  �����λ��(digit)�ϣ�С��i�ĸ���
			{
				a[k] = a[k-1] + a[k];
			}
			for (int d = r; d >= l; d--)
			{
				int th = get_one_digit(arr0[d], i);
				container[a[th]-1] = arr0[d];			//��������ѣ�����arr��ĳһλiֵ����a[i]��Ƶ�κͣ���arr[x]�ŵ�container[]��a[i]λ����ȥ
				a[th]--;
			}
			for (int n = 0; n < r - l + 1; n++)			//ȡ��container�е�ֵ��arr
			{
				arr0[n + l] = container[n];
			}
		}
		delete []container;
	}
	int get_one_digit(int a,int d)						//ȡ������ĳһλ��ֵ
	{
		for (int b = 0; b < d; b++)
		{
			a/=10;
		}
		int res = a % DEC;
		return res;
	}
	int find_digits(int ar[],int left,int right)		//��ȡ���������
	{
		
		for (int i = 1; i <= right - left; i++)
		{
			if (ar[left] < ar[left + i])
			{
				swap(ar, left, left + i);
			}
		}
		int num = ar[left];
		int res = 0;
		while ( num!= 0)
		{
			num /= 10;
			res++;
		}
		return res;
	}
	void swap(int arr1[], int a, int b)
	{
		int temp;
		temp = arr1[a];
		arr1[a] = arr1[b];
		arr1[b] = temp;
	}
};



//���Ժ���
/*
void test()
{
		srand((unsigned int)time(NULL));
	int arr[NUM];
	for (int i = 0; i < NUM; i++)
	{
		arr[i] = rand() % 1000000;
	}

	vector<int> compair;
	for (int i = 0; i < NUM; i++)
	{
		compair.push_back(arr[i]);
	}
	sort(compair.begin(), compair.end());

	quicksort t;
	t.sort(arr,0,NUM-1);

	int res = 1;
	for (int i = 0; i < NUM; i++)
	{
		if (arr[i] != compair.at(i))
		{
			res = 0;
		}
	}
	return res;
}
*/

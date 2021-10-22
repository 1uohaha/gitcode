#pragma once
#include<iostream>
#include<string>//字符串
#include<ctime>//时间 随机数
#include<stdlib.h>//随机数
#include<malloc.h>
#include<fstream>
#include"myarray.hpp"
#include<vector>//容器
#include<list>
#include<stack>
#include<set>
#include<algorithm>//标准算法
#define NUM 100
#define DEC 10

void print_(int* arr,int digit)
{
	
}

class fastpower {
public:
    /**
     * 快速幂
     * @param sa string字符串
     * @param sb string字符串
     * @param n int整型
     * @return long长整型
     */
    const long long int M = 10000000033;
    long long power(long long base, long long power)
    {
        long long result = 1;
        while (power > 0) {
            if (power & 1) {					//与1   此处等价于if(power%2==1)
                result = result * base % M ;
            }
            power >>= 1;						//此处等价于power=power/2  右移一位
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
			swap(arr, ((int)rand() % (r - l + 1)) + l, r);	//随机取一位，为中间位，与最后一位交换
			int left = l;									//left维护数组左端位置
			int less = l - 1;								//less为小于区域最后一个值 less<mid
			int more = r;									//more为大于区域的前一个值 more>mid
			while (l < more)
			{
				if (arr[l] < arr[r])
				{
					swap(arr, ++less, l++);					//小于情况先加less，此时less为等于区最后一个值，再换less和l，再l++，直到l与more汇合
				}
				else if (arr[l] > arr[r])
				{
					swap(arr, --more, l);					//大于情况先减more，此时more为r左边一个未排序的值，再把l的值换到more上，注意此时l的值仍未排序，l不++
				}
				else
				{
					l++;									//等于情况l++，l始终为等于区下一个值
				}
			}
			swap(arr, r, more);								//排序完成后将置后的r与more交换
			sort(arr, left, less);					//left为数组最左端，less为等于区前一个位置
			sort(arr, more + 1, r);						//r为数组最右端，more+1为等于区后一个位置
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
			int a[DEC];									//频次表
			for (int p = 0; p < DEC; p++)				//初始化
			{
				a[p] = 0;
			}
			for (int j = l; j <= r; j++)				//遍历得到频次表
			{
				a[get_one_digit(arr0[j], i)]++;
			}
			for (int k = 1; k < DEC; k++)				//向后累加 得到前缀和 ：其中a[i]表示  在这个位数(digit)上，小于i的个数
			{
				a[k] = a[k-1] + a[k];
			}
			for (int d = r; d >= l; d--)
			{
				int th = get_one_digit(arr0[d], i);
				container[a[th]-1] = arr0[d];			//从右往左把，根据arr的某一位i值，和a[i]的频次和，把arr[x]放到container[]的a[i]位置上去
				a[th]--;
			}
			for (int n = 0; n < r - l + 1; n++)			//取出container中的值到arr
			{
				arr0[n + l] = container[n];
			}
		}
		delete []container;
	}
	int get_one_digit(int a,int d)						//取出数中某一位的值
	{
		for (int b = 0; b < d; b++)
		{
			a/=10;
		}
		int res = a % DEC;
		return res;
	}
	int find_digits(int ar[],int left,int right)		//获取最大数长度
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



//测试函数
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

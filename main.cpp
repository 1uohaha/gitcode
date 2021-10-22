#include"head.h"
using namespace std;
//constexpr auto NUM = 100;//宏定义
#define _begin 0
#define _end NUM-1
void print(int arr[])
{
	for (int i = 0; i < NUM; i++)
	{
		cout << arr[i] << " ";
	}
}

void fun(int fun_arr[])
{
	quicksort t;
	t.sort(fun_arr, _begin, _end);
}
int test()
{
	srand((unsigned int)time(NULL));			//随机数组
	int arr[NUM];
	for (int i = 0; i < NUM; i++)
	{
		arr[i] = rand() % 1000000;
	}

	vector<int> compair;						//拷贝到容器排序
	for (int i = _begin; i < _end +1; i++)
	{
		compair.push_back(arr[i]);
	}
	sort(compair.begin(), compair.end());

	fun(arr);									//测试函数排序

	int res = 1;								//比较两种数组是否相等
	for (int i = _begin; i < _end + 1; i++)
	{
		if (arr[i] != compair.at(i-_begin))
		{
			res = 0;
		}
	}
	return res;
}
void runtest()
{
	int j = 0;
	for (int i = 0; i < 10000; i++)
	{
		if (!test())
		{
			cout << "不通过" << endl;
			break;
		}
		else
		{
			j++;
			if (j >= 1000)
			{
				cout << "通过1000次" << endl;
				j = 0;
			}
		}
	}
	cout << "结束" << endl;
}
int main()
{
	cout << "hello world" << endl;
	
	runtest();

	system("pause");
	return 0;
}
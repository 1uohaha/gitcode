#pragma once
#include<iostream>
#include<string>//字符串
#include<fstream>
using namespace std;

template <class T>
class myarr
{
public:
	//有参构造
	myarr(int capacity) 
	{
		this->m_capacity = capacity;
		this->m_size = 0;
		int X = this->m_capacity;
		this->Taddr = new T[5];
	}
	//拷贝构造
	myarr(const myarr& a)
	{
		this->m_capacity = a.m_capacity;
		this->m_size = a.m_size;
		int X = a.m_capacity;
		this->Taddr = new T[X];
		for (int i = 0; i < a.m_size; i++)
		{
			this->Taddr[i] = a.Taddr[i];
		}
	}
	~myarr() 
	{
		if (this->Taddr != NULL)
		{
			delete [] this->Taddr;
			this->Taddr = NULL;
		}
	}

	//重载= 操作符  防止浅拷贝问题  这种情况 -> P1 = P2
	myarr& operator=(const myarr& myarray) {
		if (this->Taddr != NULL) {
			delete[] this->Taddr;
			this->m_capacity = 0;
			this->m_size = 0;
		}
		this->m_capacity = myarray.m_capacity;
		this->m_size = myarray.m_size;
		this->Taddr = new T[this->m_capacity];
		for (int i = 0; i < myarray.m_size; i++) {
			this->Taddr[i] = myarray.Taddr[i];
		}
		return *this;
	}
	//尾插法
	void Push_back(const T& val)
	{
		if (this->m_capacity == this->m_size)
		{
			return;
		}
		this->Taddr[this->m_size] = val;
		this->m_size++;
	}

	//尾删法
	void Pop_back()
	{
		if (this->m_size == 0)
		{
			return;
		}
		this->m_size--;
	}
	//重载[] 操作符  arr[0]
	T& operator [](int index)
	{
		return this->Taddr[index]; //不考虑越界，用户自己去处理
	}
private:
	T* Taddr;
	int m_capacity;
	int m_size;
};



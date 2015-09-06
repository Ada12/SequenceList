// SequenceList.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#define MaxSize 20
typedef struct SqList
{
	int a[MaxSize];
	int length;
};

using namespace std;

int DeleteMin(SqList &l)
{
	if(l.length == 0)
	{
		cout << "Error";
	}
	int min = l.a[0];
	int pos = 0;
	for(int i = 0; i < l.length; i ++)
	{
		if(min > l.a[i])
		{
			min = l.a[i];
			pos = i;
		}
	}
	l.a[pos] = l.a[l.length-1];
	return min;
}

int DeleteAll(SqList &l, int target)
{
	//一步一步来看 针对一个位置进行分析 不同情况不同对待
	int k = 0;
	for(int i = 0; i < l.length; i ++)
	{
		if(l.a[i] == target)
		{
			k ++;
		}
		else
		{
			l.a[i-k] = l.a[i];
		}
	}
	l.length = l.length-k;
	return k;
}

void LeftCycle(SqList &l, int digit)
{
	
}

void _tmain(int argc, _TCHAR* argv[])
{
	SqList sl;
	sl.a[0] = 6;
	sl.a[1] = 8;
	sl.a[2] = 5;
	sl.a[3] = 1;
	sl.a[4] = 3;
	sl.a[5] = 8;
	sl.a[6] = 9;
	sl.a[7] = 10;
	sl.length = 8;

//	int result = DeleteMin(sl);
//	cout << result;
//	cout << endl;

	int k = DeleteAll(sl, 8);
	for(int i = 0; i < sl.length; i ++)
	{
		cout << sl.a[i];
		cout << endl;
	}
}


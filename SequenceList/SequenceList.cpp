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

int DeleteOrderInterval(SqList &l, int small, int large)
{
	if(small > large)
	{
		cout << "Error";
	}
	int k = 0;
	for(int i = 0; i  < l.length; i ++)
	{
		
	}
	return 0;
}

int DeleteInterval(SqList &l, int small, int large)
{
	if(small > large)
	{
		cout << "Error";
	}
	int k = 0;
	for(int i = 0; i < l.length; i ++)
	{
		if((l.a[i] < large)&&(l.a[i] > small))
		{
			k ++;
		}
		else
		{
			l.a[i-k] = l.a[i];
		}
	}
	l.length = l.length - k;
	return k;
}

void DeleteRepeat(SqList &l)
{
	if(l.length <= 0)
	{
		cout << "Error";
	}
	int mark;
	for(int i = 0; i < l.length; i ++)
	{
		mark = l.a[i];
		int k = 0;
		for(int j = i + 1; j < l.length; j++)
		{
			if(l.a[i] == l.a[j])
			{
				k ++;
			}
			else
			{
				l.a[j-k] = l.a[j];
			}
		}
		l.length = l.length - k;
	}
}

SqList MergeTwoOrder(SqList la, SqList lb)
{
	SqList lc;
	lc.length = la.length + lb.length;
	//for(int i = 0,j = 0; i < lc.length ; i ++)
	//{
		
	//}
	int i = 0, j =0, count = 0;
	while(i < la.length & j < lb.length){
		if(la.a[i] < lb.a[j]){
			lc.a[count] = la.a[i];
			i++;
			count++;
		}else{
			lc.a[count] = lb.a[j];
			j++;
			count++;
		}

		if (i == la.length)
		{
			while (j < lb.length)
			{
				lc.a[count] = lb.a[j];
				j++;
				count++;
			}
		}else if(j == lb.length){
			while (i < la.length)
			{
				lc.a[count] = la.a[i];
				i++;
				count++;
			}
		}

	}
	return lc;
}

SqList MyMergeTwoOrder(SqList la, SqList lb)
{
	SqList lc;
	lc.length = la.length + lb.length;
	int i = 0, j = 0, k = 0;
	while((i < la.length)&&(j < lb.length))
	{
		if(la.a[i]<= lb.a[j])
		{
			lc.a[k] = la.a[i];
			i++;
			k++;
		}
		else
		{
			lc.a[k] = lb.a[j];
			j++;
			k++;
		}
	}
	while(i < la.length)
	{
		lc.a[k] = la.a[i];
		i++;
		k++;
	}
	while(j < lb.length)
	{
		lc.a[k] = lb.a[j];
		j++;
		k++;
	}
	return lc;
}

int Median(SqList &la, SqList &lb)
{
	int sa = 0, sb = 0, ma, mb, ea = la.length-1, eb = la.length-1;
	while((sa != ea)&&(sb != eb))
	{
		ma = (sa + ea)/2;
		mb = (sb + eb)/2;
		if(la.a[ma] == lb.a[mb])
		{
			return la.a[ma];
		}
		if(la.a[ma] < lb.a[mb])
		{
			if((sa + ea)%2 == 0)
			{
				sa = ma;
				eb = mb;
			}else
			{
				sa = ma + 1;
				eb = mb;
			}
		}
		else
		{
			if((sa + ea)%2 == 0)
			{
				ea = ma;
				sb = mb;
			}else
			{
				ea = ma;
				sb = mb + 1;
			}
		}
	}
	return la.a[sa]< lb.a[sb]? la.a[sa] : lb.a[sb];
}

int CalculateMainElement(SqList l)
{
	int m = l.a[0];
	int num = 1;
	for(int i = 1; i < l.length; i ++)
	{
		if(num == 0)
		{
			m = l.a[i];
		}
		if(m ==l.a[i])
		{
			num ++;
		}
		else
		{
			num--;
		}
	}
	int max = 0;
	for(int j = 0; j < l.length; j ++)
	{
		if(l.a[j] == m)
		{
			max ++;
		}
	}
	if(max > l.length/2)
	{
		return m;
	}
	else
	{
		return -1;
	}
}

void _tmain(int argc, _TCHAR* argv[])
{
	SqList sl;
	sl.a[0] = 0;
	sl.a[1] = 5;
	sl.a[2] = 5;
	sl.a[3] = 3;
	sl.a[4] = 5;
	sl.a[5] = 1;
	sl.a[6] = 5;
	sl.a[7] = 5;
	sl.length = 8;

	SqList la;
	la.a[0] = 1;
	la.a[1] = 3;
	la.a[2] = 5;
	la.a[3] = 7;
	la.a[4] = 9;
	la.length = 5;
	SqList lb;
	lb.a[0] = 2;
	lb.a[1] = 4;
	lb.a[2] = 6;
	lb.a[3] = 8;
	lb.a[4] = 10;
	lb.length = 5;

//	int result = DeleteMin(sl);
//	cout << result;
//	cout << endl;

//	int k = DeleteAll(sl, 8);
//	int k = DeleteInterval(sl, 1, 9);
//	DeleteRepeat(sl);
//	SqList lc = MyMergeTwoOrder(la, lb);

//	int result = Median(la, lb);
//	cout << result;
//	for(int i = 0; i < lb.length; i ++)
//	{
//		cout << lb.a[i];
//		cout << endl;
//	}

//	for(int i = 0; i < sl.length; i ++)
//	{
//		cout << sl.a[i];
//		cout << endl;
//	}

	int result = CalculateMainElement(sl);
	cout << result;
	cout << endl;
}


// APPLE_P1479.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <string>
#include <string.h>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <numeric>
#include <set>
#include <map>
#include <functional>
#include <unordered_set>
#include <unordered_map>
using namespace std;

char a[1000];
char l[1000], r[1000];
char alpha = 'x';
int CharToInt(char example[])
{
	int res=0;
	int f = example[0]=='-'?-1:1;
	for (int i = 0; i <=strlen(example)-1; i++)
	{
		if (example[i]>='0' && example[i]<='9')
		{
			res = res * 10 + (example[i] - '0');
		}
	}
	return res*f;
}

int CharToInt2(char ex[])
{
	int s = 0;
	int res=0;
	char p[20];
	memset(p, 0, sizeof(p));
	
	for (int i = 0; i < strlen(ex); i++)
	{
		
		if (ex[i]=='-'  || ex[i] == '+')
		{
			if (strlen(p)>0)
			{
				if (!(p[s-1] >= 'a'&&p[s-1] <= 'z'))
				{
					res += CharToInt(p);
				}
			}
			memset(p,0,sizeof(p));
			s = 0;
			p[s] = ex[i];
			s++;
		}
		else
		{
			p[s] = ex[i];
			s++;
		}
	}

	if (!(p[s - 1] >= 'a'&&p[s - 1] <= 'z'))
	{
		res += CharToInt(p);
	}
	return res;
}

int xxx(char ex[])
{
	int tot = 0;
	int index = 0;
	for (int i = 0; i <= strlen(ex) - 1; i++)
	{
		if (ex[i] == '-' || ex[i] == '+')
		{
			index = i;
		}
		if (ex[i] >= 'a' && ex[i] <= 'z')
		{
			alpha = ex[i];
			char temp[20];
			memset(temp, 0, sizeof(temp));
			for (int j = index; j <= i - 1; j++)
			{
				temp[j - index] = ex[j];
			}
			tot += CharToInt(temp);
		}
	}
	return tot;
}

int main()
{
	memset(a, 0, sizeof(a));
	memset(l, 0, sizeof(l));
	memset(r, 0, sizeof(r));

	cin >> a;
	for (int i = 0; i <= strlen(a)-1; i++)
	{
		if (a[i]=='=')
		{
			for (int j = i+1; j <=strlen(a)-1 ; j++)
			{
				r[j-i-1] = a[j];
			}
		}
		else
		{
			l[i] = a[i];
		}
	}

	double lx=0.0, rx=0.0;
	double lvalue=0.0, rvalue = 0.0;
	lvalue = (double)CharToInt2(l);
	rvalue = (double)CharToInt2(r);
	lx = (double)xxx(l);
	rx = (double)xxx(r);
	double x = ((double)rvalue - (double)lvalue) / ((double)lx - (double)rx);
	printf("%c=%.3lf",alpha,x);
    return 0;
}


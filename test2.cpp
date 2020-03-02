#include <bits/stdc++.h>
#include "data_structure.h"
using namespace std;
NUM Max(NUM a,NUM b)
//可以改为min,比较绝对值的大小或者其他的二元函数
//该函数需满足f(a,f(b,c))==f(f(a,b),c) 
{
	if(a>b) return a;
	return b;
}
int main()
//输入元素的个数n、操作的个数m与询问的个数q 
//接着输入n个初始元素、m次操作以及q次询问(在[l,r]区间内f的值) 
//对于每一次询问，输出结果 
//样例见最下方 
{
	int n,m,q,x,y;
	ReadNum(n);
	ReadNum(m);
	ReadNum(q);
	int num[10010];
	for(int i=1;i<=n;i++) ReadNum(num[i]);
	SEGTREEA a(10010,Max,num);
	for(int i=1;i<=m;i++)
	{
		ReadNum(x);
		ReadNum(y);
		a.Change(x,y);
	}
	for(int i=1;i<=q;i++)
	{
		ReadNum(x);
		ReadNum(y);
		cout<<a.Answer(x,y)<<endl;
	}	
	return 0;
}
/*
Sample Input:
5 1 3
1 2 3 4 5
4 -1
2 4
3 5
1 5

Sample Output:
3
5
5

*/

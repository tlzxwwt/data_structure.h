#include <bits/stdc++.h>
#include "data_structure.h"
using namespace std;
NUM Max(NUM a,NUM b)
//���Ը�Ϊmin,�ȽϾ���ֵ�Ĵ�С���������Ķ�Ԫ����
//�ú���������f(a,f(b,c))==f(f(a,b),c) 
{
	if(a>b) return a;
	return b;
}
int main()
//����Ԫ�صĸ���n�������ĸ���m��ѯ�ʵĸ���q 
//��������n����ʼԪ�ء�m�β����Լ�q��ѯ��(��[l,r]������f��ֵ) 
//����ÿһ��ѯ�ʣ������� 
//���������·� 
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

#include <bits/stdc++.h>
#include "data_structure.h"
using namespace std;
int main()
//�������(�ϲ�)�Ĵ���n��ѯ�ʵĸ���m
//��������n�β�����m��ѯ��
//����ÿһ��ѯ�ʣ�����Ƿ���ͬһ������
//���������·� 
{
	UFSET s(10010);
	int n,m,x,y;
	ReadNum(n);
	ReadNum(m);
	for(int i=1;i<=n;i++)
	{
		ReadNum(x);
		ReadNum(y);
		s.Union(x,y);
	}
	for(int i=1;i<=m;i++)
	{
		ReadNum(x);
		ReadNum(y);
		cout<<s.IfSameSet(x,y)<<endl;
	}	
	return 0;
}
/*
Sample Input:
5 5
1 2
3 4
2 3
5 6
7 1
1 5
3 4
7 4
5 7
9 8

Sample Output:
0
1
1
0
0
*/

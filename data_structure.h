//last updated on 1,3,2020
//可以在主函数中用Help(cout)来输出帮助和提示 
#ifndef _DATA_STRUCTURE_H_
#define _DATA_STRUCTURE_H_
#include <iostream>
#include <stdio.h>
#include <vector>
#define NUM int //int or long long
#define MAX_SIZE 10010 //default size
using namespace std;
void Help(ostream &of)
{
	of<<"目前支持的函数："<<endl;
	of<<"ReadNum\t输入整数（int或long long）"<<endl;
	of<<endl;	
	of<<"目前支持的数据结构："<<endl;
	of<<"UFSET\t并查集"<<endl;
}
inline void ReadNum(int &s)
{
	s=0;
	char c=getchar();
	int f=1;
	while('0'>c||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9')
	{
		s=s*10+c-'0';
		c=getchar();
	}
	s*=f;
}
inline void ReadNum(long long &s)
{
	s=0;
	char c=getchar();
	int f=1;
	while('0'>c||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9')
	{
		s=s*10+c-'0';
		c=getchar();
	}
	s*=f;
}
class UFSET
{
	public :
		NUM size;
		vector<NUM> father;
		UFSET(NUM a=10010)
		{
			size=a;
			for(NUM i=1;i<=size;i++)
			{
				father.push_back(i);
			}
		}
		NUM FindFather(NUM k)
		{
			if(father[k]==k) return k;
			father[k]=FindFather(father[k]);
			return father[k];
		}
		void Union(NUM k1,NUM k2)
		{
			father[FindFather(k1)]=FindFather(k2);
		}
		bool IfSameSet(NUM k1,NUM k2)
		{
			return FindFather(k1)==FindFather(k2);
		}
};
class SEGTREENODE
{
	public:
		NUM l,r,m;
		NUM v;
		NUM lazy;
};
class SEGTREEB
{
	public:
		NUM 
}
//class SEGTREEA
//{
//	public:
//		NUM size;
//		vector<NUM> 
//}
//template <class V>
//class SEGTREENODE
//{
//	NUM l,r,m;
//	V v;
////	SEGTREENODE(NUM a,NUM b,V c)
////	{
////		l=a;
////		r=b;
////		m=(a+b)/2;
////		v=c;
////	}
//};
//template <class V>
//class SEGTREEA
//{
//	public:
//		V (*f)(V,V);
//		NUM size;
//		vector<SEGTREENODE<V> > tree;
//		void BuildTree(NUM pos,NUM l,NUM r,V v[])
//		{
//			if(l==r)
//			{
//				//tree[pos]=SEGTREENODE<V>(l,r,v[l]);
//				tree[pos].l=l;
//				tree[pos].r=r;
//				tree[pos].m=(l+r)/2;
//				tree[pos].v=v[l];
//				return;
//			}
//			
//			//tree[pos]=SEGTREENODE(l,r,f())
//		}
//		SEGTREEA(NUM a,V(*p)(V,V),V v[])
//		{
//			size=a;
//			f=p;
//			BuildTree(1,1,size,v);
//		}
//};
#endif

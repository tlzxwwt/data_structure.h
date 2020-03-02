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
	of<<"SEGTREEA\t线段树A"<<endl;
	of<<"SEGTREEB\t线段树B"<<endl;
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
		int size;
		vector<int> father;
		UFSET(int a=10010)
		{
			size=a;
			father.push_back(0);
			for(int i=1;i<=size;i++)
			{
				father.push_back(i);
			}
		}
		int FindFather(int k)
		{
			if(father[k]==k) return k;
			father[k]=FindFather(father[k]);
			return father[k];
		}
		void Union(int k1,int k2)
		{
			father[FindFather(k1)]=FindFather(k2);
		}
		bool IfSameSet(int k1,int k2)
		{
			return FindFather(k1)==FindFather(k2);
		}
};
class SEGTREENODE
{
	public:
		int l,r,m;
		NUM v;
		NUM lazy;
		SEGTREENODE(int a=1,int b=1,NUM c=0)
		{
			l=a;
			r=b;
			m=(a+b)/2;
			v=c;
			lazy=0;
		}
};
class SEGTREEA
{
	public:
		int size;
		NUM (*f)(NUM,NUM);
		vector<SEGTREENODE> tree;
		void BuildTree(int pos,int l,int r,NUM a[])
		{
			tree[pos]=SEGTREENODE(l,r,a[l]);
			if(l==r) return;
			BuildTree(pos*2,l,tree[pos].m,a);
			BuildTree(pos*2+1,tree[pos].m+1,r,a);
			tree[pos].v=f(tree[pos*2].v,tree[pos*2+1].v);
		}
		SEGTREEA(int s,NUM (*p)(NUM,NUM),NUM a[])
		{
			size=s;
			f=p;
			tree.resize(s*4+1);
			BuildTree(1,1,size,a);
		}
		void Change(int pos,const int &k,const NUM &v)
		{
			if(tree[pos].l==k&&tree[pos].r==k)
			{
				tree[pos].v=v;
				return;
			}
			if(tree[pos].m<k) Change(pos*2+1,k,v);
			else Change(pos*2,k,v);
			tree[pos].v=f(tree[pos*2].v,tree[pos*2+1].v);
		}
		void Change(const int &k,const NUM &v)
		{
			Change(1,k,v);
		}				
};
class SEGTREEB
{
	public:
		NUM size;
		vector<SEGTREENODE> tree;
		void BuildTree(int pos,int l,int r,NUM a[])
		{
			tree[pos]=SEGTREENODE(l,r,a[l]);
			if(l==r) return;
			BuildTree(pos*2,l,tree[pos].m,a);
			BuildTree(pos*2+1,tree[pos].m+1,r,a);
			tree[pos].v=tree[pos*2].v+tree[pos*2+1].v;
		}
		SEGTREEB(int s,NUM a[])
		{
			size=s;
			tree.resize(s*4+1);
			BuildTree(1,1,size,a);
		}
		void Down(const int &pos)
		{
			tree[pos*2].lazy+=tree[pos].lazy;
			tree[pos*2+1].lazy+=tree[pos].lazy;
			tree[pos*2].v+=tree[pos].lazy*(tree[pos*2].r-tree[pos*2].l+1);
			tree[pos*2+1].v+=tree[pos].lazy*(tree[pos*2+1].r-tree[pos*2+1].l+1);
			tree[pos].lazy=0;
		}
		void Change(int pos,const int &k,const NUM &v)
		{
			if(tree[pos].l==k&&tree[pos].r==k)
			{
				tree[pos].v=v;
				return;
			}
			if(tree[pos].lazy!=0) Down(pos);
			if(tree[pos].m<k) Change(pos*2+1,k,v);
			else Change(pos*2,k,v);
			tree[pos].v=tree[pos*2].v+tree[pos*2+1].v;
		}
		void Change(const int &k,const NUM &v)
		{
			Change(1,k,v);
		}		
		void AddRange(int pos,const int &l,const int &r,const NUM &v)
		{
			if(tree[pos].l>=l&&tree[pos].r<=r)
			{
				tree[pos].v+=(tree[pos].r-tree[pos].l+1)*v;
				tree[pos].lazy+=v;
				return;
			}
			if(tree[pos].lazy!=0) Down(pos);
			if(tree[pos].m>=l) AddRange(pos*2,l,r,v);
			if(tree[pos].m<r) AddRange(pos*2+1,l,r,v);
			tree[pos].v=tree[pos*2].v+tree[pos*2+1].v;
		}
		void AddRange(const int &l,const int &r,const NUM &v)
		{
			AddRange(1,l,r,v);
		}
		NUM Sum(int pos,const int &l,const int &r)
		{
			if(tree[pos].l>=l&&tree[pos].r<=r)
			{
				return tree[pos].v;
			}
			if(tree[pos].lazy!=0) Down(pos);
			NUM ts=0;
			if(tree[pos].m>=l) ts+=Sum(pos*2,l,r);
			if(tree[pos].m<r) ts+=Sum(pos*2+1,l,r);
			return ts;
		}
		NUM sum(const int &l,const int &r)
		{
			return Sum(1,l,r);
		}
};
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

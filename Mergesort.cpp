// 归并排序 分治 复杂度 nlogn 且稳定
// 要排序[l,r]，长度为1直接退出，否则分为[l,m],[m+1,r];
// 递归两个子区间进行归并排序
// 将排序好的子区间合并

#include <bits/stdc++.h>
using namespace std;

int a[10001],c[10001];

void mergesort(int l,int r){
    if(l==r)return;
    int m=(l+r)/2;
    mergesort(l,m);
    mergesort(m+1,r);
    int p1=l,p2=m+1,tot=0;
    while(p1<=m&&p2<=r){
        if(a[p1]<=a[p2])
            c[++tot]==a[p1++];
        else
            c[++tot]=a[p2++];
    }
    while(p1<=m)
        c[++tot]=a[p1++];
    while(p2<=m)
        c[++tot]=a[p2++];
    for(int i=1;i<=tot;i++)
        a[i+l-1]=c[i];
}
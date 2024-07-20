// 基数排序 复杂度 nk
// 拆分成 m 个关键字 从后往前 依次对m个关键字进行排序
// 每次排序会使用上一次排序的结果
// 一般使用计数排序来完成每次的排序
// 例如对三位数排序 先排个位 再排十位 再排百位
// 经常被用于字符串的排序 后缀数组的核心就是基数排序


#include<bits/stdc++.h>
using namespace std;

int n,m,a[1001],sa[1001],v[1001],r[1001],c[10];

void countingsort(){
    memset(c,0,sizeof(c));
    for(int i=1;i<=n;i++)
        ++c[v[i]];
    for(int i=1;i<=9;i++)
        c[i]+=c[i-1];
    for(int i=n;i;i--)
        r[sa[i]]=c[v[sa[i]]]--;
    for(int i=1;i<=n;i++)
        sa[r[i]]=i;
}

void radixsort(){
    for(int i=1;i<=n;i++)
        sa[i]=i;
    int x=1;
    for(int i=1;i<=m;i++,x*=10){
        for(int j=1;j<=n;j++){
            v[j]=a[j]/x%10;
        }
        countingsort();
    }
}
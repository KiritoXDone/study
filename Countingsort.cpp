// 计数排序 适合值域范围较小 复杂度 n+k 稳定
// 统计每个数字出现了几次
// 统计完出现次数，求前缀和，可知道每个数字在拍完序的位置的范围
// 保证稳定性，倒着确定原本每个位置上的数字最后排在低级位


#include <bits/stdc++.h>
using namespace std;

int n,m,a[10001],c[10001],r[10001];

void countingsort(){
    memset(c,0,sizeof(c));
    for(int i=1;i<=n;i++)
        ++c[a[i]];
    for(int i=1;i<=m;i++)
        for(int j=1;j<=c[i];j++)
            printf("%d",i);
    printf("\n");

    for(int i=2;i<=m;i++)
        c[i]+=c[i-1];
    for(int i=n;i;i--)
        r[i]=c[a[i]]--;
    for(int i=1;i<=n;i++)
        printf("%d",r[i]);
    printf("\n");
}
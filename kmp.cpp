// 字符串匹配问题 查找s中p是否出现
// 暴力匹配 O(nm)
// 哈希优化 O(n+m)
// KMP 线性复杂度解决 O(n+m)
// KMP 中对于s中每个位置i，我们要找到最大的j满足s[i-j+1]...s[i]和p[1]...[j]相同
// f[i]对应j的位置，j对应p中的位置
// 如果j不等于m，并且s[i+1]==p[j+1]，j右移一位
// 否则，j向前回退，到满足s[i-k+1]...s[i]==p[1]...[j]且k最大的位
// 如果s[i+1]仍不等于p[j+1]，不停向前回退，直到相等或j=0

// 为了快速求出k
// 求k与s无关
// 最大的k满足k<j,使得p[1]..p[k]和p[j-k+1]...p[j]完全相同
// 可以用next维护每个j对应的k

#include <bits/stdc++.h>
using namespace std;

int n,m;
int nxt[100001],f[100001];
string s,p;

void kmp(){
    n=s.size()+1,m=p.size()+1;
    int j=0;
    nxt[1]=0;
    for(int i=2;i<=m;i++){
        while(j>0&&p[j+1]!=p[i])
            j=nxt[j];
        if(p[j+1]==p[i])
            j++;
        nxt[i]=j;
    }
    j=0;
    for(int i=1;i<=n;i++){
        while((j==m)||(j>0&&p[j+1]!=s[i]))
            j=nxt[j];
        if(p[j+1]==s[i])
            j++;
        f[i]=j;
    }
}//可将p和s结合起来 中间用字符隔开 两个for可结合 简化代码
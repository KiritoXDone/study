// 快排 分治思想 复杂度[nlogn,n^2] 不稳定 --x随机取 
// 排序区间为[l,r]时，长度小于1，直接退出，否则选一个数字x作为比较元素
// 将大于x的放右边，小于x的放左边，等于x的随意放
// 确定x的位置后，对两侧继续递归
#include <bits/stdc++.h>
using namespace std;

int a[100005];

void quicksort(int l,int r){
    if(l>=r)return;//长度小于1，直接退出
    swap(a[l],a[l+rand()%(r-l+1)]);//保证x随机取
    int x=a[l];
    int i=l,j=r;
    while(i<j){
        while(i<j&&a[j]>x)//不能写成a[j]>=x
            j--;
        if(i<j)
            a[i++]=a[j];
        while(i<j&&a[i]<x)//不能写成a[i]<=x
            i++;
        if(i<j)
            a[j--]=a[i];
    }
    a[i]=x;
    quicksort(l,i-1);//不能递归i
    quicksort(i+1,r);
}

//另一种写法

void Quicksort(int l, int r){
    if(l>=r)return;
    int b[100001],c[100001];
    int x=a[l+rand()&(r-l+1)];
    int l1=0,l2=0,y=0;
    for(int i=l;i<=r;i++){
        if(a[i]<x)
            b[++l1]=a[i];
        else 
            if(a[i]>x)
                c[++l2]=a[i];
            else ++y;
    }
    for(int i=1;i<=l1;i++)
        a[l+i-1]=b[i];
    for(int i=1;i<=y;i++)
        a[l+l1+i-1]=x;
    for(int i=1;i<=l2;i++)
        a[l+l1+y+i-1]=c[i];
    Quicksort(l,l+l1-1);
    Quicksort(l+l1+y,r);
}


int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    quicksort(1,n);
    return 0;
}
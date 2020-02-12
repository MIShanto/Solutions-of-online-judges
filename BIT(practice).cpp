#include<bits/stdc++.h>
using namespace std;

int BIT[1000000];

int Update(int i, int updatedWith,int Size)
{
    for(; i<=Size; i+=i&(-i))
    {
        BIT[i] += updatedWith;
    }
}
int query(int n)
{
    int sum =0;
    for(; n>0; n -= n&(-n))
    {
        sum += BIT[n];
    }
    return sum;
}
int main()
{
    int n,xx,yy;
    cin>>n>>xx>>yy;
    int a[n+5];
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        Update(i,a[i],n);
    }

    cout<<"sum of first "<<xx<<" number is = "<<query(xx)<<endl;
    cout<<"sum of range "<<xx<<" to "<<yy<<" is = "<<query(xx)- query(yy-1)<<endl;
    return 0;

}

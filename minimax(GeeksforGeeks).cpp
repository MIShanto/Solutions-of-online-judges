#include<bits/stdc++.h>
using namespace std;

int minimax(int depth, int nodeIndex, int a[], int h, int isMax)
{
    if(depth == h)
        return a[nodeIndex];
    if(isMax)
    {
        return max(minimax(depth+1, nodeIndex*2,a,h,false),minimax(depth+1, nodeIndex*2+1,a,h,false));
    }
    else
        return min(minimax(depth+1, nodeIndex*2,a,h,true),minimax(depth+1, nodeIndex*2+1,a,h,true));

}
int log2(int n)
{
    if(n==1)
        return 0;
    else
        return 1+log2(n/2);
}
int main()
{
    int n;
    cin>>n;
    int a[n+5];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    int h = log2(n);
    int res = minimax(0,0,a,h,true);
    cout<<"result = "<<res<<endl;
    return 0;

}

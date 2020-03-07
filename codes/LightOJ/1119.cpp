#include<bits/stdc++.h>
using namespace std;
int a[20][20],n;
int dp[1<<16];
int setMask(int mask,int pos)
{
    return mask = mask | (1<<pos);
}
int resetMask(int mask,int pos)
{
    return mask = mask & (~(1<<pos));
}
bool checkMask(int mask, int pos)
{
    return (bool)(mask&(1<<pos));
}
int bitmask(int mask)
{
    if(mask == (1<<n)-1)
        return 0;
    if(dp[mask]!=0)
        return dp[mask];
    int miN = 1<<28;
    for(int i=0; i<n; i++)
    {
        //cout<<"dp mask = "<<dp[mask]<<" min = "<<miN<<"i = "<<i<<endl;
        if(checkMask(mask,i)==0)
        {
            int price = a[i][i];
            for(int j=0; j<n; j++)
            {
                if(i!=j && checkMask(mask,j)!=0)
                {
                    price += a[i][j];
                }
            }
            int res = price + bitmask(setMask(mask,i));
            miN = min(res,miN);
        }

    }
    return dp[mask] = miN;
}
int main()
{
    freopen("teest.txt","r",stdin);
    freopen("test.txt","w",stdout);
    int t,k=0;
    cin>>t;
    while(t--)
    {
        memset(dp,0,sizeof(dp));
        cin>>n;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin>>a[i][j];
            }}
        int ans = bitmask(0);
        cout<<"Case "<<++k<<": "<< ans<<endl;
    }
    return 0;
}

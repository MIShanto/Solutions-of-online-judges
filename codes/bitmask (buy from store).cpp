#include<bits/stdc++.h>

using namespace std;

int table[100][100];
int dp[(1<<15)+2];
int n;

bool check(int mask,int pos){
    return (mask&(1<<pos));
}

int sett(int mask,int pos){
    return mask= mask| (1<<pos);
}


int bitmask(int mask)
{
    if(mask == (1<<n)-1)
    {
        return 0;
    }
    if(dp[mask]!=-1)
        return dp[mask];

int miN = 9999999;
    for(int i=0; i<n; i++)
    {

        if(check(mask,i)==0)
        {
            int price = table[i][i];
            for(int j=0; j<n; j++)
            {
                if(i!=j && check(mask, j)!=0 )
                    price+=table[i][j];
            }
            int tmp = price + bitmask(sett(mask,i));

            miN = min(tmp,miN);
        }
    }
    return dp[mask] = miN;
}


int main()
{

    cin>>n;
    memset(dp,-1,sizeof(dp));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>table[i][j];
    int ans = bitmask(0);
    cout<<ans<<endl;
    return 0;
}

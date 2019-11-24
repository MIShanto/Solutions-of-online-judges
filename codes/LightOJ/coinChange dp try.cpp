#include<bits/stdc++.h>
using namespace std;

int coin[]={5,8,11,15,18};
int make = 24;
int dp[6][100];

int call(int i, int amount)
{
        if(i>5)
        {
            if(amount == make)
                return 1;
            else
                return 0;
        }
            if(dp[i][amount]!=-1)
                return dp[i][amount];
            int res1=0,res2=0;
            if(amount+coin[i] <= make){
                    cout<<"res1 = "<<res1<<endl;
                res1 = call(i,amount+coin[i]);
            cout<<"res1 = "<<res1<<endl;
            }
            cout<<"res2 = "<<res2<<endl;
            res2 = call(i+1,amount);
            cout<<"res2 = "<<res2<<endl;

        return dp[i][amount] = res1 | res2;
}


int main()
{
    memset(dp,-1,sizeof(dp));
    cout<<call(0,0)<<endl;

    return 0;
}

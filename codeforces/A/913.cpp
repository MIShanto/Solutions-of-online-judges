#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll n,m,res=1;
	cin>>n>>m;
	for(int i=0;i<n;i++)
    {
         res *= 2;
         if(res> m){
        cout<<m<<endl;
         return 0;
    }
    }


        cout<<m%res<<endl;


	return 0;
}

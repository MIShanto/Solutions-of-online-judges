
#include<bits/stdc++.h>
using namespace std;
#define ll long long

main()
{
    int t,k1,k2,n,x;
    int maxK1=-1,maxK2=-1;
    cin>>t;
    while(t--)
    {
        maxK1=-1;
        maxK2=-1;
        cin>>n>>k1>>k2;
        while(k1--)
        {
            cin>>x;
            if(x>maxK1)
                maxK1=x;
        }
        while(k2--)
        {
            cin>>x;
            if(x>maxK2)
                maxK2=x;
        }
        if(maxK1>maxK2)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }

}


#include<bits/stdc++.h>
using namespace std;
#define ll long long

main()
{

   int t,n,cnt;
   cin>>t;
   while(t--)
   {
        cnt=0;
       cin>>n;
       int tmpN=n;
       int a[n+5];
      // int b[n+5];
       for(int i=0; i<n; i++)
       {
           cin>>a[i];
         //  b[i]=a[i];
       }

     //   sort(a,a+n);
        for(int i=0,j=i+1;i<n-1;i++,j++)
        {
             if(abs(a[i]-a[j])>=2)
            {
                cout<<"YES"<<endl;
                cnt=1;

              //  findIndex(b,n,a[i],a[n-1]);
                cout<<i+1<<" "<<j+1<<endl;
                break;
            }
        }
        if(cnt==0)
            cout<<"NO"<<endl;

   }
}

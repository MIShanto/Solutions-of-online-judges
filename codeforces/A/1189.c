#include<bits/stdc++.h>
using namespace std;

int main()
{
			string s,s2;
   int n,n0=0,n1=0;
				cin>>n>>s;
    for(int i=0; i<n; i++)
				{ //cout<<s[i]<<endl;
				if(s[i]=='0') n0++;
				else n1++;
}
			//	cout<<n0<<n1<<endl;
				if(n0!=n1)
				 cout<<1<<"\n"<<s<<endl;
				else {cout<<2<<endl;
								cout<<s[0]<<" ";
								for(int i=1; i<n; i++)
				 cout<<s[i];
								}
}

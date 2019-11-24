
#include<bits/stdc++.h>
using namespace std;
int main()
{
    char a[100],b[100];
    long long int x,y,s=0,la,lb,i=-1;
    cin>>a;
 
    la=strlen(a);
 
        while(la!=0)
        {
            b[++i]='9';
            la--;
        }
        b[i]='\0';
    if(b[0]!='\0')
    lb=strlen(b);
    else{
        lb=0;
        b[0]='0';
    }
 
        stringstream geeka(a);
        stringstream geekb(b);
    geeka>>x;
    geekb>>y;
    la = x-y;
  //  cout<<la<<" "<<lb<<endl;
    while(la!=0){
        s+=la%10;
        la/=10;
    }
    if(b[0]!='\0')
        s+=lb*9;
    else
        s+=0;
    cout<<s<<endl;
 
    return 0;
}
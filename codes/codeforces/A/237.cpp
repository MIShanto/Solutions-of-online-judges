#include <iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[100][100];
int main()
{
    int i=0,j=0,n,x,y,maX=1;
    cin>>n;
    int m=n;
    while(m--){
        cin>>x>>y;
        a[x][y]+=1;
 
    }
    for(i=0; i<100; i++){
        for(j=0; j<100; j++){
            if(maX<a[i][j])
            maX=a[i][j];
        }
    }
    cout<<maX<<endl;
    return 0;
}
//#include<bits/stdc++.h>
#include<stdio.h>
#include<iostream>
#define mx 100001
using namespace std;

int a[mx];
int tree[mx*3];

void makeTree(int node, int s, int e)
{
    if(s==e)
    {

        tree[node] = a[e];
        return;
    }
    int left = node*2;
    int right =node*2+1;
    int mid = (s+e)/2;

    makeTree(left,s,mid);
    makeTree(right,mid+1,e);

    tree[node] = min(tree[left], tree[right]);
}

int query(int node, int s, int e, int x,int y)
{
    if(x>e || y<s)
        return 9999999;
    if(x<=s && y>=e)
    {
        return tree[node];
    }

    int left = node*2;
    int right =node*2+1;
    int mid = (s+e)/2;
    int p1,p2;

    p1=p2=9999999;
     p1 = query(left,s,mid,x,y);
     p2= query(right,mid+1,e,x,y);
    return min(p1,p2);
}

int main()
{
    int n,t,q,kase=1;
    //cin>>t;
    scanf("%d",&t);
    while(t--)
    {
        //cin>>n>>q;
        scanf("%d",&n);
        scanf("%d",&q);

        for(int i=1; i<=n; i++)
        {
            //cin>>a[i];
            scanf("%d",&a[i]);
        }
        makeTree(1,1,n);

        //cout<<"Case: "<<kase++<<endl;
        printf("Case %d:\n",kase++);

        for(int i=0; i<q; i++)
        {
            int x,y;
            //cin>>x>>y;
            scanf("%d",&x);
            scanf("%d",&y);
            //cout<<query(1,1,n,x,y)<<endl;
            printf("%d\n",query(1,1,n,x,y));
        }
    }
    return 0;
}

//solved using knapsack....
#include<bits/stdc++.h>
using namespace std;

struct product
{
    int p,w;
};

bool cmp(struct product a, struct product b)
{
    if(a.w == b.w)
        return (a.p > b.p);
    return a.w<b.w;
}


void makeTable(int n, int maxG,struct product prod[], int storeG[], int g)
{
    //make table for knapsack..................................
    //start making
    int table[n+5][maxG+5];

    memset(table,0,sizeof(table));

    for(int i=1; i<=maxG; i++)
    {
        if(i>=prod[0].w)
            table[0][i] = prod[0].p;
    }

    for(int i=1; i<n; i++)
    {
        for(int j=0; j<=maxG; j++)
        {
            if(j<prod[i].w)
                table[i][j] = table[i-1][j];
            else
            {
                table[i][j] =max( (prod[i].p + table[i-1][j - prod[i].w]), table[i-1][j]);
            }
        }
    }   // end of making table.
    /* from line 40 to 44 is for uva 10130 solution*/
    int Res = table[n-1][storeG[0]];
    for(int i=1; i<g; i++)
        Res+= table[n-1][storeG[i]];
    cout<<Res<<endl;

    //search knapsack..............................................
   /* int res = table[n-1][maxG],j=maxG;

    for(int i=n-1; i>=0 && res>0; i--)
    {
        if(i>0)
        {

            if(res == table[i-1][j])
                continue;
            else
            {
                cout<<prod[i].w<<" ";

                res -= prod[i].p;
                j -= prod[i].w;
            }
        }
        else
        {
            cout<<prod[i].w<<" ";

                res -= prod[i].p;
                j -= prod[i].w;
        }
    }*/

    //print the table...............

   /*for(int i=0; i<n; i++)
    {
        for(int j=0; j<=maxG; j++)
        {
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }*/
}

int main()
{

    int t,p,w,g,n;

    cin>>t;

    while(t--)
    {
        cin>>n;

        struct product prod[n+5];

        for(int i=0; i<n; i++)
        {
            cin>>prod[i].p>>prod[i].w;

        }

        sort(prod,prod+n,cmp);

        cin>>g;

        int storeG[g+5],maxG=-1;

        for(int i=0; i<g; i++)
        {
            cin>>storeG[i];
            if(storeG[i]>maxG)
                maxG = storeG[i];
        }

        makeTable(n,maxG,prod,storeG,g);

    }
    return 0;
}

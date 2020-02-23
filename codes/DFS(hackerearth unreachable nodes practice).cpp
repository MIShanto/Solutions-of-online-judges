#include<bits/stdc++.h>

using namespace std;

vector<int> v[999999];
stack<int>  s;
int visit[9999999];

void DFS(int root,int n)
{
    visit[root]=1;
    int countVisitedNodes = 1;
    s.push(root);
    while(!s.empty())
    {
        int top = s.top();
        s.pop();
        for(int i= 0; i<v[top].size(); i++)
        {
            if(visit[v[top][i]]==0)
            {
                s.push(v[top][i]);
                visit[v[top][i]]=1;
                countVisitedNodes++;
            }

        }
    }
    cout<<n-countVisitedNodes<<endl;

}

int main()
{
        int n,m,x,y,root;
        cin>>n>>m;
        for(int i=0; i<m; i++)
        {
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        cin>>root;
        DFS(root,n);


    return 0;
}

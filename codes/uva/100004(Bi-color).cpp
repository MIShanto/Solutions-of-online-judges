#include <bits/stdc++.h>
using namespace std;
vector<int> v[10000];

int lvl[10000];
bool visit[10000];

void bfs(int x)
{

    memset(lvl,0,sizeof(lvl));
    memset(visit,0,sizeof(visit));

    int cnt=0;
    queue<int> q;

    q.push(x);
    visit[x] =1;
    lvl[x] = 1;

    while(!q.empty())
    {
        int f = q.front();
        q.pop();
        for(int i=0; i<v[f].size(); i++)
        {
            int check = v[f][i];

            if(visit[check] == 0)
            {
                q.push(check);
                visit[check] = 1;
                lvl[check] = lvl[f]+1;

            }
            else
            {
                if(lvl[f]==lvl[check])
                {
                    cout<<"NOT BICOLORABLE."<<endl;
                        cnt = 5;
                        return;
                }
            }
        }
    }
    if(cnt==0)
        cout<<"BICOLORABLE."<<endl;

    return;
}

int main()
{
    int n,e,u,vv;
    while(1)
    {
         for(int i=0; i<10000; i++)
        {
            v[i].clear();
        }

        cin>>n;
        if(n==0)
            break;
        cin>>e;

        while(e--)
        {
            cin>>u>>vv;
            v[u].push_back(vv);
            v[vv].push_back(u);
        }
        bfs(0);
    }


    return 0;
}


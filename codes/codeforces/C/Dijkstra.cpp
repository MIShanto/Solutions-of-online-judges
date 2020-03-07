#include <bits/stdc++.h>

using namespace std;
#define infinity 1<<30  //2^30

const int MAXN = 1e5 + 3;
int path[MAXN];


int dijstkra(int n, vector<pair<int,int> > v[], int source){
    path[1] = 1;
    int distance[n+1];
    for(int i=1;i<=n;i++) {
        distance[i] = infinity;
    }
    //cout<<distance[n]<<endl;

    priority_queue< pair<int,int> , vector<pair<int,int> >,  greater<pair<int,int> > >  q;
    q.push(make_pair(0, source));
    distance[source] = 0;

    while(!q.empty()){
        int top = q.top().second;
        q.pop();
        if(top == n)
            return 1;

        //cout<<"top = "<<top<<endl;

        for(int i=0;i<(int)v[top].size();i++){

            int  adj = v[top][i].second;

        //cout<<"adj = "<<adj<<"cost of adj = "<<v[top][i].first<<endl;

            //Relaxation
            if(distance[top] + v[top][i].first < distance[adj]){
                distance[adj] = distance[top] + v[top][i].first;
                //cout<<"dis[adj] = "<<distance[adj]<<endl;
                path[adj] = top;
                q.push(make_pair(distance[adj], adj));
            }
        }
    }
        return -1;
    //cout<<distance[n]<<endl;
   /* for(int i=0;i<=n;i++){
        cout<<source<<" --> "<<i<<" = "<<distance[i]<<endl;
        cout<<"path"<<" --> "<<i<<" = "<<path[i]<<endl;
    }*/
}
int main(){


    stack<int> ans;

    int numNodes, numEdges;
    cin>>numNodes>>numEdges;
    vector<pair<int,int> > v[numNodes+5];
    for(int i=0;i<numEdges;i++){
        int u1, u2, w;
        cin>>u1>>u2>>w;
        v[u1].push_back(make_pair(w,u2));
        v[u2].push_back(make_pair(w,u1));
    }
    int source;
    //cin>>source;
    int res = dijstkra(numNodes, v, 1);
    if(res ==-1)
    {
        cout<<-1<<endl;
    }
    else{
//    cout<<distance[numNodes]<<endl;
    for(int i =numNodes; i!=1;)
    {
        ans.push(path[i]);
        i = path[i];
    }
    while(!ans.empty())
    {
        cout<<ans.top()<<" ";
        ans.pop();
    }
    cout<<numNodes<<endl;
    }

    return 0;
}

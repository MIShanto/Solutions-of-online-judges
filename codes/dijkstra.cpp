#include <bits/stdc++.h>

using namespace std;
#define infinity 1<<30  //2^30

void dijstkra(int n, vector<pair<int,int> > v[], int source){

    int distance[n+1];
    for(int i=1;i<=n;i++) {
        distance[i] = infinity;
    }

    priority_queue< pair<int,int> , vector<pair<int,int> >,  greater<pair<int,int> > >  q;
    q.push(make_pair(0, source));
    distance[source] = 0;

    while(!q.empty()){
        int top = q.top().second;
        q.pop();

        cout<<"top = "<<top<<endl;

        for(int i=0;i<(int)v[top].size();i++){

            int  adj = v[top][i].second;
        cout<<"adj = "<<adj<<endl;

            //Relaxation
            if(distance[top] + v[top][i].first < distance[adj]){
                distance[adj] = distance[top] + v[top][i].first;
                q.push(make_pair(distance[adj], adj));
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<source<<" --> "<<i<<" = "<<distance[i]<<endl;
    }
}
int main(){

    vector<pair<int,int> > v[10000]; //this code can handle maximum 10000 nodes
    int numNodes, numEdges;
    cin>>numNodes>>numEdges;
    for(int i=0;i<numEdges;i++){
        int u1, u2, w;
        cin>>u1>>u2>>w;
        v[u1].push_back(make_pair(w,u2));
        v[u2].push_back(make_pair(w,u1));
    }
    int source;
    cin>>source;
    dijstkra(numNodes, v, source);

    return 0;
}

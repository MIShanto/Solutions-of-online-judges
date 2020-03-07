#include <bits/stdc++.h>

using namespace std;
#define infinity 1<<30  //2^30

int dijstkra(int n, vector<pair<int,int> > v[], int source){

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

        //cout<<"top = "<<top<<endl;

        for(int i=0;i<(int)v[top].size();i++){

            int  adj = v[top][i].second;
        //cout<<"adj = "<<adj<<endl;

            //Relaxation
            if(distance[top] + v[top][i].first < distance[adj]){
                distance[adj] = distance[top] + v[top][i].first;
                q.push(make_pair(distance[adj], adj));
            }
        }
    }
    return distance[n-1];
    //for(int i=1;i<=n;i++){
        //cout<<source<<" --> "<<i<<" = "<<distance[i]<<endl;
    //}
}
int main(){

    vector<pair<int,int> > v[10000];
    int numNodes, numExistingRoads,roadToPrepare,d,t,k=0;
    cin>>t;
    while(t--)
    {
        for(int i=0; i<10000; i++)
            v[i].push_back(make_pair(0,0));

         cin>>numNodes>>numExistingRoads>>roadToPrepare>>d;

        for(int i=0;i<numExistingRoads;i++){
            int u1, u2, w;
            cin>>u1>>u2>>w;
            v[u1].push_back(make_pair(w,u2));
            //v[u2].push_back(make_pair(w,u1));
    } for(int i=0;i<roadToPrepare;i++){
            int u1, u2, w;
            cin>>u1>>u2>>w;
            v[u1].push_back(make_pair(w,u2));
            //v[u2].push_back(make_pair(w,u1));
    }
    if(d==0){
            cout<<"Case "<<++k<<": Impossible"<<endl;
    }
    else{
        int ans = dijstkra(numNodes, v, 0);
        cout<<"Case "<<++k<<": "<<ans<<endl;
    }
    }


    return 0;
}

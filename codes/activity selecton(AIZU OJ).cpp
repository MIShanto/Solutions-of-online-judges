#include<bits/stdc++.h>

using namespace std;
#define ll long long int
#define PI 3.14159265358979323846


struct Activity
{
    int startTime;
    int endTime;
};

bool compare(Activity one, Activity two)
{
    return (one.endTime<two.endTime);
}

int ActivitySelection(Activity activities[],int n)
{
    sort(activities,activities+n,compare);
    int i =0,cnt=1;
    for(int j=1; j<n; j++)
    {
        if(activities[j].startTime>=activities[i].endTime){
            i = j;
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    int n;

    cin>>n;
    Activity activities[n+5];
    for(int i=0; i<n; i++)
    {
        cin>>activities[i].startTime>>activities[i].endTime;
    }
    int res = ActivitySelection(activities,n);
    cout<<res<<endl;
    return 0;
}

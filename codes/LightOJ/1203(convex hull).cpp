#include<bits/stdc++.h>

using namespace std;
#define ll long long int
#define PI 3.14159265358979323846


struct Point
{
    ll x;
    ll y;
};
Point a[100005] , res[100005] ;

stack < Point >  S ;

Point nextToTop()
{
    Point P = S.top();
    S.pop();
    Point res = S.top();
    S.push(P);
    return res;
}

ll dist(Point P,Point Q)
{
    return (P.x-Q.x)*(P.x-Q.x)+(P.y-Q.y)*(P.y-Q.y) ;
}

double calc(Point A,Point B,Point C)
{
    double a = sqrt((double)dist(A,B));
    double b = sqrt((double)dist(B,C));
    double c = sqrt((double)dist(C,A));

    //return acos((b*b-c*c-a*a)/(-2*a*c));
    return acos((a*a+c*c-b*b)/(2*a*c));
}

int orientation(Point P,Point Q,Point R)
{
    ll result = (Q.y-P.y)*(R.x-Q.x) - (Q.x-P.x)*(R.y-Q.y) ;
    if(result<0) return 2;
    if(result>0) return 1;
    return result ;
}

bool cmp(Point X , Point Y)
{
    ll result = orientation(a[0],X,Y);
    if(result==0)
    {
        ll dist1 = dist(a[0],X);
        ll dist2 = dist(a[0],Y);
        return dist1 < dist2 ;
    }
    else if(result==2) return true ;
    else return false ;
}

double convexHull(ll n)
{

   ll ymin = a[0].y, miN = 0;
   for (ll i = 1; i < n; i++)
   {
     ll y = a[i].y;


     if ((y < ymin) || (ymin == y && a[i].x < a[miN].x))
     {
         ymin = a[i].y;
        miN = i;
     }
   }

        swap(a[0],a[miN]);
        sort(&a[1],&a[n],cmp); // sort from 1 to n using cmp func

        S.push(a[0]);


       for(ll i=1;i<n;i++)
        {
            while(S.size()>1 && orientation(nextToTop(),S.top(),a[i])!=2)
                S.pop();

            S.push(a[i]);

          // cout<<S.top().x<<" "<<S.top().y<<endl;
        }

        vector<Point> v;
       // v.push_back()
        while(!S.empty())
        {
            v.push_back(S.top());
            //cout<<"in stack "<<S.top().x<<" "<<S.top().y<<endl;
           // cout<<v[0].x<<" "<<v[0].y<<endl;
            S.pop();
        }

        ll cnt = v.size();
        if(cnt<3) return 0.0 ;

        v.insert(v.begin(),v[cnt-1]);
        v.push_back(v[1]);
        cnt = v.size();


        double result = 9999;
        for(ll i=cnt-2; i>0; i--)
        {
            ll j = i+1;
            ll k = i-1;
            result = min(result,(calc(v[i],v[j],v[k])*180)/PI);
        }
        return result;



}

int main()
{
        ll T ;
        cin>>T;
        for(ll kase=1;kase<=T;kase++)
        {
            ll N ;
            cin>>N;
            for(ll i=0;i<N;i++)
                cin>>a[i].x>>a[i].y;
            printf("Case %lld: %.7lf\n",kase,convexHull(N));

        }
    return 0;
}

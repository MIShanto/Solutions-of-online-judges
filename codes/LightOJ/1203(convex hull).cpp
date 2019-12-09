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

long long dist(Point P,Point Q)
{
    return (P.x-Q.x)*(P.x-Q.x)+(P.y-Q.y)*(P.y-Q.y) ;
}

double calc(Point A,Point B,Point C)
{
    double a = sqrt((double)dist(A,B));
    double b = sqrt((double)dist(B,C));
    double c = sqrt((double)dist(C,A));

    return acos((b*b-c*c-a*a)/(-2*a*c));
}

int orientation(Point P,Point Q,Point R)
{
    long long ret = (Q.y-P.y)*(R.x-Q.x) - (Q.x-P.x)*(R.y-Q.y) ;
    if(ret<0) return 2;
    if(ret>0) return 1;
    return ret ;
}

bool cmp(Point X , Point Y)
{
    ll ret = orientation(a[0],X,Y);
    if(ret==0)
    {
        long long dist1 = dist(a[0],X);
        long long dist2 = dist(a[0],Y);
        return dist1 < dist2 ;
    }
    else if(ret==2) return true ;
    else return false ;
}

double convexHull(ll n)
{
    // Find the bottommost point
   ll ymin = a[0].y, miN = 0;
   for (ll i = 1; i < n; i++)
   {
     ll y = a[i].y;

     // Pick the bottom-most or chose the left
     // most point in case of tie
     if ((y < ymin) || (ymin == y && a[i].x < a[miN].x))
     {
         ymin = a[i].y;
        miN = i;
     }
   }

        swap(a[0],a[miN]);
        sort(&a[1],&a[n],cmp);
        S.push(a[0]);

       for(ll i=1;i<n;i++)
        {
            while(S.size()>1 && orientation(nextToTop(),S.top(),a[i])!=2)
                S.pop();

            S.push(a[i]);
        }

        ll cnt = 0 ;

            while(!S.empty())
            {
                res[cnt++]=S.top() ;
                S.pop();
            }
           vector < Point > V ;
            for(ll i=cnt-1;i>=0;i--)
                V.push_back(res[i]) ;

            cnt = V.size() ;
            if(cnt<3) return 0.0 ;
            double ret = 1258.0 ;

            for(ll i=0;i<cnt;i++)
            {
                ll j = (i+1)%cnt;
                ll k = (i-1+cnt)%cnt;
                ret = min(ret,(calc(V[i],V[j],V[k])*180)/PI);
            }
            return ret ; //BUJHINAI*/

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

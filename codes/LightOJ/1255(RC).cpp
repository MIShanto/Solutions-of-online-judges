// SOLVED USING Rabin karp.. not acceptable

#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll kase=0,cnt,main_sum,check_sum;

ll makeHash(string pattern)
{
    ll patSize = pattern.size(), main_sum=0;
    for(ll i=0; i<patSize; i++)
    {
        main_sum+= (pattern[i]-96)*(pow(3,i));

    }
    return main_sum;
}

void searchPattern(string text,string pattern)
{
    main_sum=makeHash(pattern);
    //cout<<"main sum = "<<main_sum<<endl;
    check_sum=0;
    ll j=-1,k=0,p=0;
    //m=pattern.size();
    for(ll i=0; i<text.size(); i++)
    {
       check_sum+= (text[i]-96)*(pow(3,p));
       k++;
       p++;
       //cout<<"check = "<<check_sum<<endl;
       if(k == pattern.size())
       {
           if(main_sum == check_sum)
           {
            cnt++;
            check_sum=0;
            p=0;
            k=0;
            i--;
           }
           else
           {
               check_sum = (check_sum - (text[++j]-96))/3;
               k--;
               p--;

           }
       }
    }
    cout<<"Case "<<++kase<<": "<<cnt<<endl;
}
 main()
{
    ll t;
    string text,pattern;
    cin>>t;
    while(t--)
    {
        cnt =0;
        cin>>text;
        cin>>pattern;

    searchPattern(text,pattern);
    }
}

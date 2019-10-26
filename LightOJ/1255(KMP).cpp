// SOLVED USING KMP..  acceptable
#include<bits/stdc++.h>
using namespace std;


int kase=0,cnt,lps[1000000];
int KMP(string pattern, int lps[])
{
    for(int i=1,j=0; i<pattern.size();)
    {
        if(pattern[i]==pattern[j])
        {
            lps[i]=j+1;
            i++;
            j++;
        }
        else
        {
            if(j==0)
            {
                lps[i]=0;
                i++;
            }
            else
            {
                j = lps[lps[j-1]];
            }
        }
    }

}

void searchPattern(string text,string pattern, int lps[])
{
    int i,j=0;
    lps[0]=0;
    KMP(pattern,lps);
    for(i=0; i<text.size();)
    {


        if(pattern[j] == text[i])
        {

            j = j+1;
            i = i+1;

        }
        if(j==pattern.size())
        {
            cnt++;

            j = lps[j-1];
        }
        else if(pattern[j] != text[i])
        {
            if(j!=0)
            {
                j = lps[j-1];
            }
            else
                i++;
        }
    }
    cout<<"Case "<<++kase<<": "<<cnt<<endl;
}
 main()
{
    int t;
    string text,pattern;

    cin>>t;
    while(t--)
    {
        cnt =0;
        cin>>text;
        cin>>pattern;

    searchPattern(text,pattern,lps);
    }
}

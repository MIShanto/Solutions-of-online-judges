// SOLVED USING KMP..  acceptable
#include<bits/stdc++.h>
using namespace std;

void printAns(string pattern,int maX)
{
    for(int i=maX-1; i>=0; i--)
        cout<<pattern[i];
    cout<<endl;
    return;
}


void KMP(string pattern, int lps[])
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
                j = lps[j-1];
            }
        }
    }
    return;
}

void searchPattern(string text,string pattern)
{
    int i,j=0,maX=0;
    int lps[pattern.size()+5];
    memset(lps,0,pattern.size()+5);
    lps[0]=0;
    KMP(pattern,lps);
    for(i=0; i<text.size();)
    {


        if(pattern[j] == text[i])
        {

            j = j+1;
            i = i+1;
            if(j>maX)
                maX = j;

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
    printAns(pattern,maX);
    return;
}

int  main()
{
    int t;
    string text,pattern;

    cin>>t;
    while(t--)
    {

        cin>>text;
        pattern = text;
        reverse(text.begin(),text.end());

    searchPattern(text,pattern);
    }
    return 0;
}

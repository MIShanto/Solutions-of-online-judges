// SOLVED USING DFA.. not acceptable

#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000

int table[MAX][100],kase=0,cnt;

void makeDFA(string pattern)
{


    int lps = 0;
    for(int i = 1; i<=pattern.size(); i++)
    {
        for(int j=0; j<30; j++)
        {
            table[i][j] = table[lps][j];
        }
        table[i][pattern[i]-97] = i+1;
        if(i<pattern.size())
            lps = table[lps][pattern[i]-97];
    }

   /* for(int i=0; i<=pattern.size(); i++){
    for(int j=0; j<30; j++){
        cout<<table[i][j]<<" ";}cout<<endl;}*/

}

void searchPattern(string text,string pattern)
{
    for(int i=0;i<MAX; i++)
        for(int j=0; j<100; j++)
            table[i][j]=0;

    int j=0;
    table[0][pattern[0]-97] = 1;
   //cout<< pattern[0]-97<<endl;
    makeDFA(pattern);

    for(int i=0; i<text.size(); i++)
    {
        j = table[j][text[i]-97];

        if(j==pattern.size())
            cnt++;
    }
    cout<<"Case "<<++kase<<": "<<cnt<<endl;
}
int main()
{
    int t;
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

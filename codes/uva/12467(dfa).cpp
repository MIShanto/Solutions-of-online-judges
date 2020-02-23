// SOLVED USING DFA..  acceptable
#include<bits/stdc++.h>
using namespace std;

void printAns(string pattern,int maX)
{
    for(int i=maX-1; i>=0; i--)
        cout<<pattern[i];
    cout<<endl;
    return;
}

int getNextState(string pattern, int patSize, int currentState, int x)
{
    if(currentState<patSize && x == pattern[currentState])
    {
        return currentState+1;
    }
    int nextState,i;
    for(nextState = currentState; nextState>0; nextState--)
    {
        if(pattern[nextState-1] == x)
        {
            for(i=0; i<nextState-1; i++)
            {
                if(pattern[i] != pattern[currentState-nextState+1+i])
                    break;
            }
            if(i == nextState-1)
                return nextState;
        }
    }
    return 0;
}

void DFA(string pattern,int patSize,int stateTable[][30])
{
    int currentState, x;
    for(currentState = 0; currentState<=patSize; currentState++)
    {
        for(x = 0; x<30; x++)
        {
            stateTable[currentState][x] = getNextState(pattern,patSize,currentState,x);
        }
    }
    for(int i=0; i<patSize; i++){
        for(int j=0; j<30; j++)
            cout<<stateTable[i][j]<<" ";
        cout<<endl;
    }
    return;
}

void searchPattern(string text,string pattern)
{
    int maX = 0;
    int stateTable[pattern.size()+5][30];
    memset(stateTable,0,sizeof(stateTable));
    DFA(pattern,pattern.size(),stateTable);
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

#include<bits/stdc++.h>

using namespace std;

void printSortedArray(int a[],int n)
{
    for(int i =0; i<n ; i++)
        cout<<a[i]<<endl;
}

void insertionSort(int a[],int n)
{
    for(int i =0; i<n; i++)
    {
        for(int j = 0; j<n-1; j++)
        {
            if(a[j]>a[j+1])
            {
                swap(a[j],a[j+1]);
            }
        }
    }
    printSortedArray(a,n);
}



int main()
{
    int n;
    cin>>n;
    int a[n+5];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    insertionSort(a,n);

    return 0;
}

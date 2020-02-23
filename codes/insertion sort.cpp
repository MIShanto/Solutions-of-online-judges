#include<bits/stdc++.h>

using namespace std;

void printSortedArray(int a[],int n)
{
    for(int i =0; i<n ; i++)
        cout<<a[i]<<endl;
}

void insertionSort(int a[],int n)
{
    for(int i =1; i<n; i++)
    {
        int j = i-1;
        int tmp = a[i];
        while(j>=0)
        {
            if(a[j]>tmp)
            {
               a[j+1] = a[j];
               j--;
            }
            else
                 break;
        }
        a[j+1] = tmp;
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

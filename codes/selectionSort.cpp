#include<bits/stdc++.h>

using namespace std;

void printSortedArray(int a[],int n)
{
    for(int i =0; i<n ; i++)
        cout<<a[i]<<endl;
}

void selectionSort(int a[],int n)
{

    for(int i =0; i<n; i++)
    {
        int miN = a[i];
        int minIndex = i;
        for(int j =i+1; j<n; j++)
        {
            if(a[j]<miN)
            {
                miN = a[j];
                minIndex = j;
            }

        }
        swap(a[i],a[minIndex]);

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
    selectionSort(a,n);

    return 0;
}

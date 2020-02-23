#include<bits/stdc++.h>
using namespace std;

int a[1000000],b[1000000];

void maxHeapify(int root,int sizeofArray)
{
    int largest = root;
    int left = root*2;
    int right = root*2 + 1;

    if(left<= sizeofArray && a[left]>a[largest])
        largest = left;
    if(right<= sizeofArray && a[right]>a[largest])
        largest = right;
    if(largest != root)
    {
        swap(a[root],a[largest]);
        maxHeapify(largest,sizeofArray);
    }
}
void minHeapify(int root,int sizeofArray)
{
    int smallest = root;
    int left = root*2;
    int right = root*2 + 1;

    if(left<= sizeofArray && b[left] < b[smallest])
        smallest = left;
    if(right<= sizeofArray && b[right] < b[smallest])
        smallest = right;
    if(smallest != root)
    {
        swap(b[root],b[smallest]);
        minHeapify(smallest,sizeofArray);
    }
}

void buildHeap(int i,int n)
{
     for(; i>0; i--)
     {
        maxHeapify(i,n);
        minHeapify(i,n);
     }
}

void printHeap(int n)
{
    cout<<"max heap: "<<endl;
    for(int i=1; i<=n; i++)
    {
        cout<<a[i]<<endl;
    }
    cout<<"min heap: "<<endl;
    for(int i=1; i<=n; i++)
    {
        cout<<b[i]<<endl;
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        b[i] = a[i];
    }
    buildHeap(n/2,n);
    printHeap(n);
    return 0;

}

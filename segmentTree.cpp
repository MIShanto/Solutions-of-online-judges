#include<bits/stdc++.h>
#define mx 100001
using namespace std;
int arr[mx];
int tree[mx * 3];
void init(int node, int b, int e)
{
    if (b == e) {
        tree[node] = arr[b];
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    cout<<"before init left call   left: "<<Left<<"  b: "<<b<<"   mid: "<<mid<<endl;
    init(Left, b, mid);
    cout<<"after init left call   left: "<<Left<<"  b: "<<b<<"   mid: "<<mid<<endl;
    cout<<"before init right call   right: "<<Right<<"  mid: "<<mid<<"   e: "<<e<<endl;
    init(Right, mid + 1, e);
    cout<<"after init right call   right: "<<Right<<"  mid: "<<mid<<"   e: "<<e<<endl;
    tree[node] = tree[Left] + tree[Right];
}
int main()
{
    //READ("in");
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
        cin>> arr[i];
    init(1, 1, n);

    return 0;
}


#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll X[2000005],Y[2000005];

void calcsubarray(ll a[], ll x[], int n, int c)
{
	for (int i=0; i<(1<<n); i++)
	{
		ll s = 0;
		for (int j=0; j<n; j++)
			if (i & (1<<j))
				s += a[j+c];
		x[i] = s;
	}
}

ll solveSubsetSum(ll a[], int n, ll S)
{
	calcsubarray(a, X, n/2, 0);
	calcsubarray(a, Y, n-n/2, n/2);

	int size_X = 1<<(n/2);
	int size_Y = 1<<(n-n/2);

	sort(Y, Y+size_Y);

	ll max = 0;


	for (int i=0; i<size_X; i++)
	{
		if (X[i] <= S)
		{

			int p = lower_bound(Y, Y+size_Y, S-X[i]) - Y;

            cout<<p<<endl;


			if (p == size_Y || Y[p] != (S-X[i]))
                p--;

                cout<<p<<endl;

			if ((Y[p]+X[i]) > max)
				max = Y[p]+X[i];
            cout<<(Y[p]+X[i])<<" "<<max<<endl;
		}
	}
	return max;
}

int main()
{
	ll a[] = {3, 34, 4, 12, 5, 2};
	int n=sizeof(a)/sizeof(a[0]);
	ll S = 10;
	printf("Largest value smaller than or equal to given "
		"sum is %lld\n", solveSubsetSum(a,n,S));
	return 0;
}

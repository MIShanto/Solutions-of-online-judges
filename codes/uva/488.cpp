#include <bits/stdc++.h>
using namespace std;

int main()
{
	int kase, f, a;

	cin>>kase;
	while (kase--)
        {
		scanf("%d\n%d", &a, &f);

		for (int i = 0; i < f; i++) {
			for (int j = 1; j <= a; j++) {
				for (int k = 0; k < j; k++) {
					cout<<j;
				}
				cout<<endl;
			}
			for (int j = a - 1; j >= 1; j--) {
				for (int k = 0; k < j; k++) {
					cout<<j;
				}
				cout<<endl;
			}
			if (i != f - 1)
				cout<<endl;
		}
		if (kase)
			cout<<endl;
	}

	return 0;
}

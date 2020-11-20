#include <bits/stdc++.h>
using namespace std;

#define MAXN 200001
#define all(x) x.begin(), x.end()

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;

ll n, j, s, maxx=INT_MIN;

int main() {
    cin >> n;
    
    for(int i=0; i<n; i++) {
		cin >> j;
		maxx=max(maxx,j);
		s+=j;
	}
    cout << max(maxx*2,s) << endl;
    return 0;
}

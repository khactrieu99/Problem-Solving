#include <bits/stdc++.h>
using namespace std;

#define MAXN 5001
#define all(x) x.begin(), x.end()

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;

ll x, t;
int n, y, l, r;
vector<pii> a;
vi ans;

int main() {
	cin >> n >> x;
	a.resize(n);
	for(int i=0; i<n; i++) {
		cin >> y;
		a[i]={y,i+1};
	}
	sort(all(a));
	for(int i=0; i<n; i++) {
		t=x-a[i].first;
		l=i+1; r=n-1;
		while(l<r) {
			if(a[l].first+a[r].first==t) {
				ans.push_back(a[i].second);
				ans.push_back(a[l].second);
				ans.push_back(a[r].second);
				break;
			}
			else if(a[l].first+a[r].first>t) r--;
			else l++;
		}
		if(!ans.empty()) {
			cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
			break;
		}
	}

	if(ans.empty()) cout << "IMPOSSIBLE" << endl;

	return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define MAXN 200001

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<int,int> vii;
typedef long long ll;

set<ll> s;
int n, x, y, cnt=0, prefix=0;

int main() {
	cin >> n >> x;
	s.insert(0);

	for(int i=0; i<n; i++){
		cin >> y;
		prefix+=y;
		s.insert(prefix);
		if(s.find(prefix-x)!=s.end()) cnt++;
	}
	
	cout << cnt << endl;

	return 0;
}

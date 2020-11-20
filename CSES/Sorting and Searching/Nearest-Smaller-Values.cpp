#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

int n, x;
stack<pii> s;

int main() {
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> x;
		while(!s.empty()&&s.top().first>=x) s.pop();
		if(s.empty()) cout << 0 << " ";
		else cout << s.top().second << " ";
		s.push({x,i+1});
	}
	return 0;
}

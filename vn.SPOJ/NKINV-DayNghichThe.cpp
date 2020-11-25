#include <bits/stdc++.h>
using namespace std;

#define MAXN 60001

typedef vector<int> vi;

int n, x, res=0;
vi f(MAXN,0);

void update(int i) {
	while(i>0) {
		f[i]++;
		i=i-(i&-i);
	}
}

int get(int i) {
	int s=0;
	while(i<MAXN) {
		s += f[i];
		i=i+(i&-i);
	}

	return s;
}

int main() {
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> x;
		update(x);
		res += get(x+1);
	}
	cout << res << endl;
	return 0;
}

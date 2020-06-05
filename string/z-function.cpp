#include <bits/stdc++.h>
using namespace std;

#define FOR(_,__,___) for(int _=__; _<___; _++)

string s, t;

void z_function() {
	vector<int> Z;
	Z.push_back(0);

	string combine = t + "$" + s;
	int n=combine.length();
	
	int L=0, R=0;
	FOR(i,1,n) {
		if(i>R) {
			L=i; R=i;
			while(R<n && combine[R]==combine[R-L]) {
				R++;
			}
			Z.push_back(R-L); R--; 	
		}
		else {
			int k=i-L;
			if(Z[k]<R-i+1) {
				Z.push_back(Z[k]);	
			}
			else {
				L=i;
				while(R<n && combine[R]==combine[R-L])
					R++;
				Z.push_back(R-L); R--;
			}				
		}
	}

	FOR(i,t.length()+1,Z.size()) {
		if(Z[i]==t.length()) cout << i-t.length() << " ";
	}
	
	cout << endl;	
}

int main() {
	cin >> s >> t;
	z_function();
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define FOR(_,__,___) for(int _=__; _<___; _++)

string s, p;
vector<int> prefix;

void prefixCalc() {	
	int k=0; 
	prefix.push_back(k);

	FOR(i,1,p.length()) {
		while(k>0 && p[k]!=p[i])
                	k=prefix[k-1];
                
		if(p[k]==p[i])
			k++;
		
		prefix.push_back(k);
	}	
}

void findOccurences() {
	int k=0;
	FOR(i,0,s.length()) {
		if(s[i]!=p[k]){
			while(k>0 && s[i]!=p[k])
				k=prefix[k-1]; 
		}
		if(s[i]==p[k]) 
			k++;
		if(k==p.length()) {
			cout << i-k+2 << " ";
			k=prefix[k-1];
		}
	}
	cout << endl;
}

int main() {
	cin >> s >> p;
	prefixCalc();
	findOccurences();
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define MAXN 200001

struct cmp {
    bool operator() (pair<int,int> a, pair<int,int>b) {
        return a.first < b.first;
    }
} comparision;

int n, a, b, maxx=0, pfsum=0;
vector< pair<int,int> > v;
vector< pair<int,int> >::iterator it;

int main() {
    cin >> n;
    while(n--) {
        cin >> a >> b;
        v.push_back(make_pair(a, 1));
        v.push_back(make_pair(b,-1));
    }

    sort(v.begin(), v.end(), comparision);
    
    for(it=v.begin(); it!=v.end(); it++) {
        pfsum+=it->second;
        maxx=max(maxx,pfsum);
    }

    cout << maxx << endl;

    return 0;
}
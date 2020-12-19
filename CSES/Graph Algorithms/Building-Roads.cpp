#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;

int n, m, x, y;
int p[MAXN], r[MAXN];
set<int> s;
vector<vi> v;

void init() {
    for(int i=1; i<=n; i++) {
        p[i]=i;
        r[i]=0;
    }
}

void print() {
    vector<int> ans(s.begin(), s.end());
    cout << ans.size() - 1 << endl;
    
    for(int i=0; i<ans.size()-1; i++) {
        cout << ans[i] << " " << ans[i+1] << endl;
    }   
}

int find(int i) {
    if(p[i]!=i) p[i]=find(p[i]);
    return p[i];
}

void join(int i, int j) {
    i=find(i);
    j=find(j);
    if(i==j) return;
    if(r[i]==r[j]) r[i]++;
    if(r[j]<r[i]) {
        p[j]=i;
    }
    else {
        p[i]=j;
    }
}

int main() {
    cin >> n >> m;
    init();
    v.resize(m+1);
    
    for(int i=0; i<m; i++) {
        cin >> x >> y;
        join(x, y);
    }

    for(int i=1; i<=n; i++) {
        s.insert(find(i));
    }
    
    print();

    return 0;
}

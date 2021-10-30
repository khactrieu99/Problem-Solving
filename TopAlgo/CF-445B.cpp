#include <bits/stdc++.h>
using namespace std;

int n, m, a, b;
vector<int> cnt, p;

int find(int v) {
    if(p[v]==v) return v;
    return p[v]=find(p[v]);
}

void connect(int u, int v) { 
    int rootu=find(u);
    int rootv=find(v);
    if(rootu!=rootv) {
        p[rootu]=rootv;
        cnt[rootv]+=cnt[rootu];
        cnt[rootu]=0;
    }
}

int main() {
    cin >> n >> m;
    cnt.resize(n+1);
    p.resize(n+1);
    for(int i=1; i<=n; i++) {
        p[i]=i;
        cnt[i]=1;
    }
    for(int i=0; i<m; i++) {
        cin >> a >> b;
        connect(a,b);
    }
    long long ans=1;
    for(int i=1; i<=n; i++) {
        if(cnt[i]>0) ans<<=(cnt[i]-1);
    }
    cout << ans << endl; 
    return 0;
}

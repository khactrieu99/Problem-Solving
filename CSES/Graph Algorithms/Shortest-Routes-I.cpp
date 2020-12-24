#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

typedef unsigned long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

int n, m, a, b, c;
ll d[MAXN];
bool isVisited[MAXN];
vector<vector<pll>> v;

void dijkstra() {
    priority_queue<pll, vector<pll>, greater<pll>> q;
    q.push({0,1});

    while(!q.empty()) {
        ll dcurr=q.top().first;
        int curr=q.top().second; 
        q.pop();

        if(d[curr]<dcurr) continue;

        for(auto val: v[curr]) {
            if(d[val.first]>dcurr+val.second) {
                d[val.first]=dcurr+val.second;
                q.push({d[val.first],val.first});
            }
        }
    }
}

int main() {
    cin >> n >> m;
    v.resize(n+1);
    for(int i=0; i<m; i++) {
        cin >> a >> b >> c;
        v[a].push_back({b,c});
    }
    
   for(int i=1; i<=n; i++) d[i]=LLONG_MAX;
   d[1]=0;
   dijkstra();

   for(int i=1; i<=n; i++) cout << d[i] << " ";
   cout << endl;

    return 0;
}

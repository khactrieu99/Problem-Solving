#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;

int n, m, k;
int p[MAXN];
bool isVisited[MAXN];
vector<vi> v;

void print(int from, int to) {
    stack<int> s;
    s.push(to);
    while(from!=to) {
        s.push(from);
        from=p[from];
    }   
    s.push(to);
    cout << s.size() << endl;
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}   

bool dfs(int i) {
    isVisited[i]=true;
    for(auto val: v[i]) {
        if(isVisited[val]&&p[i]!=val) {
            print(i, val);
            return true;
        }
        else if(!isVisited[val]) {
            p[val]=i;
            if(dfs(val)) return true;
        } 
    }

    return false;
}

int main() {
    cin >> n >> m;
    v.resize(n+1);

    for(int i=0; i<m; i++) {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i=1; i<=n; i++) p[i]=i; 
    for(int i=1; i<=n; i++) {
        if(!isVisited[i]) {
            if(dfs(i)) return 0;
        }
    }

    cout << "IMPOSSIBLE" << endl;

    return 0;
}   

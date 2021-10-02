#include<bits/stdc++.h>
using namespace std;

int n, m;

int solve() {
    queue<pair<int,int>> q;
    q.push(make_pair(n,0));

    while(!q.empty()) {
        pair<int,int> val = q.front();
        q.pop();

        if(val.first==m) return val.second;
        if(val.first-1>0) q.push(make_pair(val.first-1, val.second+1));
        if(val.first*2<2*m) q.push(make_pair(val.first*2, val.second+1));
    }
    
    return 0;
}

int main() {
    cin >> n >> m;
    cout << solve() << endl;
    return 0;
}

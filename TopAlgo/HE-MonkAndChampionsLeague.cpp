#include <bits/stdc++.h>
using namespace std;

int n, m;
long long ans=0;
vector<int> h;
priority_queue<int> q;

int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        int x; cin >> x;
        q.push(x);
    } 

    for(int i=0; i<m; i++) {
        int maxx=q.top();
        q.pop();
        
        ans+=maxx;
        if(maxx>0) q.push(maxx-1);
    }
    cout << ans << endl;
    
    return 0;
}

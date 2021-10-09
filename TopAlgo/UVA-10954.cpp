#include <bits/stdc++.h>
using namespace std;

int n;
priority_queue<long long, vector<long long>, greater<long long>> q;

int main() {
    while(cin >> n) {
        if(n==0) return 0;

        for(int i=0; i<n; i++) {
            int x; cin >> x;
            q.push(x);
        }
        
        long long ans=0;
        while(q.size()>1) {
            int a=q.top();
            q.pop();

            int b=q.top();
            q.pop();
            
            ans+=(a+b);
            q.push(a+b);
        }
        q.pop();
        
        cout << ans << endl;
    }
    return 0;
}

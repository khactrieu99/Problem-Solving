#include <bits/stdc++.h>
using namespace std;

int n, sum=0, res=0;
vector<int> coins;
vector<vector<bool>> trace;

void solve() {
    trace[0][0]=true;
    for(int i=0; i<=n; i++) trace[i][0]=true;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=sum; j++) {
            if(j>=coins[i-1]) 
                trace[i][j]=trace[i-1][j-coins[i-1]] || trace[i-1][j];
            else 
                trace[i][j]=trace[i-1][j];
        }
    }
    for(int i=1; i<=sum; i++) {
        if(trace[n][i]) res++;
    }
    cout << res << endl;
    for(int i=1; i<=sum; i++) {
        if(trace[n][i]) cout << i << " ";
    }
    
    cout << endl;
}

int main() {
    cin >> n;
    coins.resize(n);
    for(auto &c: coins) {
        cin >> c;
        sum+=c;
    }    
    
    sort(coins.begin(), coins.end());

    trace.resize(n+1, vector<bool>(sum+1,false));    

    solve();

    return 0;
}

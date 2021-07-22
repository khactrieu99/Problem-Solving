#include <bits/stdc++.h>
using namespace std;

int n;
map<int, vector<int>> tree;
vector<int> dp;

int process(int node) {
    if(tree[node].size()==0) return 1;
   
    int res=0;
    for(auto v: tree[node]) res+=process(v);
    dp[node]=res;
    
    return dp[node]+1;
}

int main() {
    cin >> n;
    dp.resize(n+1,0);
    for(int i=1; i<n; i++) {
        int x; 
        cin >> x;
        tree[x].push_back(i+1);
    }

    process(1);

    for(int i=1; i<=n; i++) cout << dp[i] << " ";
    cout << endl;
        
    return 0;
}

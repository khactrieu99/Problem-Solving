#include <bits/stdc++.h>
using namespace std;

#define MAXN 101
#define MAXK 100001

int n, k;
int a[MAXN];
bool dp[MAXK];

int main() {
    cin >> n >> k;
    for(int i=0; i<n; i++) {
        cin >> a[i];
        dp[a[i]]=true;
    }

    dp[0]=false;
    for(int i=1; i<=k; i++) {
        dp[i]=false;
        for(int j=0; j<n; j++) {
            if(a[j]<=i) dp[i]=(dp[i]||!dp[i-a[j]]);
        }
    }
    if(dp[k]) cout << "First" << endl;
    else cout << "Second" << endl;
    
    return 0;
}

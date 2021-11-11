#include <bits/stdc++.h>
using namespace std;

#define MAXN 1002

string s1, s2;
int dp[MAXN][MAXN]={0};
 
int main() {
    cin >> s1 >> s2;
    for(int i=1; i<=s1.length(); i++) {
        for(int j=1; j<=s2.length(); j++) {
            if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],max(dp[i][j-1],dp[i-1][j-1]));
        }
    } 
    cout << dp[s1.length()][s2.length()] << endl;

    return 0;
}

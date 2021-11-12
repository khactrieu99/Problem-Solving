#include <bits/stdc++.h>
using namespace std;

int n;
string s1, s2;
int main() {
    cin >> n;
    while(n--) {
        cin >> s1 >> s2;
        vector<vector<int>> dp(s1.length()+1, vector<int>(s2.length()+1, 0));
        for(int i=0; i<=s1.length(); i++) dp[i][0]=i;
        for(int j=0; j<=s2.length(); j++) dp[0][j]=j;

        for(int i=1; i<=s1.length(); i++) {
            for(int j=1; j<=s2.length(); j++) {
                if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1];
                else {
                    int del = dp[i-1][j];
                    int ins = dp[i][j-1];
                    int rep = dp[i-1][j-1];
                    dp[i][j]=min(del,min(ins,rep))+1;
                }
            }
        }
        cout << dp[s1.length()][s2.length()] << endl;
    }
    return 0;
}

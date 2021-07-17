#include <bits/stdc++.h>
using namespace std;

string s1, s2;
vector<vector<int>> step;
int solve() {
    int n=s1.length(), m=s2.length();
    step.resize(n+1, vector<int>(m+1, 0));
    
    for(int i=0; i<=m; i++) step[0][i]=i;    
    for(int i=0; i<=n; i++) step[i][0]=i;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(s1[i-1]==s2[j-1]) step[i][j]=step[i-1][j-1];
            else {
                step[i][j]=min(step[i][j-1],min(step[i-1][j],step[i-1][j-1]))+1;
            }
        }
    }
    return step[n][m];
}

int main() {
    cin >> s1 >> s2;
    cout << solve() << endl;
    return 0;
}

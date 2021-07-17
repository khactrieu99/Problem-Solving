#include <bits/stdc++.h>
using namespace std;

int a, b;

int solve() {
    vector<vector<int>> rect;
    rect.resize(a+1, vector<int>(b+1, 0));

    for(int i=1; i<=a; i++) {
        for(int j=1; j<=b; j++) {
            if(i!=j) {
                int min_step=INT_MAX;
                for(int k=1; k<i; k++) min_step=min(min_step, rect[i-k][j]+rect[k][j]+1);
                for(int k=1; k<j; k++) min_step=min(min_step, rect[i][j-k]+rect[i][k]+1);
                rect[i][j]=min_step;
            }
        }
    }
    
    return rect[a][b];
}

int main() {
    cin >> a >> b;
    cout << solve() << endl;
    return 0;
}

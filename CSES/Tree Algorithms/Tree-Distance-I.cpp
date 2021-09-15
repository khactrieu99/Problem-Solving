#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> child;



int main(0) {
    cin >> n;
    for(int i=0; i<n-1; i++) {
        int x, y; cin >> x >> y;
        child[x].push_back(y);
        child[y].push_back(x);
    }
    return 0;
}

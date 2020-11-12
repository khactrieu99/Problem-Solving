#include <bits/stdc++.h>
using namespace std;

#define MAXN 21
typedef long long ll;

ll p[MAXN], n, minn=INT_MAX;

void findDiff(int pos, long long diff) {
    if(pos>=n) minn=min(minn,abs(diff));
    else {
        findDiff(pos+1,diff+p[pos]);
        findDiff(pos+1,diff-p[pos]);
    }
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++) cin >> p[i];
    findDiff(0,0);
    cout << minn <<endl;
    return 0;
}
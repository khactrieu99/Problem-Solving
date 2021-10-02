#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> arr;

bool solve(int l, int r) {
    if(l==r) return true;
    
    int mid=l+(r-l)/2;

    bool isLeftIncreasing = solve(l, mid-1);
    bool isRightIncreasing = solve(mid, r);

    return arr[mid-1] <= arr[mid] && isLeftIncreasing && isRightIncreasing;
}

int main() {
    cin >> n;
    arr.resize(n);
    for(auto &v: arr) cin >> v;
    cout << solve(0, n) << endl;
    return 0;
}

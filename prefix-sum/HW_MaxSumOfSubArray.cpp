#include <iostream>
#include <climits>
#include <vector>

using namespace std;

#define FOR(_,__,___) for(int _=__; _<___; _++)
#define REP(_,__,___) for(int _=__; _<=___; _++)

typedef long long ll;
typedef vector<ll> vll;

int n;
vll a;
// normal => O(n^3)
// int MaxSumOfSubArray() {
//     int maxx = INT_MIN;
//     FOR(i, 0, n) {
//         REP(j, 0, i) {
//             int sum=0;
//             REP(k, j, i) {
//                     sum += a[k];
//             }
//             maxx = max(sum, maxx);
//         }
//     }

//     return maxx;
// }

// prefix sum => O(n^2) 
// int MaxSumOfSubArray() {
//     int maxx = INT_MIN;
//     // create prefix sum
//     vll prefix;
//     prefix.push_back(0);
//     REP(i, 1, n)
//         prefix.push_back(prefix[i-1]+a[i-1]);

//     REP(i, 1, n) 
//         REP(j, 1, i) 
//             maxx = max(maxx, prefix[i] - prefix[j - 1]);

//     return maxx;
// }

// O(n)
int MaxSumOfSubArray() {
    ll maxx = a[0], curr = a[0];
    FOR(i, 1, n) {
        curr = max(a[i], curr + a[i]);
        maxx = max(maxx, curr);
    }

    return maxx;
}

int main() {
    cin >> n;
    FOR(i, 0, n) {
        int x; cin >> x;
        a.push_back(x);
    }
    cout << MaxSumOfSubArray() << endl;
    return 0;
}
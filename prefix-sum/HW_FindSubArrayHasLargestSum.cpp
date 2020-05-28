#include <iostream>
#include <climits>
#include <vector>
#include <map>

using namespace std;

#define FOR(_,__,___) for(int _=__; _<___; _++)
#define REP(_,__,___) for(int _=__; _<=___; _++)

typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> pii;

int n, k, maxx = INT_MIN, maxx_start, maxx_end;
vll a;

// O(n*(n-k))
void FindSubArrayHasLargestSum() {
    vll prefixSum;
    prefixSum.push_back(0);

    REP(i, 1, n) {
        prefixSum.push_back(prefixSum[i-1] + a[i-1]);
    }

    REP(i, 1, n) {
        REP(j, 1, i - k) {
            if(maxx < prefixSum(i) - prefixSum(j)) {
                maxx = prefixSum(i) - prefixSum(j);
                maxx_start = j + 1; maxx_end = i;
            }
        }
    }

    cout << maxx << " " << maxx_start << "->" << maxx_end << endl;
}



int main() {
    cin >> n >> k;
    FOR(i, 0, n) {
        int x; cin >> x;
        a.push_back(x);
    }

    FindSubArrayHasLargestSum();
    return 0;
}
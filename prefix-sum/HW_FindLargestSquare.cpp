#include <iostream>
#include <climits>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

#define FOR(_,__,___) for(int _=__; _<___; _++)
#define REP(_,__,___) for(int _=__; _<=___; _++)

typedef long long ll;
typedef vector<ll> vll;
typedef pair<int, int> pii;

int n, m;
vector<vll> prefixSum;


//O(m*n*min(m,n))
void FindLargestSquare() {
    int maxx=0, x, y;
    REP(i, 1, n) {
        REP(j, 1, m) {
            int ms = min(n-i+1, m-j+1);
            FOR(k, 0, ms) {
                int sum = prefixSum[i+k][j+k] 
                        - prefixSum[i-1][j+k] 
                        - prefixSum[i+k][j-1]
                        + prefixSum[i-1][j-1];
                if(sum==pow(k+1,2) && k+1>maxx) {
                    maxx = k+1;
                    x=i; y=j;
                }
            }
        }
    }
    cout << "max square: " << maxx*maxx << endl;
    cout << "with (i, j) begin is: (" << x << "," << y << ")" << endl; 
}

bool isSquareNumber(int num) {
    return pow(int(sqrt(num)), 2) == num;
}

int main() {
    cin >> n >> m;

    prefixSum.resize(n+1);
    REP(i, 0, n) {
        prefixSum[i].resize(m+1);
        fill(prefixSum[i].begin(), prefixSum[i].end(), 0);
    }
    
    REP(i, 1, n) {
        REP(j, 1, m) {
            int x; cin >> x;
            prefixSum[i][j] =  (isSquareNumber(x) ? 1 : 0 ) 
                               + prefixSum[i-1][j] 
                               + prefixSum[i][j-1] 
                               - prefixSum[i-1][j-1];
        }
    }

    FindLargestSquare();

    return 0;
}
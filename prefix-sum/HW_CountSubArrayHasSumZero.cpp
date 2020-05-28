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

int n, count=0;
ll prefixSum=0;
vll a;
map<ll, vll> sameSum;
map<ll, vll>::iterator it;

void CountSubArrayHasSumZero() {
    // this is for the case that prefix sum at position i is equal to 0
    vll temp; temp.push_back(0);
    sameSum.insert(make_pair(0, temp));

    FOR(i, 0, n) {
        prefixSum += a[i];
        it = sameSum.find(prefixSum);
        if(it != sameSum.end())
            it->second.push_back(i+1);
        else {
            vll vect;
            vect.push_back(i+1);
            sameSum.insert(make_pair(prefixSum, vect));
        }
    }
    
    for(it=sameSum.begin(); it!=sameSum.end(); it++) {
        int size = it->second.size();
        count += size * (size - 1) / 2;
    }

    cout << "number of sub array has sum equal to 0: " << count << endl;
}

int main() {
    cin >> n;
    FOR(i, 0, n) {
        int x; cin >> x;
        a.push_back(x);
    }

    CountSubArrayHasSumZero();

    return 0;
}
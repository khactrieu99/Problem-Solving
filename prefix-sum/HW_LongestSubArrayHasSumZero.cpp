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

int n, maxx=0;
ll prefixSum=0;
vll a;
map<ll, pii> sameSum;
map<ll, pii>::iterator it;

// normal apprach, with every i from 0 to n, we calculate the sum from 0 to i
// then we find 2 positions i and j such that j - i is max
// => O(n^3)
// void LongestSubArrayHasSumZero() {
//     FOR(i, 0, n) {
//         REP(j, 0, i) {
//             int sum=0;
//             REP(k, j, i) {
//                 sum += a[k];
//             }
//             if(sum==0 && maxx < i-j+1) {
//                 maxx = i-j+1;
//             }
//         }
//     }
//     cout << "max length: " << maxx << endl;
// }


// better approach, this approach is improval version of approach
// in detail we use prefix sum technique to store sum of all elements from 
// 0 to i with 0<=i<n, after that we iterate all the sums we have and find out which 2 of them have 
// substraction equal to 0 and have largest length
// => O(n^2)
// void LongestSubArrayHasSumZero() {
//     vll prefix;
//     prefix.push_back(0);
//     REP(i, 1, n) 
//         prefix.push_back(prefix[i-1]+a[i-1]);

//     REP(i, 1, n) {
//         FOR(j, 0, i) {
//             if(prefix[i] == prefix[j] && maxx < i-j)
//                 maxx = i-j;
//         }
//     }

//     cout << "max length: " << maxx << endl;
// }



// the idea of this approach is to save prefix sum of each position from left to right,
// if prefix sum at position [i] is equal to such sum at [j] then 
// we have the sum of sub array from [i+1]to [j] is equal to 0
// => O(n)

// we use hash to store such sum
void LongestSubArrayHasSumZero() {
    // this is for the case that prefix sum at position i is equal to 0
    sameSum.insert(make_pair(0, make_pair(0, 0)));

    FOR(i, 0, n) {
        prefixSum += a[i];
        it = sameSum.find(prefixSum);
        if(it != sameSum.end())
            it->second.second = i+1;
        else {
            sameSum.insert(make_pair(prefixSum, make_pair(i+1, 0)));
        }
    }
    
    for(it=sameSum.begin(); it!=sameSum.end(); it++)
        maxx = max(maxx, it->second.second - it->second.first);
    cout << "max length: " << maxx << endl;
}


int main() {
    cin >> n;
    FOR(i, 0, n) {
        int x; cin >> x;
        a.push_back(x);
    }
    LongestSubArrayHasSumZero();
    return 0;
}
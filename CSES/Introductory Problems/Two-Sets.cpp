#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, sum1=0, sum2=0;
queue<int> set1, set2;

int main() {
    cin >> n;
    while(n!=0) {
        if(sum1<=sum2) {
            sum1+=n;
            set1.push(n);
        }
        else {
            sum2+=n;
            set2.push(n);
        }
        n--;
    }
    if(sum1!=sum2) cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        cout << set1.size() << endl;
        while(!set1.empty()) {
            cout << set1.front() << " ";
            set1.pop();
        }
        cout << endl;
        cout << set2.size() << endl;
        while(!set2.empty()) {
            cout << set2.front() << " ";
            set2.pop();
        }
    }
    cout << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int t, n, sum;
vector<int> a;
vector<bool> prime;

int main() {
    cin >> t;
    prime.resize(20001, true);
    for(int i=2; i<=20000; i++) {
        if(prime[i]==true) {
            for(int j=2; i*j<=20000; j++) prime[i*j]=false;
        }
    }
    while(t--) {
        cin >> n;
        a.resize(n);
        sum=0;
        for(auto &v: a) {
            cin >> v;
            sum += v;
        }
        int j=n-1;
        while(prime[sum]) sum-=a[j--];
        cout << "---" << endl;
        cout << j+1 << endl;
        for(int i=1; i<=j; i++) cout << i << " ";     
        cout << endl;
        cout << "---" << endl;
    }
    return 0;
}

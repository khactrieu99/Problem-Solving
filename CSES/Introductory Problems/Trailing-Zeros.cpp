#include <bits/stdc++.h>
using namespace std;

int n;
int res=0, temp;

int main() {
    cin >> n;
    // O(nlogn)
    // for(int i=5; i<=n; i+=5) {
    //     res++;
    //     temp=i/5;
    //     while(temp%5==0) {
    //         res++;
    //         temp/=5;
    //     }
    // }

    // better way O(n)
    while(n) res+=(n=n/5);
    
    cout << res << endl;
    return 0;
}
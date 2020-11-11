#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

ull n;

int main() {
    cin >> n;
    for(ull i=1; i<=n; i++)
        cout << i*i*(i*i-1)/2 - 4*(i-1)*(i-2) << endl;
    return 0;
}
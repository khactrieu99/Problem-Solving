#include <bits/stdc++.h>
using namespace std;

int a, b, c;

void check() {
    cin >> a >> b >> c;
    if(-a+b+c==0||a-b+c==0||a+b-c==0) cout << "yes" << endl;
    else cout << "no" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    check();
    check();
    return 0;
}

#include <iostream>
#include <cmath>
using namespace std;

int a, x, y;
int main() {
    scanf("%d%d%d",&a,&x,&y);
    if(abs(x) >= a || y % a == 0) cout << -1;
    else {
        int k = ceil(double(y)/a);
        if(k == 1 || k % 2 == 0) {
            if(abs(x) >= (double)a / 2) cout << -1;
            else if(k == 1 || k == 2) cout << k;
            else cout << 2 + 3*((k - 1)/2);
        }
        else {
            if(x == 0) cout << -1;
            else if(x < 0) cout << 3 * (k / 2);
            else cout << 3 * (k / 2) + 1;
        }
    }
    return 0;
}
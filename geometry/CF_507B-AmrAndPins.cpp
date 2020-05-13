#include <iostream>
#include <cmath>
using namespace std;

long long r, x, y, x2, y2; 
int main() {
    //scanf("%d%d%d%d%d", &r, &x1, &y1, &x2, &y2);
    cin >> r >> x >> y >> x2 >> y2;
    double d = sqrt((x2-x)*(x2-x)+(y2-y)*(y2-y));
    cout << ceil(d/(2*r));
    return 0;
}
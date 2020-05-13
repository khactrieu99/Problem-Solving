#include <iostream>
using namespace std;

int d[6];

bool isRightAngled() {
    int a = (d[0]-d[2])*(d[0]-d[2]) + (d[1]-d[3])*(d[1]-d[3]);
    int b = (d[2]-d[4])*(d[2]-d[4]) + (d[3]-d[5])*(d[3]-d[5]);
    int c = (d[4]-d[0])*(d[4]-d[0]) + (d[5]-d[1])*(d[5]-d[1]);

    return a&&b&&c&&(a+b==c || b+c==a || a+c==b);
}

int main() {
    for(int i=0; i<6; i++) 
        scanf("%d", &d[i]);
    if(isRightAngled()) cout << "RIGHT";
    else {
        bool check = false;
        for(int i=0; i<6; i++) {
            d[i]--;
            if(isRightAngled()) {
                cout << "ALMOST";
                check = true;
                break;
            }
            d[i]+=2;
            if(isRightAngled()) {
                cout << "ALMOST";
                check = true;
                break;
            }
            d[i]--;
        }
        if(!check) cout << "NEITHER";
    }
    return 0;
}
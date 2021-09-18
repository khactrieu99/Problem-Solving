#include<bits/stdc++.h>
using namespace std;

int m, s, s1, s2;
string minn, maxx;

bool can(int mm, int ss) {
    return ss >= 0 && ss <= mm*9;    
}

int main() {
    cin >> m >> s;
    s1=s; s2=s;
    for(int i=0; i<m; i++) {
        for(int d=0; d<10; d++) {
            if((i>0 || d>0 || (m==1 && d==0)) && can(m-i-1, s1-d)) {
                minn += char('0' + d);
                s1 -= d;
                break;
            }
        }
    }
    for(int i=0; i<m; i++) {
        for(int d=9; d>=0; d--) {
            if((i>0 || d>0 || (m==1 && d==0)) && can(m-i-1, s2-d)) {
                maxx += char('0' + d);
                s2 -= d;
                break;
            }
        }
    }

    if(!(minn.length() == m && maxx.length() == m)) cout << "-1 -1" << endl;
    else cout << minn << " " << maxx << endl;

    return 0;
}

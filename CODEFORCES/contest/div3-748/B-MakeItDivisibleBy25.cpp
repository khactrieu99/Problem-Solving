#include <bits/stdc++.h>
using namespace std;

int t;
string n;

int solve() {
    int rs=INT_MAX;
    for(int i=n.length()-1; i>0; i--) {
        for(int j=i-1; j>=0; j--) {
            string num=string(1,n[j])+n[i];
            int val = n.length()-j-2;
            if(num=="00" || num=="25" || num=="50" || num=="75") {
                rs=min(rs,val);
            }  
        }
    }
    return rs;
}

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        cout << solve() << endl;                    
    }
    return 0;
}

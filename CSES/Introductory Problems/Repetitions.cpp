#include <bits/stdc++.h>
using namespace std;

int main() {
    string input;
    int res=0, begin=0, end=0;
    cin >> input;
    while(end<input.length()) {
        if(input[end]==input[begin]) {
            res=max(res, end-begin+1);
            end++;
        }
        else {
            begin=end; 
        }
    }

    cout << res << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

string input, output="", ans="";
bool a[26];
int cnt=0;

int main() {
    cin >> input;
    for(char &c: input) {
        if(!a[c-'A']) {
            a[c-'A']=true;
            cnt++;
        }
        else {
            ans+=c;
            a[c-'A']=false;
            cnt--;
        }
    }

    if(cnt>1) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }

    output+=ans;
    for(char &c: input) {
        if(a[c-'A']) {
            output+=c;
            a[c-'A']=false;
        }
    }
    reverse(ans.begin(), ans.end());
    output+=ans;

    cout << output << endl;

    return 0;
}
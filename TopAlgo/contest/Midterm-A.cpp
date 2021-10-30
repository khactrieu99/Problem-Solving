#include<bits/stdc++.h>
using namespace std;

typedef struct {
    bool isBracket;
    int val;
} node;

int ans;
string f;
stack<node> s;
int main() {
    cin >> f;
    for(int i=0; i<f.size(); i++) {
        switch(f[i]) {
            case '(': 
                s.push({true,0});
                break;
            case 'O':
                s.push({false,16});
                break;
            case 'H':
                s.push({false,1});
                break;
            case 'C':
                s.push({false,12});
                break;
            case ')':
                ans=0;
                while(!s.empty()) {
                    node n=s.top(); s.pop();
                    if(n.isBracket) break;
                    ans += n.val;
                }
                s.push({false,ans});
                break;
            default:
                node n=s.top(); s.pop();
                s.push({false,n.val*(f[i]-'0')});
        }
    }
    ans=0;
    while(!s.empty()) {
        node n=s.top(); s.pop();
        ans+=n.val;
    }
    cout << ans << endl;
    return 0;
}

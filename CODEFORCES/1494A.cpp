#include <bits/stdc++.h>
using namespace std;

int t;
string s;
bool flag=false;
stack<char> b;

void add_to_stack(char c) {
    if(!b.empty() && b.top()=='(' && c==')') b.pop();
    else b.push(c);
}
int main() {
    cin >> t;
    while(t--) {
        cin >> s;
        
        for(int i=0; i<(1<<3); i++) {
            for(int j=0; j<s.length(); j++) {
                int v=0;

                if(s[j]=='A') v=i&(1<<2);
                else if(s[j]=='B') v=i&(1<<1);
                else v=i&1;
                
                if(v) add_to_stack(')');
                else add_to_stack('('); 
            }
            
            if(b.empty()) {
                flag = true;
                break;
            }
            
            while(!b.empty()) b.pop();
        }

        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;

        flag = false;
    }   
    return 0;
}

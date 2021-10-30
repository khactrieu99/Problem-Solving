#include <bits/stdc++.h>
using namespace std;
 
typedef struct {
    int f, s;
} node;

int n;
vector<node> g;

int main() {
    cin >> n;
    g.resize(n);
    for(auto &p: g) cin >> p.f >> p.s;
    for(auto p: g) cout << p.f << " " << p.s << endl;
    
    return 0;
}

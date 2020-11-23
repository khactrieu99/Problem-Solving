#include <bits/stdc++.h>
using namespace std;

#define MAXN 200001
#define all(x) x.begin(),x.end()

#define FOR(i,a,b) for(int i=a; i<b; i++)
#define REPL(i,a,b) for(int i=a; i<=b; i++)
#define RFOR(i,a,b) for(int i=b; i>a; i--)
#define RREPL(i,a,b) for(int i=b; i>=a; i--)

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

int n, x, z;
ll cur=0, res=0;
map<ll,ll> m;
map<ll,ll>::iterator it;

int main() {
    cin >> n >> x;
    
    FOR(i,0,n) {
        cin >> z;
        cur += z;
        if(cur==x) res++;

        if(m.find(cur-x)!=m.end()) res+=(m[cur-x]);
        m[cur]++;
    }

    cout << res << endl;
    return 0;
}
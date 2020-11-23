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

int n, z;
ll x;
vi res;
vector<pii> a;

int main() {
    // get input
    cin >> n >> x;
    FOR(i,0,n) {
        cin >> z;
        a.push_back({z,i+1});
    }

    sort(all(a));

    FOR(i,0,n-3) {
        FOR(j,i+1,n-2) {
            ll t = x - a[i].first - a[j].first;
            int l = j+1, r = n-1;
            while(l<r) {
                if(a[l].first+a[r].first==t) {
                    res.push_back(a[i].second);
                    res.push_back(a[j].second);
                    res.push_back(a[l].second);
                    res.push_back(a[r].second);
                    break;
                }
                else if(a[l].first+a[r].first>t) r--;
                else l++;
            }
            if(!res.empty()) {
                for(auto item: res) cout << item << " ";
                break;
            }
        }
        if(!res.empty()) break;
    }

    if(res.empty()) cout << "IMPOSSIBLE" << endl;
    
    return 0;
}
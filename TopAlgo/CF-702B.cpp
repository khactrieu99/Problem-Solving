#include <bits/stdc++.h>
using namespace std;

int n;
long long ans=0;
vector<int> a;
map<int,int> cnt;

int main() {
    cin >> n;
    a.resize(n);
    for(auto &v: a) {
        cin >> v;
        cnt[v]++;
    }
    for(int i=0; i<n; i++) {
        unsigned int target=1<<31;
        while(target>0) {
            int other = target-a[i];
            if(cnt.find(other)!=cnt.end() && cnt[other]>0) {
                ans+=cnt[other];
                if(other==a[i]) ans--;
            }
            target >>= 1;
        }
        cnt[a[i]]--;
    }
    cout << ans << endl;
    return 0;
}

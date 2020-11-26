#include <bits/stdc++.h>
using namespace std;

#define MAXN 50002

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;

int n, q, a, b;
vi v, min_f, max_f;

void update(int i, int val) {
    while(i<=n) {
        if(min_f[i]==-1||min_f[i]>val) min_f[i]=val;
        if(max_f[i]==-1||max_f[i]<val) max_f[i]=val;
        i=i+(i&-i);
    }
}

int get(int i, int j) {
    int minn=INT_MAX, maxx=INT_MIN;
    while(j>=i) {
        if((j-(j&-j)>=i)) {
            minn=min(minn,min_f[j]);
            maxx=max(maxx,max_f[j]);
            j=j-(j&-j);
        }
        else {
            minn=min(minn,v[j-1]);
            maxx=max(maxx,v[j-1]);
            j--;
        }
    }
    return maxx-minn;
}

int main() {
    cin >> n >> q;

    min_f.resize(n+1,-1);
    max_f.resize(n+1,-1);
    v.resize(n);

    for(int i=0; i<n; i++) {
        cin >> v[i];
        update(i+1, v[i]);        
    }

    while(q--) {
        cin >> a >> b;
        cout << get(a,b) << endl;        
    }

    return 0;
}

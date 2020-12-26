#include <bits/stdc++.h>
using namespace std;

#define MAXN 505
#define MAX_RANGE 100000000000005

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

int n, m, q, a, b, c;
ll d[MAXN][MAXN];

void floyd_warshall() {
    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
}

int main() {
    cin >> n >> m >> q;
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(i==j) d[i][j]=0;
            else d[i][j]=MAX_RANGE;
        }
    }
    for(int i=0; i<m; i++) {
        cin >> a >> b >> c;
        d[a][b]=min(ll(c),d[a][b]);
        d[b][a]=min(ll(c),d[b][a]);
    }

    floyd_warshall();

    while(q--) {
        cin >> a >> b;
        cout << ((d[a][b]>=MAX_RANGE)?-1:d[a][b]) << endl;
    }

    return 0;
}

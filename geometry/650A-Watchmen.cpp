// #include <bitset/stdc++.h>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define FOR(i,a,b) for(int i=a;i<b;i++)

typedef long long ll;

ll n, res=0;
map<ll, ll> pointX, pointY;
map<ll, ll>::iterator it1;

map<pair<ll,ll>, ll> point;
map<pair<ll,ll>, ll>::iterator it2;

int main() {
    scanf("%d",&n);

    while(n--) {
        int x, y;
        scanf("%d%d", &x, &y);
        pointX[x]++;
        pointY[y]++;
        point[make_pair(x,y)]++;
    }
    
    for(it1=pointX.begin();it1!=pointX.end();it1++) res+=it1->second*(it1->second-1)/2;
    for(it1=pointY.begin();it1!=pointY.end();it1++) res+=it1->second*(it1->second-1)/2;
    for(it2=point.begin();it2!=point.end();it2++) res-=it2->second*(it2->second-1)/2;

    cout << res << endl;

    return 0;
}
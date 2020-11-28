#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000001

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;

struct node {
    int optimal, open, close;
    node(int otp, int o, int c) {
        optimal = otp;
        open = o;
        close = c;
    }
    node operator + (const node &left, const node &right) const{
        Node res;

        int tmp = min(left.open, right.close);

        res.optimal = left.optimal + right.optimal + tmp;
        res.open = left.open + right.open - tmp;
        res.close = left.close + right.close - tmp;

        return res;
    }
} Node;

string s;
int n, a, b;
vector<Node> st(MAXN*4+1);

void build(int id, int l, int r) {
    if(l==r) {
        if(st[l]==')') st[id] = node(0,0,1);
        else st[id] = node(0,1,0);
        return;
    }

    int mid=(l+r)/2;

    build(id*2, l, mid);
    build(id*2+1, mid+1, r);

    st[id] = st[id*2] + st[id*2+1];
}

Node query(int id, int l, int r, int u, int v) {
    if(l>v || r<u) return node(0,0,0);
    if(u<=l && v>=r) return st[id];

    int mid=(l+r)/2;

    return query(id*2,l,mid,u,v) + query(id*2+1,mid+1,r,u,v);
}

int main() {
    cin >> s >> n;
    // st.resize(n*4+1);
    
    while(n--) {
        cin >> a >> b;
        Node t = query(1,1,s.length(),a,b);
        cout << t.optimal << endl;
    }
        
    return 0;
}

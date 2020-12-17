#include<bits/stdc++.h>
using namespace std;

#define MAXN 1005

typedef long long ll;
typedef vector<char> vc;
typedef vector<bool> vb;

typedef struct {
    int y, x;
} coor;

int n, m;

char g[MAXN][MAXN], mdir[MAXN][MAXN];
bool isVisited[MAXN][MAXN];
coor start, destination;

char direction[4] = {'L', 'R', 'U', 'D'};
coor fw['U'-'A'+2], bw['U'-'A'+2];

void init() {
    fw['L'-'A']={0,-1};
    fw['R'-'A']={0, 1};
    fw['U'-'A']={-1,0};
    fw['D'-'A']={1, 0};

    bw['L'-'A']={0, 1};
    bw['R'-'A']={0,-1};
    bw['U'-'A']={1, 0};
    bw['D'-'A']={-1,0};
}

void print() {
    cout << endl << "YES" << endl;

    string s="";
    int i=destination.y, j=destination.x;
    while(i!=start.y||j!=start.x) {
        s+=mdir[i][j];
        int dir = mdir[i][j]-'A';
        i+=bw[dir].y;
        j+=bw[dir].x;
    }
    cout << s.length() << endl; 
    reverse(s.begin(), s.end());
    
    cout << s << endl;
}

void findPath() {
    queue<coor> q;
    q.push(start);
    while(!q.empty()) {
        coor temp=q.front(); q.pop();
        isVisited[temp.y][temp.x]=true;
        if(g[temp.y][temp.x]=='B') {
            print();
            return;
        }
        for(int i=0; i<4; i++) {
            coor muv=fw[direction[i]-'A'];
            coor next={temp.y+muv.y, temp.x+muv.x};
            if(!isVisited[next.y][next.x]) {
                q.push(next);
                mdir[next.y][next.x]=direction[i];
            }
        }
    }
    cout << "NO" << endl;
}

int main() {
    init();
    cin >> n >> m;

    for(int i=0; i<n+2; i++) {
        for(int j=0; j<m+2; j++) {
            mdir[i][j]='#';
            isVisited[i][j]=true;
            if(i>0&&j>0&&i<n+1&&j<m+1) {
                cin >> g[i][j];
                if(g[i][j]=='A') {
                    start.y=i;
                    start.x=j;
                }
                if(g[i][j]=='B') {
                    destination.y=i;
                    destination.x=j;
                }
                if(g[i][j]!='#') isVisited[i][j]=false;
            }
        }
    }

    findPath();

    return 0;
}

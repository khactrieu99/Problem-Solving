#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<char> vc;
typedef vector<bool> vb;

typedef struct {
    int x, y;
} coor;

typedef pair<coor,char> bfs; // first is coordinate (x,y), second is the move ['L','R','D','U']

int x[] = {1, -1, 0, 0};
int y[] = {0, 0, 1, -1};
char m[] = {'R', 'L', 'D', 'U'};

int n, m;
bool flag=false;
vector<vc> g;
vc path;
vector<vb> isVisited;
coor start, destination;

void printPath() {
    cout << endl << "YES" << endl;
    cout << path.size() << endl;
    for(auto c: path) {
        cout << c;
    }
    cout << endl;
}

void findPath(bfs p) {
    queue<bfs > q;    
    q.push(p);
    while(!q.empty()) {
        coor t = p.first; 
        for(int i=0; i<4; i++) {
            if(g[t.y+y[i]][t.x+x[i]]!='#') {
                coor next = {t.x+x[i], t.y+y[i]}
                q.push(make_pair(next,p.second);
            }
        }        
    }
}

int main() {
    cin >> n >> m;
    g.resize(n+2);
    isVisited.resize(n+2);
    for(int i=0; i<n+2; i++) {
        g[i].resize(n+2);
        isVisited[i].resize(n+2);
    }

    for(int i=0; i<n+2; i++) {
        for(int j=0; j<m+2; j++) {
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
                isVisited[i][j]=false;
            }
        }
    }

    findPath(make_pair(start,' '));

    return 0;
}

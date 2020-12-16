#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<char> vc;
typedef vector<bool> vb;

typedef struct {
    int x, y;
} coor;

int n, m, ;
vc g, path;
vb isVisited;
coor start, end;

void findPath(int i, int j, char m) {
    if(i==end.y&&j==end.x) return;
    if(!isVisited[i][j]) {
        isVisited[i][j]=true;
        
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

    for(int i=0; i<n+2; n++) {
        for(int j=0; j<n+2; j++) {
            isVisited[i][j]=true;
            if(i>0&&j>0&&i<n+1&&j<n+1) {
                cin >> g[i][j];
                if(g[i][j]=='A') {
                    start.y=i;
                    start.x=j;
                }
                if(g[i][j]=='B') {
                    end.y=i;
                    end.x=j;
                }
                isVisited[i][j]=false;
            }
        }
    }

    findPath(start.y, start.x);
    
    cout << path.size() << endl;
    for(auto c: path) {
        cout << c;
    }

    cout << endl;
    
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<char> vc;
typedef pair<int,int> pii;

int x[]={1, -1, 0, 0};
int y[]={0, 0, 1, -1};
char muv[]={'R', 'L', 'D', 'U'};
int ix[]={-1, 1, 0, 0};
int iy[]={0, 0, -1, 1};

int dist[MAXN][MAXN]={0};
int d[MAXN][MAXN]={0};

int n, m;
bool isVisited[MAXN][MAXN];
char p[MAXN][MAXN];
vector<vc> graph;
queue<pii> monsters, q;
pii start;

bool isValid(int i, int j) {
    return (i>=0&&j>=0&&i<n&&j<m&&graph[i][j]!='#');
}

void print(pii des) {
    cout << "YES" << endl;

    stack<char> s;
    while(des.first!=start.first||des.second!=start.second) {
        s.push(p[des.first][des.second]);
        for(int i=0; i<4; i++) {
            if(muv[i]==p[des.first][des.second]) {
                des.first+=iy[i];
                des.second+=ix[i];
                break;
            }
        }
    }
    cout << s.size() << endl;
    while(!s.empty()) {
        cout << s.top();
        s.pop();
    }
    cout << endl;
}

void multiSourceBFS() {
    while(!monsters.empty()) {
        auto temp = monsters.front(); monsters.pop();
        for(int i=0; i<4; i++) {
            auto next = make_pair(temp.first+y[i], temp.second+x[i]);
            if(isValid(next.first,next.second)&&!isVisited[next.first][next.second]) {
                isVisited[next.first][next.second]=true;
                monsters.push(make_pair(next.first,next.second));
                dist[next.first][next.second]=dist[temp.first][temp.second]+1;
            }
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            isVisited[i][j]=false;
        }
    }
}

void BFS() {
    multiSourceBFS();
    q.push(make_pair(start.first,start.second));
    isVisited[start.first][start.second]=true;

    while(!q.empty()) {
        auto temp = q.front(); q.pop();
        if(temp.first==0||temp.second==0||temp.first==n-1||temp.second==m-1) {
            print(temp);
            return;
        }
        for(int i=0; i<4; i++) {
            auto next = make_pair(temp.first+y[i], temp.second+x[i]);
            if(isValid(next.first,next.second)&&!isVisited[next.first][next.second]&&d[temp.first][temp.second]+1<dist[next.first][next.second]) {
                d[next.first][next.second]=d[temp.first][temp.second]+1;
                isVisited[next.first][next.second]=true;
                p[next.first][next.second]=muv[i];
                q.push(make_pair(next.first,next.second));
            }
        }
    }
    
    cout << "NO" << endl;
}

int main() {
    cin >> n >> m;
    graph.resize(n);

    for(int i=0; i<n; i++) {
        graph[i].resize(m);    
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            dist[i][j]=INT_MAX;
            cin >> graph[i][j];
            if(graph[i][j]=='M') {
                monsters.push(make_pair(i,j));
                isVisited[i][j]=true;
                dist[i][j]=0;
            }
            if(graph[i][j]=='A') {
                start.first=i;
                start.second=j;
                dist[i][j]=0;
            }
        }
    }

    BFS();

    return 0;
}

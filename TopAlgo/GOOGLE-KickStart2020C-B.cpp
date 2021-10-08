#include <bits/stdc++.h>
using namespace std;

typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<char,char> pcc;
typedef vector<pcc> vpc;

int x[] = {0, 1, -1, 0};
int y[] = {1, 0, 0, -1};

queue<char> topoStack;
int t, tr=1, r, c, curDeep;
char curAns;
vvb visited;
vb topoVisited;
vi check;
vvc wall;
unordered_map<char,char> g;

bool recurLoop(int i) {
    check[i]=1;
    auto ite=g.find(i);
    if(ite!=g.end()) {
        if(check[ite->second]==1 || (check[ite->second]==0 && recurLoop(ite->second))) return true;
    }
    check[i]=2;    
    return false;
}

bool checkCycle() {
    for(auto const& val: g) {
        if(check[val.first]==0 && recurLoop(val.first)) return true;
    }
    return false;
}

void dfs(char i) {
    topoVisited[i]=true;
    
    auto ite=g.find(i);
    if(ite!=g.end()&&ite->second!='A'-1) {
        if(!topoVisited[ite->second]) dfs(ite->second);    
    }

    topoStack.push(i);
}

void findTopo() {
    topoVisited.clear();
    topoVisited.resize(91, false);
    
    for(auto const& val: g) {
        if(!topoVisited[val.first]) dfs(val.first);
    }

    while(!topoStack.empty()) {
        cout << topoStack.front();
        topoStack.pop();
    }
    cout << endl;
}

void build(int i, int j, char curChar) {
    visited[i][j]=true;
    
    for(int k=0; k<4; k++) {
        int nextX=i+x[k], nextY=j+y[k];
        bool xCondition=(nextX<r)&&(nextX>=0);
        bool yCondition=(nextY<c)&&(nextY>=0);
        
        if(xCondition && yCondition) {
            if(nextX>i && nextX>curDeep && wall[nextX][nextY]!=curChar) {
                curDeep=nextX;
                curAns=wall[nextX][nextY];
            }

            if(wall[nextX][nextY]==curChar && !visited[nextX][nextY]) { 
                build(nextX, nextY, curChar);
            }
        }
    }
}

int main() {
    cin >> t;
    while(t--) {
        cin >> r >> c;
        
        g.clear();
        check.clear(); check.resize(91, 0);
        wall.clear(); wall.resize(r, vc(c));
        visited.clear(); visited.resize(r, vb(c, false));
        
        for(auto &r: wall) { 
            for(auto &val: r) {
                cin >> val;
                curAns=val;
            }
        }

        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(!visited[i][j]) {
                    curAns=wall[i][j];
                    curDeep=-1;
                    build(i, j, wall[i][j]);
                    if(curAns!=wall[i][j]) g[wall[i][j]] = curAns;
                    else g[wall[i][j]] = 'A' - 1;
                }
            }
        }
        
        cout << "Case #" << tr << ": ";
        if(checkCycle()) cout << -1 << endl;
        else findTopo();
        
        tr++;
    }
    return 0;
}

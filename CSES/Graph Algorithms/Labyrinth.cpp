#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define pii pair<int,int>
#define fast ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
 
const int nax = 1e3+10;
bool vis[nax][nax];
char last[nax][nax];
int sx , sy , ex, ey , n , m ;
 
bool valid( int x,int y )
{
    if( x>=0 && y>=0 && x<n && y<m && !vis[x][y] )
        return 1;
    return 0;
}
void bfs()
{
    vis[sx][sy] = 1;
    queue< pii > q;
    q.push({sx,sy});
    while(!q.empty())
    {
        pii p = q.front();
        q.pop();
        int x = p.ff;
        int y = p.ss;
    if( x==ex && y==ey )
    {
        string s;
        cout << "YES\n";
        while( x!=sx || y!=sy )
        {
            s += last[x][y];
            if( last[x][y] == 'U' ) x++;
            else if( last[x][y] == 'D' ) x--;
            else if( last[x][y] == 'L' ) y++;
            else y--;
        }
        reverse(s.begin(),s.end());
        cout << s.size() << "\n" << s;
        exit(0);
 
    }
        if( valid( x-1,y) ) vis[x-1][y] = 1, last[x-1][y] = 'U',q.push({x-1,y});
        if( valid( x+1,y) ) vis[x+1][y] = 1, last[x+1][y] = 'D',q.push({x+1,y});
        if( valid( x,y-1) ) vis[x][y-1] = 1, last[x][y-1] = 'L',q.push({x,y-1});
        if( valid( x,y+1) ) vis[x][y+1] = 1, last[x][y+1] = 'R',q.push({x,y+1});
    }
    return ;
}
signed main()
{
    fast;
    cin >> n >> m;
    for(int i = 0 ; i < n  ; i++ )
    {
        string s;
        cin >> s;
        for(int j=0; j < m ; j++ )
        {
            if( s[j] == 'A' ) sx = i , sy = j;
            else if( s[j] == 'B' ) ex = i , ey = j;
            else if( s[j] == '#' ) vis[i][j] = 1;
        }
    }
    bfs();
    cout << "NO";
 
}

//#include<bits/stdc++.h>
//using namespace std;
//
//#define MAXN 1005
//
//typedef long long ll;
//typedef vector<char> vc;
//typedef vector<bool> vb;
//
//typedef struct {
//    int y, x;
//} coor;
//
//int n, m;
//
//char g[MAXN][MAXN], mdir[MAXN][MAXN];
//bool isVisited[MAXN][MAXN];
//coor start, destination;
//
//char direction[4] = {'L', 'R', 'U', 'D'};
//coor fw['Z'], bw['Z'];
//
//void Tez()
//{
//   ios::sync_with_stdio(0);
//   cin.tie(0);
//   cout.tie(0);
//}
//
//void init() {
//    fw['L']={0,-1};
//    fw['R']={0, 1};
//    fw['U']={-1,0};
//    fw['D']={1, 0};
//
//    bw['L']={0, 1};
//    bw['R']={0,-1};
//    bw['U']={1, 0};
//    bw['D']={-1,0};
//}
//
//bool isValid(int y, int x) {
//    return (y>=0&&x>=0&&y<n&&x<m&&!isVisited[y][x]&&g[y][x]!='#');
//}
//
//void print() {
//    cout << endl << "YES" << endl;
//
//    string s="";
//    int i=destination.y, j=destination.x;
//    while(i!=start.y||j!=start.x) {
//        char dir = mdir[i][j];
//        s+=dir;
//        i+=bw[dir].y;
//        j+=bw[dir].x;
//    }
//    cout << s.length() << endl; 
//    reverse(s.begin(), s.end());
//    
//    cout << s << endl;
//}
//
//void findPath() {
//    queue<coor> q;
//    q.push(start);
//    while(!q.empty()) {
//        coor temp=q.front(); q.pop();
//        isVisited[temp.y][temp.x]=true;
//        for(int i=0; i<4; i++) {
//            coor muv=fw[direction[i]];
//            coor next={temp.y+muv.y, temp.x+muv.x};
//            if(isValid(next.y,next.x)) {
//                mdir[next.y][next.x]=direction[i];
//                if(g[next.y][next.x]=='B') {
//                    print();
//                    exit(0);
//                    //return;
//                }
//                q.push(next);
//            }
//        }
//    }
//    cout << "NO" << endl;
//}
//
//int main() {
//    Tez();
//    init();
//    cin >> n >> m;
//
//    for(int i=0; i<n; i++) {
//        for(int j=0; j<m; j++) {
//            mdir[i][j]='#';
//            cin >> g[i][j];
//            if(g[i][j]=='A') {
//                start.y=i;
//                start.x=j;
//            }
//            if(g[i][j]=='B') {
//                destination.y=i;
//                destination.x=j;
//            }
//        }
//    }
//
//    findPath();
//
//    return 0;
//}

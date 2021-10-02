#include<bits/stdc++.h>
using namespace std;

int p, c, v, cur;
char cmd;
deque<int> q;
int main() {
    while(cin >> p >> c) {
        if(p==0 && c==0) break;
        unordered_map<int, int> cnt;
        q.push_front(1);
        cur=1;
        while(c--) {
            cin >> cmd;
            if(cmd == 'N') {
                cout << q.front() << endl;
                int front = q.front();
                q.push_back(front);
                q.pop_front();
                cnt[front]++;

                while(cnt[q.front()]>1) {
                    cnt[q.front()]--;
                    q.pop_front();
                }
                
                if(front==cur && cur<p) {
                    q.push_front(++cur);
                }
            } else {
                cin >> v;
                q.push_front(v);
            }
        }
        q.clear();
    }
    return 0;
}

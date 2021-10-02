#include<bits/stdc++.h>
using namespace std;

int n;
int main() {
    do {
        cin >> n;
        if(n!=0) {
            queue<int> q1, q2;
            for(int i=1; i<=n; i++) {
                q1.push(i);
            }
            while(q1.size()>1) {
                int k = q1.front();
                q1.pop();
                int t = q1.front();
                q1.pop();

                q2.push(k);
                q1.push(t);
            }

            cout << "Discarded cards:";
            while(!q2.empty()) {
                cout << " " << q2.front();
                q2.pop();
                if(!q2.empty()) cout << ",";
            }
            cout << endl;
            cout << "Remaining card: " << q1.front() << endl;
        }
    } while(n!=0);

    return 0;
}

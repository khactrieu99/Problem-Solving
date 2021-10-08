#include <bits/stdc++.h>
using namespace std;

int n;
priority_queue<long long> heap;

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        int x; cin >> x;
        heap.push(x);

        if(heap.size()<3) cout << -1 << endl;
        else {
            long long a=heap.top(); heap.pop();
            long long b=heap.top(); heap.pop();
            long long c=heap.top(); heap.pop();
            
            cout << a*b*c << endl;
            
            heap.push(a);
            heap.push(b);
            heap.push(c);
        }
    }

    return 0;
}

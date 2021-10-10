#include <bits/stdc++.h>
using namespace std;

int q, cmd, val;
vector<int> heap;

void heapify(int i) {
    int n=heap.size();
    while(true) {
        int l=i*2;
        int r=i*2+1;
        int mini=i;
        
        if(l<n && heap[l]<heap[mini]) mini=l;
        if(r<n && heap[r]<heap[mini]) mini=r;
        
        if(mini==i) break;
        
        swap(heap[mini], heap[i]);
        i=mini;
    }
}

void push(int v) {
    heap.push_back(v);
    
    int pos=heap.size()-1;
    while(heap[pos]<heap[pos/2]) {
        swap(heap[pos], heap[pos/2]);
        pos/=2;
    }
}

int top() {
    return heap[0];
}

void pop(int v) {
    int pos, n=heap.size();
    
    for(int i=0; i<n; i++) {
        if(heap[i]==v) {
            pos=i;
            break;
        }
    }
    
    swap(heap[pos], heap[n-1]);
    heap.pop_back();
    
    heapify(pos);
}

int main() {
    cin >> q;
    while(q--) {
        cin >> cmd;
        switch(cmd) {
            case 1: 
                cin >> val;
                push(val);
                break;
            case 2:
                cin >> val;
                pop(val);
                break;
            case 3:
                cout << top() << endl;
                break;
        }
    }
    return 0;
}

    

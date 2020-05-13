//#include <bitset/stdc++.h>
#include <iostream> 
#include <map>
using namespace std;

#define FOR(i, a, b) for(int i=a; i<b; i++)

struct point {
    int x, y;
    point() {}
    point(int x, int y): x(x), y(y) {}
    point& operator-=(const point &p2) {
        point res;
        x -= p2.x;
        y -= p2.y;
        return *this;
    }
    bool operator!=(point p) {
        return (x!=p.x || y!=p.y);
    }
    bool operator<(point p) const{
        return (x<p.x || (x==p.x && y<p.y));
    }
    point& operator-(const point &p2) const {
        return point(*this) -= p2;
    }
};

int gcd(int a, int b) { 
    if (a == 0) return b; 
    if (b == 0) return a; 
    if (a == b) return a; 
    if (a > b) return gcd(a-b, b); 
    return gcd(a, b-a); 
} 
   
point normalizeVector(point vector) {
    point res;
    if(vector.x==0) {
        res.x = 0; 
        res.y = 1;
    }
    else if(vector.y==0) {
        res.x = 1;
        res.y = 0;
    }
    else {
        int lcd;
        if(vector.x < 0 && vector.y <0) lcd = gcd(-vector.x, -vector.y);
        else if(vector.x < 0) lcd = gcd(-vector.x, vector.y);
        else if(vector.y < 0) lcd = gcd(vector.x, -vector.y);
        else lcd = gcd(vector.x, vector.y);

        res.x = vector.x / lcd;
        res.y = vector.y / lcd;
    }
    return res;
}

int n;
point lazerGun;
map<point, int> directionVectors;

int main() {
    scanf("%d%d%d", &n, &lazerGun.x, &lazerGun.y);
    for(int i=0; i<n; ++i) {   
        point p;
		scanf("%d%d", &p.x, &p.y);
        if(p.y >= lazerGun.y)
            p -= lazerGun;
        else {
            p.x = lazerGun.x - p.x;
            p.y = lazerGun.y - p.y;
        }
        directionVectors.insert(std::pair<point,int>(normalizeVector(p), 0) );
    }

    cout << directionVectors.size() << endl;
    return 0;
}
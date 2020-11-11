#include <bits/stdc++.h>
using namespace std;

string s;
vector<string> res;

int main() {
    cin >> s;
    sort(s.begin(), s.end());

    do {
        res.push_back(s);
    } while (next_permutation(s.begin(), s.end()));

    sort(res.begin(), res.end());

    cout << res.size() << endl;
    for(auto item: res) {
        cout << item << endl;
    }

    return 0;
}
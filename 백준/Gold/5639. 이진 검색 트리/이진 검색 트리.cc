#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(NULL), ios_base::sync_with_stdio(false)

int n;
vector<int> v;

void f(int node, int en) {
    int rS = node + 1;
    while (rS <= en && v[node] > v[rS]) ++rS;
    int lS = node + 1;
    if (lS < rS) f(lS, rS - 1);
    if (rS <= en) f(rS, en);
    cout << v[node] << '\n';
}

int main() {
    fastio;
    while (cin >> n) v.push_back(n);
    f(0, v.size() - 1);
    return 0;
}

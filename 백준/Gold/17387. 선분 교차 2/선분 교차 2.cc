#include <bits/stdc++.h>

using namespace std;

typedef pair<long long int, long long int> pi;

vector<pi> p;

int ccw(pi p1, pi p2, pi p3) {
    long long int tmp = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;
    tmp -= (p2.first * p1.second + p3.first * p2.second + p1.first * p3.second);
    if (tmp > 0) return 1;
    else if (tmp < 0) return -1;
    return 0;
}

int check(pi a, pi b, pi c, pi d) {
    int abc = ccw(a, b, c);
    int abd = ccw(a, b, d);
    int cda = ccw(c, d, a);
    int cdb = ccw(c, d, b);
    if (abc * abd == 0 && cda * cdb == 0) {
        if (a > b) swap(a, b);
        if (c > d) swap(c, d);
        return a <= d && c <= b;
    }
    return abc * abd <= 0 && cda * cdb <= 0;
}

int main() {
    int x, y, res;
    for (int i = 0; i < 4; i++) {
        cin >> x >> y;
        p.push_back({x, y});
    }
    if (check(p[0], p[1], p[2], p[3])) cout << "1";
    else cout << "0";
    return 0;
}

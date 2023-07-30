#include <bits/stdc++.h>

using namespace std;

#define MAX 3002

using pi = pair<int, int>;

int n, root[MAX], member[MAX], cnt, res;
pi a[MAX], b[MAX];

int find(int x) {
    if (root[x] == x) return x;
    return root[x] = find(root[x]);
}

void merge(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return;
    root[b] = a;
    member[a] += member[b];
    member[b] = 0;
}

int ccw(pi a, pi b, pi c) {
    int tmp = a.first * b.second + b.first * c.second + c.first * a.second;
    tmp -= (b.first * a.second + c.first * b.second + a.first * c.second);
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
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second >> b[i].first >> b[i].second;
        root[i] = i;
        member[i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++)
            if (check(a[i], b[i], a[j], b[j]))
                merge(i, j);
    }
    for (int i = 1; i <= n; i++) {
        if (member[i]) cnt++;
        res = max(res, member[i]);
    }
    cout << cnt << '\n' << res;
    return 0;
}

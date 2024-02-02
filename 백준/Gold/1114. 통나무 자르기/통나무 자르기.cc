#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(false);

int l, k, c, maxL, minP, t;
vector<int> cPoint;

int CHK(int cur) {
    int sum, cut;
    sum = cut = t = 0;
    for (int i = k; i >= 0; i--) {
        int diff = cPoint[i + 1] - cPoint[i];
        if (sum + diff > cur) {
            cut++, sum = diff;
            if (sum > cur) return 0;
            t = i + 1;
        } else sum += diff;
    }
    if (cut < c) t = 1;
    return cut <= c;
}

int main() {
    fastio;
    cin >> l >> k >> c;
    cPoint.resize(k + 2);
    cPoint[0] = 0, cPoint[k + 1] = l;
    for (int i = 1; i <= k; i++) cin >> cPoint[i];
    sort(cPoint.begin(), cPoint.end());
    int st = 1, en = l;
    while (st <= en) {
        int mid = (st + en) / 2;
        if (CHK(mid)) {
            maxL = mid;
            minP = t;
            en = mid - 1;
        } else st = mid + 1;
    }
    cout << maxL << ' ' << cPoint[minP];
    return 0;
}

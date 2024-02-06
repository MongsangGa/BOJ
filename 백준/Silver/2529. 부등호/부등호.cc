#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(false);

int n;
char s[10];
vector<int> minV, maxV;

bool Check(vector<int> &v) {
    for (int i = 0; i < n; i++) {
        if (s[i] == '>' && v[i] <= v[i + 1]) return false;
        if (s[i] == '<' && v[i] >= v[i + 1]) return false;
    }
    return true;
}

int main() {
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < 10; i++) {
        minV.push_back(i);
        maxV.push_back(9 - i);
    }
    do {
        if (Check(maxV)) {
            for (int i = 0; i < n + 1; i++) cout << maxV[i];
            cout << '\n';
            break;
        }
    } while (prev_permutation(maxV.begin(), maxV.end()));
    do {
        if (Check(minV)) {
            for (int i = 0; i < n + 1; i++) cout << minV[i];
            break;
        }
    } while (next_permutation(minV.begin(), minV.end()));

    return 0;
}

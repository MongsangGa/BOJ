#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 1002

int truck[SIZE], curW, curT, sec;
queue<int> q;

int main() {
    fastio;
    int n, l, w;
    cin >> n >> l >> w;
    for (int i = 0; i < n; i++)
        cin >> truck[i];
    for (int i = 0; i < n; i++) {
        while (1) {
            if (q.size() >= l)
                curW -= q.front(), q.pop();
            if (curW + truck[i] <= w)
                break;
            q.push(0);
            ++sec;
        }
        q.push(truck[i]);
        curW += truck[i];
        ++sec;
    }
    cout << sec + l;
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(false);
#define INF 1e9
#define SIZE 1002

int n, m[SIZE];
deque<int> balloon;
vector<int> res;

int main() {
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> m[i];
    for (int i = 0; i < n; i++) balloon.push_back(i + 1);
    for (int i = 0; i < n; i++) {
        res.push_back(balloon.front());
        int move = m[balloon.front() - 1];
        balloon.pop_front();
        if (move > 0)
            for (int j = 0; j < move - 1; j++)
                balloon.push_back(balloon.front()), balloon.pop_front();
        else
            for (int j = 0; j < -move; j++)
                balloon.push_front(balloon.back()), balloon.pop_back();
    }
    for (auto i: res) cout << i << ' ';
    return 0;
}

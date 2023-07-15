#include<bits/stdc++.h>

using namespace std;

int N, K, res;
vector<int> order, running;
bool is_used[101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    order.resize(K);
    for (int i = 0; i < K; i++) cin >> order[i];
    for (int i = 0; i < K; i++) {
        int target = order[i];
        if (is_used[target]) continue;
        if (running.size() < N) {
            is_used[target] = true;
            running.push_back(target);
            continue;
        }
        // change
        int t = 0, victim = 999;
        for (int j = 0; j < running.size(); j++) {
            int future = 999;
            for (int k = i + 1; k < K; k++) {
                if (running[j] == order[k]) {
                    future = k;
                    break;
                }
            }
            if (future > t)
                t = future, victim = j;
        }
        int change_num = running[victim];
        is_used[change_num] = false;
        running[victim] = target;
        is_used[target] = true;
        res++;
    }
    cout << res;
    return 0;
}

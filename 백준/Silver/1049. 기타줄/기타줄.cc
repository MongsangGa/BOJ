#include<bits/stdc++.h>

using namespace std;

int N, M, S = 9999999, O = 9999999, res = 9999999;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int set, one;
        cin >> set >> one;
        S = min(S, set);
        O = min(O, one);
    }
    res = min(res, O * N);
    res = min(res, S * (N / 6 + 1));
    res = min(res, S * (N / 6) + O * (N % 6));
    cout << res;
    return 0;
}

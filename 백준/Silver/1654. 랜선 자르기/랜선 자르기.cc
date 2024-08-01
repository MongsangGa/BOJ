#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define ll long long
int k, n;
ll res;
vector<int> v;

int main() {
    fastio;
    cin >> k >> n;
    v.resize(k);
    for (int i = 0; i < k; i++) cin >> v[i];
    sort(v.begin(), v.end());
    ll s = 1, e = v[k - 1], mid;
    while (s <= e) {
        mid = (s + e) / 2;
        int cnt = 0;
        for (auto i: v) cnt += i / mid;
        if (cnt >= n) res = max(res, mid), s = mid + 1;
        else e = mid - 1;
    }
    cout << res;
    return 0;
}

/*
 * 단순 구현의 시간복잡도를 대략 예상해보면 O(N * K * 최대 랜선크기(2^31)) 쯤이다
 * 반드시 개선해야 한다는 걸 알 수 있는데 N 개 이상 만들 수 있는 랜선 값을
 * 이분 탐색을 활용하면 O(NlgN) 에 해결할 수 있다
 * 위와 같은 이분탐색 결정 문제를 Parametric Search 라고 하니 더 찾아보셔도 좋습니다
 */

#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

int t, n;
long long res;
vector<int> v;

int main() {
    fastio;
    cin >> t;
    while (t--) {
        cin >> n;
        res = 0, v.resize(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        int maxP = v[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (maxP < v[i]) maxP = v[i];
            else res += maxP - v[i];
        }
        cout << res << '\n';
    }
    return 0;
}

/* 이 문제의 핵심은 '아무것도 안하는 행동과 원하는 만큼 주식을 팔 수 있는 것이다'
 * 두 문장을 보자마자 마지막 날부터 처리해야한다는 것을 몸으로 느껴야 한다
 * 마지막 날부터 최고값을 기록 한 뒤 최고값이 갱신되면 이전의 주식들을 팔면 된다
 * 그리고 마지막 출력 항에 보면 부호있는 64bit 정수형 long long 을 사용하라고 친절히 안내되어있다
 */

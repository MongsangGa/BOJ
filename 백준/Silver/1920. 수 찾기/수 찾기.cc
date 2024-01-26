#include<bits/stdc++.h>

using namespace std;

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define SIZE 100'001
int n, m, a[SIZE], target, l, r, mid;

int main() {
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    cin >> m;
    while (m--) {
        cin >> target;
        l = 0, r = n - 1;
        bool check = false; // 찾은지 못찾은지 확인
        while (l <= r) {
            mid = (l + r) / 2;
            // a[mid] : 현재 값
            // target : 찾고자 하는 값
            if (a[mid] == target) { // 찾았다!
                check = true;
                break;
            } else if (a[mid] > target) r = mid - 1; // 현재 위치가 찾고자 하는 수보다 크면, 오른쪽을 줄인다
            else if (a[mid] < target) l = mid + 1; // 현재 위치가 찾고자 하는 수보다 작으면, 왼쪽을 늘린다
        }
        if (check == true) cout << "1\n";
        else cout << "0\n";
    }
    return 0;
}

#include<bits/stdc++.h>

using namespace std;

long long int n, sum, MAX, dice[6], arr[3], one, two, three, res;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    /*
     *  n=2, 3개 면 : 4, 2개 면 : 4
     *  n=3, 3개 면 : 4, 2개 면 : 12, 1개 면 : 9
     *  3개 면 : 4, 2개 면 : 4*(n-1)+4*(n-2) , 1개 면 : 4*(n-2)*(n-1)+(n-2)*(n-2)
     *  마주보는 면을 기준으로 3개를 뽑자
     */
    cin >> n;
    for (int i = 0; i < 6; i++) {
        cin >> dice[i];
        sum += dice[i];
        MAX = max(MAX, dice[i]);
    }
    if (n == 1)
        cout << sum - MAX;
    else {
        arr[0] = min(dice[0], dice[5]);
        arr[1] = min(dice[1], dice[4]);
        arr[2] = min(dice[2], dice[3]);
        sort(arr, arr + 3);
        one = arr[0], two = one + arr[1], three = two + arr[2];
        res = (three * 4) + two * (4 * (n - 1) + 4 * (n - 2)) + one * (4 * (n - 2) * (n - 1) + (n - 2) * (n - 2));
        cout << res;
    }
    return 0;
}

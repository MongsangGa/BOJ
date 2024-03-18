#include <iostream>

using namespace std;

#define SIZE 102
#define INF 1000000007
int N, L, R;
long long dp[SIZE][SIZE][SIZE];

int main() {
    cin >> N >> L >> R;
    dp[1][1][1] = 1;
    for (int i = 2; i <= N; i++)
        for (int l = 1; l <= N; l++)
            for (int r = 1; r <= N; r++)
                dp[i][l][r] = (dp[i - 1][l - 1][r] + dp[i - 1][l][r - 1] + dp[i - 1][l][r] * (i - 2)) % INF;
    cout << dp[N][L][R];
    return 0;
}

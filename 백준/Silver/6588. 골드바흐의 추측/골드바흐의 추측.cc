#include <bits/stdc++.h>

using namespace std;

#define MAX 1'000'001

int n, prime[MAX];

void make_prime() {
    for (int i = 2; i <= sqrt(MAX); i++) {
        if (prime[i]) continue;
        for (int j = i * i; j <= MAX; j += i)
            prime[j] = 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    //fill(prime, prime + MAX, 0);
    make_prime();
    while (1) {
        cin >> n;
        if (!n) break;
        int start = 2;
        while (1) {
            if (!prime[start] && !prime[n - start]) {
                cout << n << " = " << start << " + " << n - start << '\n';
                break;
            }
            start++;
        }
    }
}

#include<bits/stdc++.h>

using namespace std;
#define MAX 1'000'000'001
long long int x, y, block, cross, cost1, cost2, cost3;

int main() {
    cin >> x >> y >> block >> cross;
    if (x < y) swap(x, y);
    cost1 = (x + y) * block;
    if ((x + y) % 2 == 0) cost2 = x * cross;
    else cost2 = ((x - 1) * cross) + block;
    cost3 = (y * cross) + ((x - y) * block);
    cout << min(min(cost1, cost2), cost3);
    return 0;
}


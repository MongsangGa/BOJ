#include <bits/stdc++.h>

using namespace std;

int X1, X2, X3, Y1, Y2, Y3;

int main() {
    cin >> X1 >> Y1 >> X2 >> Y2 >> X3 >> Y3;
    int tmp = (X2 - X1) * (Y3 - Y1) - (Y2 - Y1) * (X3 - X1);
    if (tmp > 0) cout << "1";
    else if (tmp < 0) cout << "-1";
    else cout << "0";
    return 0;
}

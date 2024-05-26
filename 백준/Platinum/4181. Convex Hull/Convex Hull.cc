#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

using pii = pair<int, int>;

int CCW(pii a, pii b, pii c) {
	auto res = 1L * (b.first - a.first) * (c.second - a.second)
		- 1L * (c.first - a.first) * (b.second - a.second);
	return res ? res > 0 ? 1 : -1 : 0;
}

auto D(pii a, pii b) {
	return 1L * (a.first - b.first) * (a.first - b.first)
		+ 1L * (a.second - b.second) * (a.second - b.second);
}

int main() {
	fastio;
	int n; cin >> n;
	vector v(0, pii());
	while (n--) {
		int a, b; char c; cin >> a >> b >> c;
		if (c == 'Y') v.push_back({ a, b });
	}
	
	n = v.size();
	for (int i = 1; i < n; i++) if (v[0] > v[i]) swap(v[0], v[i]);
	sort(v.begin() + 1, v.end(), [&](pii a, pii b) {
		int res = CCW(v[0], a, b);
		if (res) return res > 0;
		return D(v[0], a) < D(v[0], b);
	});
	
	int r = n - 1;
	while (r > 1 && !CCW(v[0], v[r], v[r - 1])) r--;
	reverse(v.begin() + r, v.end());
	
	cout << n << '\n';
	for (auto [a, b] : v) cout << a << ' ' << b << '\n';
}
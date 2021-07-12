#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/numeric>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef pair<int, int> pii;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int N = 1e5 + 5;

int n;
int a[N], b[N], c[N];

int main() {
	std::ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n; i++)
			cin >> b[i];
		for (int i = 0; i < n; i++)
			cin >> c[i];
		if (n == 1) {
			if (b[0] == 100) {
				cout << "-1\n";
			} else {
				cout << max(0LL, b[0] + 1LL - a[0]) * c[0] << "\n";
			}
		} else if (n == 2) {
			if (b[0] == 100 && b[1] == 100) {
				cout << "-1\n";
				continue;
			}
			ll res = max(50LL - a[0], 0LL) * c[0];
			res += max(50LL - a[1], 0LL) * c[1];
			a[0] = max(a[0], 50);
			a[1] = max(a[1], 50);
			if (a[0] <= b[0] && a[1] <= b[1]) {
				ll v0 = 1e18, v1 = 1e18;
				if (b[0] < 100) {
					v0 = (b[0] + 1LL - a[0]) * c[0];
				}
				if (b[1] < 100) {
					v1 = (b[1] + 1LL - a[1]) * c[1];
				}
				res += min(v0, v1);
			}
			cout << res << "\n";
		} else {
			cout << "-1\n";
		}
	}
	return 0;
}

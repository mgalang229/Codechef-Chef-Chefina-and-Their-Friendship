#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;
const long long INF = 1e18;
const long long P = 31;

vector<long long> h(1e5 + 5);
vector<long long> powers(1e5 + 5);

void init(string s) {
	long long n = s.size();
	powers[0] = 1;
	for(int i = 0; i < n; i++) {
		if(i > 0) {
			powers[i] = (powers[i-1] * P) % MOD;
		}
		h[i] = (i == 0 ? 0 : h[i-1]);
		h[i] = (h[i] + (powers[i] * (s[i] - 'a' + 1)) % MOD) % MOD;
	}
}

long long get_hash(long long l, long long r) {
	return (l == 0 ? h[r] : ((h[r] - h[l-1]) % MOD + MOD) % MOD);
}

void test_case() {
	string s;
	cin >> s;
	init(s);
	int n = (int) s.size();
	int ans = 0;
	for(int i = 1; i <= n - 2; i += 2) {
		int l1 = 0;
		int r1 = i / 2;
		
		int l2 = i / 2 + 1;
		int r2 = i;
		
		int l3 = i + 1;
		int r3 = (i + n) / 2;
		
		int l4 = (i + n) / 2 + 1;
		int r4 = n - 1;
		
		long long v1 = (get_hash(l1, r1) * powers[l2-l1]) % MOD;
		long long v2 = get_hash(l2, r2);
		long long v3 = (get_hash(l3, r3) * powers[l4-l3]) % MOD;
		long long v4 = get_hash(l4, r4);
		
		if(v1 == v2 && v3 == v4) {
			ans++;
		}
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc = 1;
	cin >> tc;
	for(int t = 0; t < tc; t++) {
		test_case();
	}
	return 0;
}


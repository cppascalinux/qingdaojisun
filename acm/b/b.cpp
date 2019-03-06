#include<cstdio>
#include<tr1/unordered_map>

typedef long long ll;
const int maxn = 1007;

int n, a[maxn];
ll ans;
std::tr1::unordered_map<ll, bool> vis;

ll Check(int x) {
	for (register ll i = (x - 1) * 10ll; i < x * 10ll; i++) {
		if (!vis[i]) {
			return i;
		}
	}
	return -1;
}

int main() {
	scanf("%d", &n);
	for (register int i = 1; i <= n; i++) {
		scanf("%d", a + i);
	}
	for (register int i = 1; ; i++) {
		for (register int j = 1; j + i - 1 <= n; j++) {
			ll now = 0;
			for (register int k = 1; k <= i; k++) {
				now = now * 10 + a[j + k - 1];
			}
			vis[now] = 1;
		}
		ans = Check(i);
		if (ans != -1) {
			printf("%lld\n", ans);
			return 0;
		}	
	}
}
#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 2e5 + 3;
const int INF = 0x3f3f3f3f;
const int MOD = 1e7 + 9;

int a, b, k;
//int k;
//int a[MXN];
//int b[MXN];
//string s;

int n_primes(int num)
{
    int ans = 0;
    for(int i = 2; i * i <= num; ++i) {
        while(num % i == 0) {
            ans++;
            num /= i;
        }
    }

    ans += (int)(num > 1);

    return ans;
}
 
void solve()
{
    if(b > a) {
        swap(a, b);
    }

    if(k > n_primes(a) + n_primes(b)) {
        cout << "NO\n";
        return;
    }

    if(k == 1) {
        if(a % b == 0 && a != b) { 
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        return;
    }

    cout << "YES\n";

}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        cin >> a >> b >> k;
        solve();
    }
}

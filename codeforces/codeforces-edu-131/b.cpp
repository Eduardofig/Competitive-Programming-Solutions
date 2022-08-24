#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 2e5 + 3;
const int INF = 0x3f3f3f3f;

int n;
int spf[MXN];

void sieve()
{
    spf[1] = 1;
    for(int i = 2; i < MXN; ++i) {
        spf[i] = i;
    }

    for(int i = 4; i < MXN; i += 2) {
        spf[i] = 2;
    }

    for(int i = 3; i * i < MXN; ++i) {
        //i is prime
        if(spf[i] == i) {
            for(int j = i * i; j < MXN; j += i) {
                if(spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
}

vector<int> factorize(int x)
{
    vector<int> factors;
    while(x != 1) {
        factors.push_back(spf[x]);
        x /= spf[x];
    }

    return factors;
}
 
void solve()
{
    int cnt[n + 1];
    memset(cnt, 0, sizeof cnt);

    for(int i = 2; i <= n; ++i) {
        for(int fact: factorize(i)) {
            cnt[fact]++;
        }
    }

    int d = max_element(cnt, cnt + n + 1) - cnt;
    cout << d << '\n';
    bool used[n + 1];
    memset(used, false, sizeof used);
    for(int i = 1; i <= n; ++i) {
        if(!used[i]) {
            used[i] = true;
            cout << i << " ";
            int tmp = i;
            while(tmp * d <= n) {
                used[tmp * d] = true;
                cout << tmp * d << ' ';
                tmp *= d;
            }
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    sieve();
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        solve();
    }
}

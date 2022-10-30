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

int n;
//int k;
//int a[MXN];
//int b[MXN];
string s;
int cnt[28];


void solve()
{
    for(char c: s) {
        cnt[c - 'A']++;
    }

    int odd_c = -1;
    for(int i = 0; i < 26; ++i) {
        if(cnt[i] % 2 > 0) {
            if(odd_c == -1) {
                odd_c = i;
            } else {
                cout << "NO SOLUTION\n";
                return;
            }
        }
    }

    n = s.size();

    if(n % 2 == 0) {
        if(odd_c != -1) {
            cout << "NO SOLUTION\n";
            return;
        }
    } else {
        if(odd_c == -1) {
            cout << "NO SOLUTION\n";
            return;
        }
    }

    string ans;
    ans.resize(n, '*');

    int c = 0;

    for(int i = 0; i < n / 2; ++i) {
        while(cnt[c] <= 1) {
            c++;
        }

        cnt[c] -= 2;
        ans[i] = c + 'A';
        ans[n - 1 - i] = c + 'A';
    }

    if(n % 2 > 0) {
        ans[n / 2] = odd_c + 'A';
    }

    cout << ans << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> s;
    solve();
}

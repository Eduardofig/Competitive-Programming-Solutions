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

int k;
//int a[MXN];
//int b[MXN];
string s;
int cnt[28] = {0};
 
void solve()
{
    for(char c: s) {
        cnt[c - 'a']++;
    }

    for(int i = 0; i < 28; ++i) {
        if(k > s.size() || cnt[i] % k != 0) {
            cout << "-1\n";
            return;
        }
    }

    for(int i = 0; i < k; ++i) {
        for(int j = 0; j < 26; ++j) {
            if(cnt[j] > 0) {
                for(int l = 0; l < cnt[j] / k; ++l) {
                    cout << (char)('a' + j);
                }
            }
        }
    }
    cout << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> k >> s;
    solve();
}

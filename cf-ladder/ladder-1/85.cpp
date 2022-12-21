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
 
void solve()
{
    int cnt = count_if(s.begin(), s.end(), [](char c) {
            return c % 2 == 1;
            });

    if(cnt <= 1) {
        cout << "-1";
    } else {
        int cnt = 0;

        for(char c: s) {
            if(cnt == 2) {
                cout << '\n';
                return;
            }

            if((c - '0') % 2 == 1) {
                cout << c;
                cnt++;
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

    int t;
    cin >> t;
    while(t--) {
        cin >> n >> s;
        solve();
    }
}

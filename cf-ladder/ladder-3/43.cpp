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
    string rgb = "RGB";
    string rbg = "RBG";

    string arr[6];

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < 3; ++j) {
            arr[j].push_back(rgb[(i + j) % 3]);
            arr[j + 3].push_back(rbg[(i + j) % 3]);
        }
    }

    int best = INF;
    int ans = -1;

    for(int j = 0; j < 6; ++j) {
        //cout << arr[j] << '\n';
        int tot = 0;
        for(int i = 0; i < n; ++i) {
            if(arr[j][i] != s[i]) {
                tot++;
            }
        }

        if(tot < best) {
            best = tot;
            ans = j;
        }
    }
    cout << best << '\n' << arr[ans] << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n >> s;
    solve();
}

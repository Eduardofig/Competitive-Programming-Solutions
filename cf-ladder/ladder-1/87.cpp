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

int n, m;
//int k;
//int a[MXN];
//int b[MXN];
//string s;
 
void solve()
{
    map<string, string> names;

    for(int i = 0; i < n; ++i) {
        string name, server;
        cin >> name >> server;

        names[server + ";"] = name;
    }


    for(int i = 0; i < m; ++i) {
        string command, server;

        cin >> command >> server;

        cout << command << ' ' << server << " #" << names[server] << '\n';
    }

}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n >> m;
    solve();
}

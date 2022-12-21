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
//string s;

string from, to;
 
void solve()
{
    int distx = to.front() - from.front();
    int disty = to.back() - from.back();

    vector<string> vans;
    while(!(distx == 0 && disty == 0)) {
        string ans = "";
        if(distx > 0) {
            ans += 'R';
            distx--;
        } else if(distx < 0) {
            ans += 'L';
            distx++;
        }

        if(disty > 0) {
            ans += 'U';
            disty--;
        } else if(disty < 0) {
            ans += 'D';
            disty++;
        }

        vans.push_back(ans);
    }

    cout << vans.size() << '\n';

    for(string s: vans) {
        cout << s << '\n';
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> from >> to;
    solve();
}

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
//int arr[MXN];
string s;
 
void solve()
{
    bool first = true;
    int end, begin;
    for(int i = 1; i < n; ++i) {
        if(!first && s[i] != s[i - 1]) {
            if(s[i] == 'L') {
                end = i - 1;
            } else {
                end = i;
            }
            cout << begin + 1 << ' ' << end + 1 << '\n';
            return;
        }

        if(first && s[i] != '.') {
            first = false;
            begin = i;
        }

    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    cin >> s;
    solve();
}

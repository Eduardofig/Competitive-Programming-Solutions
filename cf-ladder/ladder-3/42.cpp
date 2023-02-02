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
    for(char &c: s) {
        c -= '0';
    }

    vector<int> v(s.begin(), s.end());

    if(accumulate(v.begin(), v.end(), 0) == 0) {
        cout << "YES\n";
        return;
    }

    int pref[n + 1];


    for(int sum = 1; sum < accumulate(v.begin(), v.end(), 0); ++sum) {
        int curr = 0;
        for(int i: v) {

            if(i == 0) {
                continue;
            }

            if(curr == sum) {
                curr = 0;
            }
            
            if(curr + i > sum) {
                break;
            }

            curr += i;
        }

        if(curr == sum) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n >> s;
    solve();
}

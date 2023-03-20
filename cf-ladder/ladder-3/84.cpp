#include <algorithm>
#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 2e5 + 3;
const int INF = 0x3f3f3f3f;

const bool MULTIPLE_TESTCASES = 1;

int n;
int a[MXN];
//int b[MXN];
//string s;

void solve()
{
    int i = 0;
    while(i < n) {
        int next = min_element(a + i, a + n) - a;
        if(next == i) {
            i++;
        } else {
            for(int j = next; j > i; j--) {
                swap(a[j], a[j - 1]);
            }
            i = next;
        }
    }

    for(int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    cout << '\n';
}

void read()
{
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    if(MULTIPLE_TESTCASES) {
        int t;
        cin >> t;
        while(t--) {
            read();
            solve();
        }
    } else {
        read();
        solve();
    }
}

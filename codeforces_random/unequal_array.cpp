#include <bits/stdc++.h>

using namespace std;

// 112334990

void solve()
{
    int n, prev;
    cin >> n;
    int arr[n];
    bool ok = false;

    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
        ok = ok || arr[i] == prev;
        prev = arr[i];
    }

    if(!ok || n <= 2) {
        cout << 0 << endl;
        return;
    }

    int i, j;

    for(i = 0; arr[i] != arr[i + 1]; ++i){}
    for(j = n - 1; arr[j] != arr[j - 1]; --j){}

    if(abs(j - i) == 1) {
        cout << 0 << endl;
        return;
    }

    cout << max(j - i - 2, 1) << endl;

}

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i) {
        solve();
    }
}

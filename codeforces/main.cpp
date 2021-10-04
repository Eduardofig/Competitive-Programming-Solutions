#include <bits/stdc++.h>

using namespace std;

const int MXN = 1e5, INF = 0x3f3f3f;
int arr[MXN], max_sum = -INF, len;

int solve_rec(int st, int e)
{
    if(st == e) return arr[e];

    int n = (st + e), curr1, best1, curr2, best2;

    curr1 = curr2 = 0;
    best1 = best2 = -INF;

    for(int i = (n - 1)/2; i >= st; --i) {
        curr1 += arr[i];
        best1 = max(best1, curr1);
    }

    for(int j = (n - 1)/2 + 1; j < e; ++j) {
        curr2 += arr[j];
        best2 = max(best2, curr2);
    }

    int ans = max({solve_rec(st, (n - 1)/2), solve_rec((n - 1)/2 + 1, e), best1 + best2});

    if(n == len) max_sum = max(max_sum, ans);
    return ans;
}

int main()
{
    int n;
    cin >> n >> len;

    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    solve_rec(0, n);

    cout << max_sum << endl;
}

#include <iostream>
using namespace std;

const int MXN = 5e5;
long long a[MXN], b[MXN], res;

void merge(int st, int m, int e) {
    int i, j, k = 0;

    for (i = st, j = m + 1; i <= m && j <= e; k++) {
        if (a[i] <= a[j])
            b[k] = a[i++];
        else {
            b[k] = a[j++];
            res += m + 1 - i;
        }
    }

    for (; i <= m; i++)
        b[k++] = a[i];

    for (; j <= e; j++)
        b[k++] = a[j];

    for (i = 0; i < k; i++)
        a[st + i] = b[i];
}

void solve_rec(long st, long e) {
    if (st >= e)
        return;

    long m = (st + e)/2;

    solve_rec(st, m);
    solve_rec(m + 1, e);

    merge(st, m, e);
}

int main()
{
    long n, i;

    while (cin >> n) {
        res = 0;

        for (i = 0; i < n; i++)
            cin >> a[i];

        solve_rec(0, n - 1);
        if(n > 0) cout << res << endl;
    }
}


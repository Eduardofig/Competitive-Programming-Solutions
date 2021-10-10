#include <bits/stdc++.h>

using namespace std;

const int MXN = 1e5, INF = 0x3f3f3f3f;
int arr[MXN], n, ans = -INF;

void merge(int st, int e)
{
    int mid = (st + e)/2, curr_min = arr[mid], min_left , min_right,
    best_left, best_right, sum, best_min_left, best_i, best_j, best_min_right;

    min_left = min_right = curr_min = arr[mid];
    best_left = best_right = -INF;

    for(int i = mid; i >= st; --i) {
        curr_min = min(curr_min, arr[i]);
        min_left = min(min_left, arr[i]);
        sum = min_left*(mid - i + 1);
        if(sum > best_left) {
            best_left = sum;
            best_min_left = min_left;
            best_i = i;
        }
    }

    for(int j = mid; j <= e; ++j) {
        curr_min = min(curr_min, arr[j]);
        min_right = min(min_right, arr[j]);
        sum = min_right*(j - mid + 1);
        if(sum > best_right) {
            best_right = sum;
            best_min_right = min_right;
            best_j = j;
        }
    }

    ans = max({ans, (best_j - best_i + 1)*min(best_min_right, best_min_left), (best_j - mid + 1)*best_min_right, (mid - best_i + 1)*best_min_left});
}

void solve(int st, int e)
{
    if(st > e) return;

    if(st == e) {
        ans = max(ans, arr[st]);
        return;
    }

    int mid = (st + e)/2;

    solve(st, mid);
    solve(mid + 1, e);

    merge(st, e);
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> arr[i];

    solve(0, n - 1);

    cout << ans << endl;
}

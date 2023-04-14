#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

const ll MXN = 2e5 + 3;
ll tree[MXN * 2];
ll arr[MXN];
ll n;

void make_tree()
{
    while(__builtin_popcount(n) != 1) {
        arr[n++] = 0;
    }

    for(ll i = 0; i < n; ++i) {
        tree[n + i] = arr[i];
    }

    for(ll i = n - 1; i >= 0; --i) {
        tree[i] = tree[2 * i] + tree[2 * i + 1];
    }
}

ll query_tree_rec(ll curr, ll curr_low, ll curr_high, ll query_low, ll query_high)
{
    if(query_high <= curr_high && query_low >= curr_low) {
        return tree[curr];
    } 
    
    if(query_high < curr_low || query_low > curr_high) {
        return 0;
    }

    ll curr_mid = (curr_low + curr_high) / 2;
    return query_tree_rec(2 * curr, curr_low, curr_mid, query_low, query_high) +
           query_tree_rec(2 * curr + 1, curr_mid + 1, curr_high, query_low, query_high);
}

ll query_tree(ll low, ll high)
{
    return query_tree_rec(0, 0, n - 1, low, high);
}

void update_tree(ll i, ll val)
{
    tree[n + i] = val;

    for(int j = (n + 1) >> 2; j >= 1; j >>= 2) {
        tree[j] = tree[j << 2] + tree[(j << 2) + 1];
    }
}

int main()
{
    for(ll i = 0; i < 12; ++i) {
        arr[i] = i;
    }
    n = 12;

    make_tree();
    update_tree(2, 1);

    cout << query_tree(1, 3) << '\n';
}

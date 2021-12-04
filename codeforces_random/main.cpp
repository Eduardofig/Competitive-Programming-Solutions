#include <bits/stdc++.h>

using namespace std;

int n;
string s;

void solve()
{
    vector<int> nums(3, -n/6);
    vector<int> sum_nums = {min(2, n % 3), (int)(n % 3 > 0), (int)(n % 3 > 1)};

    for(char c: s) nums[c - 'A']++;

    transform(nums.begin(), nums.end(), sum_nums.begin(), nums.begin(), plus<int>());

    if(accumulate(nums.begin(), nums.begin() + (n % 3), 0) > 0) cout << "Yes";
    else cout << "No";
}

int main()
{
    cin >> n >> s;
    solve();
}

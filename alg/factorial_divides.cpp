#include <bits/stdc++.h>

using namespace std;

const unsigned long long MXN = 1 << 19;
bitset<MXN> sieve;
vector<unsigned long long> primes;

void fill_sieve()
{
    sieve.set();

    for(unsigned long long i = 2; i < MXN; ++i) if(sieve[i]) {
        primes.push_back(i);

        for(unsigned long long j = 2*i; j < MXN; j += i)
            sieve[j] = false;
    }
}

map<unsigned long long, int> factor(unsigned long long num)
{
    map<unsigned long long, int> factors;

    for(unsigned long long prime: primes) {
        if(num <= 1 || prime >= (unsigned long long)(sqrt(num) + 1)) break;

        while(!(num % prime)) {
            factors[prime]++;
            num /= prime;
        }
    }

    if(sqrt(num) + 1 >= MXN) {
        for(unsigned long long i = MXN; i <= (unsigned long long)(sqrt(num) + 1); ++i) while(!(num % i)) {
            factors[i]++;
            num /= i;
        }
    }            


    if(num != 1 || factors.empty()) factors[num]++;

    return factors;
}

int get_pow(unsigned long long num, unsigned long long factor) {
    int res = 0;

    for(unsigned long long power = factor; power <= num; power *= factor)
        res += num / power;

    return res;
}

void solve(unsigned long long num, unsigned long long divisor)
{
    map<unsigned long long, int> factors = factor(divisor);

    if(num >= divisor || (num == 0 && divisor == 1)) {
        cout << divisor << " divides " << num << "!" << endl;
        return;
    }

    for(auto [factor, n_pow]: factors) if(n_pow > get_pow(num, factor)) {
        cout << divisor << " does not divide " << num << "!" << endl;
        return;
    }


    cout << divisor << " divides " << num << "!" << endl;
}

int main()
{
    int num, divisor;

    fill_sieve();

    while(cin >> num >> divisor) 
        solve(num, divisor);
}

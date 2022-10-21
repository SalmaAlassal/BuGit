#include <bits/stdc++.h>
using namespace std;
/*
 * This code is designed to print all the prime factors of a number
 * as if the input is 210
 * the output should be
 * 2
 * 3
 * 5
 * 7
 * fix the code bugs to make it work properly.
 * */
vector<int> prime_fact(int n) {
    vector<int> primes;
    bool ok = false;
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            ok = 1;
            n /= i;
        }
        if (ok)
            primes.push_back(i);
        ok = 0;
    }
    return primes;
}

void main() {
    int n;
    cin >> n;
    auto res = prime_fact(n);
    for (auto x: res)cout << x << '\n';
    return 0;
}


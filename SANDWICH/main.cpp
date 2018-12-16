/*input
2
7 3 500
10 2 1000
*/

//
//  main.cpp
//  SANDWICH
//
//  Created by Nirmaljot Singh Bhasin on 29/12/17.
//  Copyright © 2017 Nirmaljot Singh Bhasin. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include <memory.h>
using namespace std;

typedef long long int lli;
const int MAXN = 1000006;

bool is_prime[MAXN];
lli spf[MAXN];
lli arr[MAXN], tot[MAXN];
vector<lli> primes;

void sieve() {
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < MAXN; ++i) {
        if (is_prime[i]) {
            primes.push_back(i);
            spf[i] = i;
        }
        for (int j = 0; j < primes.size() && i * primes[j] < MAXN && primes[j] <= spf[i]; ++j) {
            is_prime[i * primes[j]] = false;
            spf[i * primes[j]] = primes[j];
        }
    }
}

map<lli, lli> factorization(lli n) {
    map<lli, lli> m;
    while (n > 1) {
        if (m.count(spf[n])) {
            ++m[spf[n]];
        } else {
            m[spf[n]] = 1;
        }
        n /= spf[n];
    }
    return m;
}

lli power(lli a, lli n) {
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return a;
    }
    lli p = power(a, n >> 1);
    if (n & 1) {
        return p * a * p;
    } else {
        return p * p;
    }
}

lli power(lli a, lli n, lli m) {
    lli ret = 1;
    a = a % m;
    while (n > 0) {
        if (n & 1) {
            ret = (ret * a) % m;
        }
        n = n >> 1;
        a = (a * a) % m;
    }
    return ret;
}

void precalculate(lli p, lli e, lli m) {
    arr[0] = arr[1] = 1;
    for (int i = 2; i <= m; ++i) {
        lli x = 1;
        if (i % p) {
            x = i;
        }
        arr[i] = (arr[i - 1] * x) % m;
    }
}

lli E(lli n, lli p) {
    lli ret = 0;
    lli tmp = p;
    while (tmp <= n) {
        ret += (n / tmp);
        tmp *= p;
    }
    return ret;
}

lli f(lli n, lli p, lli m) {
    lli ret = power(arr[m], n / m, m) * arr[n % m] % m;
    return ret;
}

lli F(lli n, lli p, lli m) {
    lli i = 1;
    lli ret = 1;
    while (i <= n) {
        ret = (ret * f(n / i, p, m)) % m;
        i = p * i;
    }
    return ret;
}

lli mod_pem(lli n, lli r, lli p, lli e, lli m) {
    lli powp = E(n, p) - E(r, p) - E(n - r, p);
    lli mod1 = F(n, p, m);
    lli mod2 = (F(r, p, m) * F(n - r, p, m)) % m;
    return (power(p, powp, m) * mod1 * power(mod2, (m / p) * (p - 1) - 1, m) ) % m;
}

lli get_binom(lli n, lli r, lli p, lli e) {
    lli m = power(p, e);
    precalculate(p, e, m);
    return mod_pem(n, r, p, e, m);
}

lli inv(lli a, lli b) {
    return power(a, tot[b] - 1, b);
}

lli crt(vector<lli> &A, vector<lli> &B) {
    lli N = 1;
    for (int i = 0; i < A.size(); ++i) {
        N *= A[i];
    }
    lli ret = 0;
    for (int i = 0; i < A.size(); ++i) {
        lli val = A[i];
        lli md = B[i];
        lli prod_rem = N / val;
        ret += md * (prod_rem * inv(prod_rem, val));
    }
    ret %= N;
    return ret;
}

lli solve(lli n, lli r, lli m) {
    map<lli, lli> pf = factorization(m);
    vector<lli> mod;
    vector<lli> binom;
    for (auto &f : pf) {
        lli p = f.first;
        lli e = f.second;
        mod.push_back(power(p, e));
        binom.push_back(get_binom(n, r, p, e));
        tot[power(p, e)] = (power(p, e - 1) * (p - 1));
    }
    return crt(mod, binom);
}

int main(int argc, const char * argv[]) {
    sieve();
    int t;
    cin >> t;
    while (t--) {
        lli n, k, m;
        cin >> n >> k >> m;
        lli r = (n - 1) / k + 1;
        lli ans = solve(r * k - n + r - 1, r - 1, m);
        cout << r << " " << ans << endl;
    }
    return 0;
}

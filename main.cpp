#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// Check if a number is prime
bool isPrime(ll n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (ll i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

// Sieve of Eratosthenes: generate all primes up to n
vector<int> sieve(int n) {
    vector<bool> prime(n + 1, true);
    vector<int> primes;

    if (n >= 0) prime[0] = false;
    if (n >= 1) prime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        if (prime[i]) primes.push_back(i);
    }

    return primes;
}

// Prime factorization
vector<pair<ll, int>> factorize(ll n) {
    vector<pair<ll, int>> factors;

    for (ll p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            int count = 0;
            while (n % p == 0) {
                n /= p;
                count++;
            }
            factors.push_back({p, count});
        }
    }

    if (n > 1) {
        factors.push_back({n, 1});
    }

    return factors;
}

// GCD
ll gcdLL(ll a, ll b) {
    while (b != 0) {
        ll temp = a % b;
        a = b;
        b = temp;
    }
    return abs(a);
}

// LCM
ll lcmLL(ll a, ll b) {
    return (a / gcdLL(a, b)) * b;
}

// Modular exponentiation: (base^exp) % mod
ll modPow(ll base, ll exp, ll mod) {
    base %= mod;
    ll result = 1 % mod;

    while (exp > 0) {
        if (exp & 1) {
            result = (__int128)result * base % mod;
        }
        base = (__int128)base * base % mod;
        exp >>= 1;
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        cout << "\n=== Prime / Number Theory Toolkit ===\n";
        cout << "1. Check Prime\n";
        cout << "2. Generate Primes (Sieve)\n";
        cout << "3. Factorize Number\n";
        cout << "4. GCD / LCM\n";
        cout << "5. Modular Exponentiation\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";

        int choice;
        cin >> choice;

        if (choice == 0) {
            cout << "Exiting...\n";
            break;
        }

        if (choice == 1) {
            ll n;
            cout << "Enter number: ";
            cin >> n;

            if (isPrime(n)) cout << n << " is prime.\n";
            else cout << n << " is not prime.\n";
        }
        else if (choice == 2) {
            int n;
            cout << "Generate primes up to: ";
            cin >> n;

            vector<int> primes = sieve(n);
            cout << "Primes up to " << n << ":\n";
            for (int p : primes) cout << p << " ";
            cout << "\n";
        }
        else if (choice == 3) {
            ll n;
            cout << "Enter number: ";
            cin >> n;

            auto factors = factorize(n);
            cout << "Prime factorization of " << n << ":\n";
            for (auto [p, cnt] : factors) {
                cout << p << "^" << cnt << " ";
            }
            cout << "\n";
        }
        else if (choice == 4) {
            ll a, b;
            cout << "Enter two numbers: ";
            cin >> a >> b;

            cout << "GCD = " << gcdLL(a, b) << "\n";
            cout << "LCM = " << lcmLL(a, b) << "\n";
        }
        else if (choice == 5) {
            ll base, exp, mod;
            cout << "Enter base, exponent, modulus: ";
            cin >> base >> exp >> mod;

            cout << "Result = " << modPow(base, exp, mod) << "\n";
        }
        else {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}
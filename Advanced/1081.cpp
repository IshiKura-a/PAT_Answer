#include <iostream>

typedef long long ll;

ll gcd(ll a, ll b) {
    if (a < b) return gcd(b, a);
    if (a % b == 0) return b;
    return gcd(b, a % b);
}

class Rational {
public:
    ll nume = 0;
    ll deno = 1;

    Rational(ll nume, ll deno) {
        bool neg = (nume < 0) != (deno < 0);
        nume = std::abs(nume);
        deno = std::abs(deno);

        if (nume) {
            ll g = gcd(nume, deno);
            this->nume = nume / g * (neg ? -1 : 1);
            this->deno = deno / g;
        } else {
            this->nume = 0;
            this->deno = 1;
        }
    }

    Rational operator+(const Rational &r) const {
        return {nume * r.deno + r.nume * deno, deno * r.deno};
    }

    void print() {
        bool neg = (nume < 0) != (deno < 0);
        ll n = std::abs(nume);
        ll d = std::abs(deno);

        if (n) {
            if (neg) printf("-");
            if (n / d > 0) {
                std::cout << n / d;
                if (n % d) {
                    printf(" ");
                }
                n = n % d;
            }
            if (n % d) {
                std::cout << n << "/" << d;
            }
        } else {
            printf("0");
        }
    }
};

int main() {
    ll n, nume, deno;
    std::cin >> n;
    Rational cur = {0, 1};
    for (ll i = 0; i < n; i++) {
        scanf("%lld/%lld", &nume, &deno);
        cur = cur + Rational(nume, deno);
    }

    cur.print();
    return 0;
}
#include <iostream>

typedef long long ll;

ll gcd(ll a, ll b) {
    if (a < b) return gcd(b, a);
    else if (a % b) return gcd(b, a % b);
    else return b;
}

void print(ll nume, ll deno) {
    if (!deno) {
        printf("Inf");
        return;
    }
    if (!nume) {
        printf("0");
        return;
    }
    bool neg = (nume < 0) != (deno < 0);
    nume = std::abs(nume);
    deno = std::abs(deno);
    ll g = gcd(nume, deno);
    nume = nume / g * (neg ? -1 : 1);
    deno /= g;
    ll n = 0;
    bool flag = nume < 0;
    if (flag) {
        printf("(-");
        nume = -nume;
    }
    if (nume / deno) {
        n = nume / deno;
        printf("%lld", n);
    }
    if (nume % deno) {
        if (n) printf(" ");
        printf("%lld/%lld", nume - n * deno, deno);
    }
    if (flag) {
        printf(")");
    }
}

int main() {
    ll a, b, c, d;
    scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d);

    if (a) {
        bool neg = (a < 0) != (b < 0);
        a = std::abs(a);
        b = std::abs(b);
        ll g = gcd(a, b);
        a = a / g * (neg ? -1 : 1);
        b /= g;
    } else {
        b = 1;
    }

    if (c) {
        bool neg = (c < 0) != (d < 0);
        c = std::abs(c);
        d = std::abs(d);
        ll g = gcd(c, d);
        c = c / g * (neg ? -1 : 1);
        d /= g;
    } else {
        d = 1;
    }

    print(a, b);
    printf(" + ");
    print(c, d);
    printf(" = ");
    print(a * d + b * c, b * d);
    printf("\n");

    print(a, b);
    printf(" - ");
    print(c, d);
    printf(" = ");
    print(a * d - b * c, b * d);
    printf("\n");

    print(a, b);
    printf(" * ");
    print(c, d);
    printf(" = ");
    print(a * c, b * d);
    printf("\n");

    print(a, b);
    printf(" / ");
    print(c, d);
    printf(" = ");
    print(a * d, b * c);
    printf("\n");

    return 0;
}
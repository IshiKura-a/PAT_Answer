#include <iostream>
#include <algorithm>
#include <cmath>


double str2N(const std::string &s, double radix) {
    double res = 0;
    for (auto c: s) {
        res *= radix;
        int n = radix;
        if ('0' <= c && c <= '9') {
            n = c - '0';
        } else if ('a' <= c && c <= 'z') {
            n = c - 'a' + 10;
        }
        if (n >= radix) {
            throw "radix err";
        }
        res += n;
    }
    return res;
}

double find(std::string s, double l, double r, double n) {
    if (l > r) return -1;
    double mid = std::ceil((l + r) / 2);
    double x = str2N(s, l);
    double y = str2N(s, mid);
    double z = str2N(s, r);
    if (n < x || n > z) {
        return -1;
    } else if (n == x) { return l; }
    else if (n == y) { return mid; }
    else if (n == z) { return r; }
    else if (x < n && n < y) {
        return find(s, l + 1, mid - 1, n);
    } else return find(s, mid + 1, r - 1, n);
}

int main() {
    std::string n1, n2, m;
    int tag, radix;
    double n;

    std::cin >> n1 >> n2 >> tag >> radix;
    std::transform(n1.begin(), n1.end(), n1.begin(), ::tolower);
    std::transform(n2.begin(), n2.end(), n2.begin(), ::tolower);

    if (tag == 1) {
        n = str2N(n1, radix);
        m = n2;
    } else {
        n = str2N(n2, radix);
        m = n1;
    }

    char max = '0';
    for (char c: m) {
        if (max < c) max = c;
    }
    double i = find(m, ('0' <= max && max <= '9') ? (max - '0' + 1) : (max - 'a' + 11), n + 1, n);
    if (i >= 0) {
        printf("%.0lf", i);
    } else {
        printf("Impossible");
    }
}
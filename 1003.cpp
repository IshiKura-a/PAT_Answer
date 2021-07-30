#include <iostream>
#include <vector>

bool judge(const std::string &s);

int main() {
    int n, i;
    std::string s;

    std::cin >> n;
    for (i = 0; i < n; i++) {
        std::cin >> s;
        if (i) std::cout << '\n';
        std::cout << (judge(s) ? "YES" : "NO");
    }
}

bool judge(const std::string &s) {
    std::vector<int> n;
    n.push_back(0);
    for (char c: s) {
        switch (c) {
            case 'A':
                n.back()++;
                break;
            case 'P':
                if (n.size() != 1) return false;
                n.push_back(0);
                break;
            case 'T':
                if (n.size() != 2) return false;
                n.push_back(0);
                break;
            default:
                return false;
        }
    }
    if (n.size() != 3) return false;
    return n[2] == n[0] * n[1] && n[1] > 0;
}

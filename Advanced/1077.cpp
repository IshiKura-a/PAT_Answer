#include <iostream>

const int MAXL = 300;

int main() {
    int n;
    std::string suffix, s;

    scanf("%d\n",&n);
    for (int i = 0; i < n; i++) {
        std::getline(std::cin, s);
        if (i) {
            int j = 0;
            for (; j < suffix.length() && j < s.length(); j++) {
                if (suffix[suffix.length() - 1 - j] != s[s.length() - 1 - j]) {
                    break;
                }
            }
            if (j < suffix.length()) {
                suffix = suffix.substr(suffix.length() - j, j);
            }
        } else {
            suffix = s;
        }
    }

    if (suffix.empty()) {
        printf("nai");
    } else {
        std::cout << suffix;
    }
    return 0;
}
#include <iostream>

int main() {
    std::string s;
    std::cin >> s;
    if (s[0] == '-') printf("-");
    int posE = s.find('E');
    std::string frac = s.substr(1, posE - 1);
    int expo = std::stoi(s.substr(posE + 1));

    if (expo < 0) {
        for (int i = 0; i < std::abs(expo); i++) {
            printf("0");
            if (!i) printf(".");
        }
        for (auto c: frac) {
            if (c != '.') {
                printf("%c", c);
            }
        }
    } else {
        int index = 0;
        for (auto c: frac) {
            if (c != '.') {
                if (index == expo + 1) printf(".");
                printf("%c", c);
                index++;
            }
        }
        while (index <= expo) {
            printf("0");
            index++;
        }
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <map>

int main() {
    std::vector<std::string> base = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct",
                                     "nov", "dec"};
    std::vector<std::string> higher = {"tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer",
                                       "jou"};

    std::vector<std::string> earth2Mars;
    std::map<std::string, int> mars2Earth;
    for (int i = 0; i <= 12; i++) {
        for (int j = 0; j <= 12; j++) {
            if (!i) {
                earth2Mars.push_back(base[j]);
                mars2Earth[base[j]] = i * 13 + j;
            } else {
                std::string s = higher[i - 1];
                if (j) s = s.append(" ").append(base[j]);
                earth2Mars.push_back(s);
                mars2Earth[s] = i * 13 + j;
            }
        }
    }

    int N;
    std::cin >> N;
    std::string line;
    for (int i = 0; i < N; i++) {
        std::getline(std::cin, line, '\n');
        if (line.empty()) {
            i--;
            continue;
        }
        if ('0' <= line[0] && line[0] <= '9') {
            std::cout << earth2Mars[std::stoi(line)] << std::endl;
        } else {
            std::cout << mars2Earth[line] << std::endl;
        }
    }
    return 0;
}
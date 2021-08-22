#include <iostream>
#include <set>

int main() {
    int N, skip, first;
    std::cin >> N >> skip >> first;

    int cnt = 0;
    std::set<std::string> winner;
    if (N < first) {
        std::cout << "Keep going...";
    } else {
        for (int i = 1; i < first; i++) {
            std::string s;
            std::cin >> s;
        }
        for (int i = first; i <= N; i++) {
            std::string s;
            std::cin >> s;
            if (!(cnt % skip)) {
                if (winner.find(s) == winner.end()) {
                    winner.insert(s);
                    std::cout << s << std::endl;
                } else {
                    cnt--;
                }
            }
            cnt++;
        }
    }

    return 0;
}
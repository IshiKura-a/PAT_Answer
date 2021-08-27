#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

class Pair {
public:
    char c;
    int pos;

    Pair(char c, int pos) : c(c), pos(pos) {}
};

int main() {
    int n;
    std::string s;
    std::map<char, int> stuck;
    std::cin >> n;
    std::cin >> s;
    std::vector<char> candidate(s.begin(), s.end());
    // 此题如果使用如下集合，会出现WA
//    std::vector<char> candidate({'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
//                                 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
//                                 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
//                                 '_'});

    for (char c: candidate) {
        std::string append(n, c);
        std::string character(1, c);
        bool flag = false;
        int pos1 = 0, pos2, minPos = s.size() + 1;
        while ((pos1 = s.find(character, pos1)) != -1) {
            pos2 = s.find(append, pos1);
            if (pos1 == pos2) {
                minPos = std::min(minPos, pos1);
                flag = true;
            } else {
                flag = false;
                break;
            }
            pos1 += n;
        }
        if (flag) {
            pos1 = 0;
            stuck[c] = minPos;
            while ((pos1 = s.find(append, pos1)) != -1) {
                s = s.replace(pos1, n, character);
                pos1 = pos1 + 1;
            }
        }
    }
    std::vector<Pair> v;
    v.reserve(stuck.size());
    for (auto p: stuck) {
        v.emplace_back(p.first, p.second);
    }
    std::sort(v.begin(), v.end(), [](Pair a, Pair b) {
        return a.pos < b.pos;
    });
    for (auto p: v) {
        std::cout << p.c;
    }
    std::cout << std::endl << s;
    return 0;
}

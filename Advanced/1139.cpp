#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>

std::unordered_map<int, std::set<int>> same;
std::unordered_map<int, std::set<int>> friendship;

int main() {
    int N, M, K;
    scanf("%d%d", &N, &M);

    /*
     * 此题需要注意：
     * 1. 输出为4位编号: %04d
     * 2. 0000的性别处理
     */
    std::string strX, strY;
    int i, x, y;
    for (i = 0; i < M; i++) {
        std::cin >> strX >> strY;
        bool flag = (strX[0] == '-') == (strY[0] == '-');
        x = abs(std::stoi(strX));
        y = abs(std::stoi(strY));
        if (flag) {
            if (same.find(x) != same.end()) {
                same[x].insert(y);
            } else {
                same.insert(std::make_pair(x, std::set<int>({y})));
            }
            if (same.find(y) != same.end()) {
                same[y].insert(x);
            } else {
                same.insert(std::make_pair(y, std::set<int>({x})));
            }
        }
        if (friendship.find(x) != friendship.end()) {
            friendship[x].insert(y);
        } else {
            friendship.insert(std::make_pair(x, std::set<int>({y})));
        }
        if (friendship.find(y) != friendship.end()) {
            friendship[y].insert(x);
        } else {
            friendship.insert(std::make_pair(y, std::set<int>({x})));
        }
    }

    scanf("%d", &K);
    for (i = 0; i < K; i++) {
        scanf("%d%d", &x, &y);
        x = abs(x);
        y = abs(y);
        if (same.find(x) == friendship.end() || same.find(y) == friendship.end()) {
            printf("0\n");
        } else {
            auto fX = same[x];
            auto fY = same[y];
            std::vector<int> res;
            for (auto p: fX) {
                for (auto q: fY) {
                    std::set<int> tmp = {p, q, x, y};
                    if (tmp.size() == 4 && friendship[p].find(q) != friendship[p].end()) {
                        res.push_back(p);
                        res.push_back(q);
                    }
                }
            }
            printf("%d\n", res.size() / 2);
            int j;
            for (j = 0; j < res.size(); j += 2) {
                printf("%04d %04d\n", res[j], res[j + 1]);
            }
        }
    }
    return 0;
}
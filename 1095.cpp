#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <numeric>
#include <map>

#define MAXN 1005

enum {
    GRADE = 1,
    GNO = 2,
    DATE = 3
};

class Record {
public:
    std::string s;
    int grade = 0;
};

int main() {
    int N, M, i;
    std::string s;
    std::vector<Record *> records;

    std::cin >> N >> M;
    for (i = 0; i < N; i++) {
        std::cin >> s;
        records.push_back(new Record());
        records.back()->s = s;

        std::cin >> records.back()->grade;
    }

    int inst;
    std::string req;
    std::string NA = "NA\n";

    for (i = 0; i < M; i++) {
        std::cin >> inst >> req;
        std::cout << "Case " << i + 1 << ": " << inst << " " << req << std::endl;
        std::vector<Record *> stream;
        switch (inst) {
            case GRADE:
                std::copy_if(records.begin(), records.end(), std::back_inserter(stream),
                             [req](Record *r) { return r->s[0] == req[0]; });
                std::sort(stream.begin(), stream.end(), [](Record *a, Record *b) {
                    return a->grade > b->grade || (a->grade == b->grade && a->s.compare(b->s) < 0);
                });
                if (stream.empty()) {
                    printf("%s", NA.c_str());
                } else {
                    std::for_each(stream.begin(), stream.end(), [&](Record *item) {
                        printf("%s %d\n", item->s.c_str(), item->grade);
                    });
                }
                break;
            case GNO:
                std::copy_if(records.begin(), records.end(), std::back_inserter(stream),
                             [req](Record *r) { return r->s.substr(1, 3) == req; });
                if (stream.empty()) {
                    printf("%s", NA.c_str());
                } else {
                    printf("%d %d\n", stream.size(), std::accumulate(stream.begin(), stream.end(), 0,
                                                                     [](int curSum, Record *b) {
                                                                         return curSum + b->grade;
                                                                     }));
                }
                break;
            case DATE:
                std::copy_if(records.begin(), records.end(), std::back_inserter(stream),
                             [req](Record *r) { return r->s.substr(4, 6) == req; });
                if (stream.empty()) {
                    printf("%s", NA.c_str());
                } else {
                    typedef std::pair<int, int> pair;
                    std::vector<pair> mapArray;
                    std::vector<int> mMap(MAXN);
                    std::for_each(stream.begin(), stream.end(), [&](Record *item) {
                        mMap[stoi(item->s.substr(1, 3))]++;
                    });
                    for (int j = 0; j < 1000; j++) {
                        if (mMap[j] != 0) {
                            mapArray.push_back(std::make_pair(j, mMap[j]));
                        }
                    }
                    std::sort(mapArray.begin(), mapArray.end(), [](const pair &a, const pair &b) {
                        return a.second > b.second || (a.second == b.second && a.first < b.first);
                    });
                    for (const auto &m: mapArray) {
                        printf("%03d %d\n", m.first, m.second);
                    }
                }
                break;
            default:
                break;
        }
    }
}

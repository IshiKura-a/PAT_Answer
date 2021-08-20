#include <iostream>
#include <map>
#include <vector>
#include <cctype>
#include <algorithm>

class School {
public:
    std::string name;
    int tws = 0;
    int twsB = 0;
    int twsA = 0;
    int twsT = 0;
    int ns = 0;
};

int main() {
    int N, i;
    std::string id, school;
    int tws;

    std::map<std::string, School *> record;
    std::cin >> N;
    for (i = 0; i < N; i++) {
        std::cin >> id >> tws >> school;
        std::transform(school.begin(), school.end(), school.begin(), tolower);

        if (record.find(school) != record.end()) {
            record[school]->ns++;
            if (id[0] == 'B') {
                record[school]->twsB += tws;
            } else if (id[0] == 'A') {
                record[school]->twsA += tws;
            } else {
                record[school]->twsT += tws;
            }
        } else {
            auto *newSchool = new School();
            newSchool->name = school;
            newSchool->ns = 1;
            if (id[0] == 'B') {
                newSchool->twsB += tws;
            } else if (id[0] == 'A') {
                newSchool->twsA += tws;
            } else {
                newSchool->twsT += tws;
            }
            record.insert(std::make_pair(school, newSchool));
        }
    }

    std::vector<School *> rank;
    for (const auto &r: record) {
        rank.push_back(r.second);
    }
    std::transform(rank.begin(), rank.end(), rank.begin(), [](School *item) {
        item->tws = (int) (item->twsA + item->twsB / 1.5 + item->twsT * 1.5);
        return item;
    });
    std::sort(rank.begin(), rank.end(), [](School *a, School *b) {
        if (a->tws > b->tws) {
            return true;
        } else if (a->tws < b->tws) {
            return false;
        } else if (a->ns < b->ns) {
            return true;
        } else if (a->ns > b->ns) {
            return false;
        } else {
            return a->name.compare(b->name) < 0;
        }
    });

    int cnt = 1;
    printf("%d\n", rank.size());
    for (i = 0; i < rank.size(); i++) {
        if (i == 0 || rank[i]->tws != rank[i - 1]->tws) {
            cnt = i + 1;
        }
        printf("%d %s %d %d\n", cnt, rank[i]->name.c_str(), (int) rank[i]->tws, rank[i]->ns);
    }

    return 0;
}


#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

class Student {
public:
    int id;
    double gE, gI;
    double final;
    std::vector<int> school;

    Student(int id, double gE, double gI) : id(id), gE(gE), gI(gI) {
        final = (gI + gE) / 2.0;
    }

    bool operator<(const Student &r) const {
        if (final < r.final) return true;
        else if (final == r.final) {
            if (gE < r.gE) return true;
            return false;
        }
        return false;
    }

    bool operator==(const Student &r) const {
        return final == r.final && gE == r.gE;
    }

    bool operator>(const Student &r) const {
        return !(*this < r || *this == r);
    }
};

int main() {
    int n, m, k, school;
    double gE, gI;
    std::cin >> n >> m >> k;
    std::vector<int> quota(m);
    std::vector<Student *> student;
    std::vector<std::vector<int>> res(m);
    std::unordered_map<int, Student *> map;

    for (int i = 0; i < m; i++) {
        std::cin >> quota[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> gE >> gI;
        auto *s = new Student(i, gE, gI);
        for (int j = 0; j < k; j++) {
            std::cin >> school;
            s->school.push_back(school);
        }
        student.push_back(s);
        map[i] = s;
    }
    std::sort(student.begin(), student.end(), [](auto *a, auto *b) {
        return *a > *b;
    });

    for (auto i: student) {
        for (auto j: i->school) {
            if (res[j].size() < quota[j]
            || (*map[res[j].back()] == *i)) {
                res[j].push_back(i->id);
                break;
            }
        }
    }

    for (auto i: res) {
        std::sort(i.begin(), i.end());
        for (int j = 0; j < i.size(); j++) {
            if (j) printf(" ");
            printf("%d", i[j]);
        }
        printf("\n");
    }
    return 0;
}
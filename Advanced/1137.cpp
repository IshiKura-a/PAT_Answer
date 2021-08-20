#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>

class Student {
public:
    std::string id;
    int gP = -1;
    int gMid = -1;
    int gFinal = -1;
    int g = -1;

    Student() {}

    Student(std::string id, int gP = -1) : id(std::move(id)), gP(gP) {}

    void cal(int gFinal) {
        this->gFinal = gFinal;
        this->g = gFinal >= gMid ? gFinal : (int) round(0.4 * gMid + 0.6 * gFinal);
    }
};

int main() {
    int P, N, M;
    std::cin >> P >> M >> N;

    std::map<std::string, Student> stuMap;
    int i, tmp;
    std::string s;
    for (i = 0; i < P; i++) {
        std::cin >> s >> tmp;
        if (tmp >= 200) {
            stuMap[s] = Student(s, tmp);
        }
    }
    for (i = 0; i < M; i++) {
        std::cin >> s >> tmp;
        if (stuMap.find(s) != stuMap.end()) {
            stuMap[s].gMid = tmp;
        }
    }
    for (i = 0; i < N; i++) {
        std::cin >> s >> tmp;
        if (stuMap.find(s) != stuMap.end()) {
            stuMap[s].cal(tmp);
        }
    }

    std::vector<Student> v;
    for (const auto &m: stuMap) {
        if (m.second.gFinal >= 60) {
            v.push_back(m.second);
        }
    }

    std::sort(v.begin(), v.end(), [](Student a, Student b) {
        return a.g != b.g ? a.g > b.g : a.id < b.id;
    });

    for (const auto &item: v) {
        printf("%s %d %d %d %d\n", item.id.c_str(), item.gP, item.gMid, item.gFinal, item.g);
    }
    return 0;
}

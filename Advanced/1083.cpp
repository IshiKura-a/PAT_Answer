#include <iostream>
#include <algorithm>
#include <vector>

class Student {
public:
    std::string name, id;
    int grade;

    Student(std::string name, std::string id, int grade) : name(std::move(name)), id(std::move(id)), grade(grade) {}

    bool operator<(const Student &r) const {
        return grade < r.grade;
    }
};

int main() {
    int n, grade;
    std::string name, id;

    std::cin >> n;
    std::vector<Student> v;
    for (int i = 0; i < n; i++) {
        std::cin >> name >> id >> grade;
        v.emplace_back(name, id, grade);
    }

    std::sort(v.begin(), v.end());
    int min, max;
    std::cin >> min >> max;

    auto low = std::lower_bound(v.begin(), v.end(), Student("", "", min));
    auto up = std::upper_bound(v.begin(), v.end(), Student("", "", max));

    low--;
    up--;
    bool flag = false;
    for (auto it = up; it != low; it--) {
        flag = true;
        std::cout << it->name << " " << it->id << std::endl;
    }

    if (!flag) {
        std::cout << "NONE";
    }
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

class Student {
public:
    int id;
    std::vector<int> score;
    int total = 0;
    int nPerfect = 0;
    bool valid = false;

    Student(int id, int n) : id(id), score(std::vector<int>(n + 1, -2)) {}

    void update(int i, int s, int max) {
        if (s >= 0) {
            valid = true;
        }
        if (score[i] < s) {
            if (s == max) {
                nPerfect++;
            }
            if (s < 0 || score[i] < 0) {
                score[i] = s;
                if (s >= 0) total += s;
            } else {
                total += s - score[i];
                score[i] = s;
            }
        }
    }

    bool operator<(const Student &r) const {
        return (total > r.total) || (total == r.total && nPerfect > r.nPerfect)
               || (total == r.total && nPerfect == r.nPerfect && id < r.id);
    }
};

int main() {
    int m, n, k;
    std::cin >> n >> k >> m;

    std::vector<Student *> v;
    for (int i = 1; i <= n; i++) {
        v.push_back(new Student(i, k));
    }

    std::vector<int> score(k + 1);
    for (int i = 1; i <= k; i++) {
        std::cin >> score[i];
    }

    int id, index, grade;
    for (int i = 0; i < m; i++) {
        std::cin >> id >> index >> grade;
        v[id - 1]->update(index, grade, score[index]);
    }

    std::sort(v.begin(), v.end(), [&](Student *a, Student *b) {
        return *a < *b;
    });

    int ranking = 1;
    int nInvalid = 0;
    for (int i = 0; i < n; i++) {
        if (!v[i]->valid) {
            nInvalid++;
            continue;
        }
        if (i && v[i]->total != v[i - 1]->total) {
            ranking = i + 1 - nInvalid;
        }
        printf("%d %05d %d", ranking, v[i]->id, v[i]->total);
        for (int j = 1; j <= k; j++) {
            if (v[i]->score[j] >= 0) {
                printf(" %d", v[i]->score[j]);
            } else if (v[i]->score[j] == -1) {
                printf(" 0");
            } else {
                printf(" -");
            }
        }
        printf("\n");
    }

    return 0;
}
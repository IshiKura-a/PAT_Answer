#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

const int MAXN = 10005;
const int MAXM = 10004;

class People {
public:
    int id = 0, father = -1, mother = -1;
    int nEstate = 0;
    double sumEstate = 0;

    People() = default;

    People(int id, int father, int mother) : id(id), father(father), mother(mother) {}
};

class Statsic {
public:
    int id = 0;
    int nFamily = 0;
    int nEstate = 0;
    double sumEstate = 0;
    double avgEstate = 0;
    double avgArea = 0;
};

People *people[MAXN];
int family[MAXN];

void makeSet(int x) {
    if (family[x] == MAXM)
        family[x] = x;
}

int findSet(int x) {
    if (x != family[x]) {
        family[x] = findSet(family[x]);
    }
    return family[x];
}

void unionSet(int x, int y) {
    int xx = findSet(x);
    int yy = findSet(y);

    if (xx < yy) {
        family[yy] = xx;
    } else if (xx > yy) {
        family[xx] = yy;
    }
}

int main() {
    int N;
    std::cin >> N;
    int id, father, mother, nChildren, children;

    std::fill(family, family + MAXN, MAXM);
    for (int i = 0; i < N; i++) {
        std::cin >> id >> father >> mother >> nChildren;
        makeSet(id);
        if (father != -1) {
            makeSet(father);
            unionSet(id, father);
        }
        if (mother != -1) {
            makeSet(mother);
            unionSet(id, mother);
        }
        people[id] = new People(id, father, mother);
        for (int j = 0; j < nChildren; j++) {
            std::cin >> children;
            makeSet(children);
            unionSet(id, children);
        }
        std::cin >> people[id]->nEstate;
        std::cin >> people[id]->sumEstate;
    }

    std::map<int, Statsic> familyMap;
    for (int i = 0; i <= 9999; i++) {
        if (family[i] != MAXM) {
            int j = findSet(i);
            familyMap[j].nFamily++;
            familyMap[j].id = j;
            if (people[i]) {
                familyMap[j].nEstate += people[i]->nEstate;
                familyMap[j].sumEstate += people[i]->sumEstate;
            }
        }
    }

    printf("%d\n", familyMap.size());
    std::vector<Statsic> v;
    for (auto entry: familyMap) {
        entry.second.avgEstate = entry.second.nEstate * 1.0 / entry.second.nFamily;
        entry.second.avgArea = entry.second.sumEstate * 1.0 / entry.second.nFamily;
        v.push_back(entry.second);
    }

    std::sort(v.begin(), v.end(), [](Statsic a, Statsic b) {
        if (a.avgArea > b.avgArea) return true;
        else if (a.avgArea < b.avgArea) return false;
        else return a.id < b.id;
    });

    for (auto i: v) {
        printf("%04d %d %.3f %.3f\n", i.id, i.nFamily, i.avgEstate, i.avgArea);
    }
    return 0;
}
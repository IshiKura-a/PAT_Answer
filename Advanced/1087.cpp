#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

class Edge {
public:
    int to;
    double cost;

    Edge(int to, int cost) : to(to), cost(cost) {};
};

const int MAXN = 26 * 26 * 26;
int happiness[MAXN];
std::vector<Edge> edge[MAXN];
bool visit[MAXN];

std::vector<int> cur;

std::vector<int> opt;
double minCost = 0x3f3f3f3f;
double maxHappiness = 0;
int cnt = 0;
double curCost = 0;
double curHappiness = 0;

int toInt(std::string s) {
    return (s[0] - 'A') + 26 * (s[1] - 'A') + 26 * 26 * (s[2] - 'A');
}

std::string toString(int i) {
    std::string s;
    for(int j=0;j<3;j++) {
        s.push_back(i % 26 + 'A');
        i /= 26;
    }
    return s;
}

int rom = toInt("ROM");

void dfs() {
    if (cur.back() == rom) {
        if (curCost < minCost) {
            cnt = 1;
        } else if (curCost == minCost) {
            cnt++;
        }
        if (curCost < minCost ||
            (curCost == minCost && curHappiness > maxHappiness) ||
            (curCost == minCost && curHappiness == maxHappiness &&
             opt.size() > cur.size())) {
            minCost = curCost;
            maxHappiness = curHappiness;
            opt = std::vector<int>(cur);
        }
    } else {
        if (curCost >= minCost) {
            return;
        }
        for (auto i: edge[cur.back()]) {
            if (!visit[i.to]) {
                visit[i.to] = true;
                cur.push_back(i.to);
                curCost += i.cost;
                curHappiness += happiness[i.to];
                dfs();
                curHappiness -= happiness[i.to];
                curCost -= i.cost;
                cur.pop_back();
                visit[i.to] = false;
            }
        }
    }
}

int main() {
    int n, k, s;
    std::string p, q;
    std::cin >> n >> k;

    memset(visit, 0, sizeof(visit));
    std::cin >> p;
    s = toInt(p);

    double tmp;
    for (int i = 0; i < n - 1; i++) {
        std::cin >> p >> tmp;
        auto j = toInt(p);
        happiness[j] = tmp;
    }

    for (int i = 0; i < k; i++) {
        std::cin >> p >> q >> tmp;
        auto x = toInt(p);
        auto y = toInt(q);
        edge[x].emplace_back(y, tmp);
        edge[y].emplace_back(x, tmp);
    }

    visit[s] = false;
    cur.push_back(s);
    dfs();

    printf("%d %.0lf %.0lf %.0lf\n", cnt, minCost, maxHappiness, std::floor(maxHappiness / (opt.size() - 1)));
    for (int i = 0; i < opt.size(); i++) {
        if (i) printf("->");
        std::cout << toString(opt[i]);
    }
    return 0;
}
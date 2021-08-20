#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

#define MAXN 10005

inline int Pair(int a, int b) {
    return 10000 * std::min(a, b) + std::max(a, b);
}

std::unordered_map<int, int> line;
std::unordered_map<int, std::set<int>> adjacent;
std::vector<int> path;
std::vector<int> curPath;
bool visit[MAXN];
std::set<int> stations;

int nTransfer = INT16_MAX;
int target, N, M;

void dfs(int start);

int main() {

    std::cin >> N;
    int i, j;
    int x, y;
    for (i = 1; i <= N; i++) {
        std::cin >> M;
        x = -1;
        for (j = 0; j < M; j++) {
            std::cin >> y;
            stations.insert(y);
            if (x != -1) {
                line[Pair(x, y)] = i;
                adjacent[x].insert(y);
                adjacent[y].insert(x);
            }
            x = y;
        }
    }

    std::cin >> M;
    for (i = 0; i < M; i++) {
        std::cin >> x >> target;
        nTransfer = INT16_MAX;
        path.clear();
        curPath.clear();
        std::fill(visit, visit + MAXN, false);
        dfs(x);

        std::cout << path.size() - 1 << std::endl;
        int curLine;
        int curStart = path[0];
        for (j = 1; j < path.size(); j++) {
            int l = line[Pair(path[j - 1], path[j])];
            if (j == 1) {
                curLine = l;
            } else if (curLine != l) {
                printf("Take Line#%d from %04d to %04d.\n", curLine, curStart, path[j - 1]);
                curStart = path[j - 1];
                curLine = l;
            }
        }
        if (curStart != path[path.size() - 1]) {
            printf("Take Line#%d from %04d to %04d.\n", curLine, curStart, path[path.size() - 1]);
        }
    }

}

void dfs(int start) {
    visit[start] = true;
    curPath.push_back(start);
    if (start == target) {
        int curTransfer = 0;
        int curLine;
        for (int i = 1; i < curPath.size(); i++) {
            int l = line[Pair(curPath[i - 1], curPath[i])];
            if (i == 1) {
                curLine = l;
            } else if (curLine != l) {
                curLine = l;
                curTransfer++;
            }
        }
        if (path.empty()) {
            path = curPath;
            nTransfer = curTransfer;
        } else if (curPath.size() < path.size() || (curPath.size() == path.size() && curTransfer < nTransfer)) {
            path = curPath;
            nTransfer = curTransfer;
        }
    } else {
        for (auto s: adjacent[start]) {
            if (!visit[s]) {
                dfs(s);
                curPath.pop_back();
                visit[s] = false;
            }
        }
    }
}
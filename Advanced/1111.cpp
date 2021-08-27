#include <iostream>
#include <map>
#include <vector>

const int MAXN = 0x3f3f3f3f;

std::map<int, std::map<int, int>> distance;
std::map<int, std::map<int, int>> timeDist;

int N, M;
int source, destination;

int main() {
    int v1, v2, oneWay, l, t;
    std::cin >> N >> M;
    for (int i = 0; i < M; i++) {
        scanf("%d%d%d%d%d", &v1, &v2, &oneWay, &l, &t);
        distance[v1][v2] = l;
        timeDist[v1][v2] = t;
        if (!oneWay) {
            distance[v2][v1] = l;
            timeDist[v2][v1] = t;
        }
    }
    std::cin >> source >> destination;

    std::vector<int> minDistance = std::vector<int>(N, MAXN);
    std::vector<int> minDistanceTime = std::vector<int>(N, MAXN);
    std::vector<int> minDistanceN = std::vector<int>(N, MAXN);
    std::vector<bool> visit = std::vector<bool>(N, false);
    std::vector<int> path = std::vector<int>(N, -1);
    for (auto i: distance[source]) {
        minDistance[i.first] = i.second;
        path[i.first] = source;
        minDistanceN[i.first] = 1;
    }
    for (auto i: timeDist[source]) {
        minDistanceTime[i.first] = i.second;
    }
    visit[source] = true;
    minDistance[source] = 0;
    minDistanceTime[source] = 0;
    minDistanceN[source] = 0;
    while (true) {
        int minDist = MAXN;
        int node = -1;
        for (int j = 0; j < N; j++) {
            if (!visit[j] && minDistance[j] != MAXN) {
                if (minDistance[j] < minDist) {
                    node = j;
                    minDist = minDistance[j];
                }
            }
        }
        if (node == -1) break;
        visit[node] = true;
        for (auto j: distance[node]) {
            if (!visit[j.first]) {
                if (minDistance[node] + j.second < minDistance[j.first]
                    || (minDistance[node] + j.second == minDistance[j.first]
                        && minDistanceTime[node] + timeDist[node][j.first] < minDistanceTime[j.first])
                    || (minDistance[node] + j.second == minDistance[j.first]
                        && minDistanceTime[node] + timeDist[node][j.first] == minDistanceTime[j.first]
                        && minDistanceN[node] + 1 < minDistanceN[j.first])) {
                    minDistance[j.first] = minDistance[node] + j.second;
                    minDistanceTime[j.first] = minDistanceTime[node] + timeDist[node][j.first];
                    minDistanceN[j.first] = minDistanceN[node] + 1;
                    path[j.first] = node;
                }
            }
        }
    }

    std::vector<int> pathDistance;
    int cur = destination;
    while (path[cur] > 0) {
        pathDistance.push_back(cur);
        cur = path[cur];
    }

    std::fill(visit.begin(), visit.end(), false);
    path = std::vector<int>(N, -1);
    std::vector<int> minTime = std::vector<int>(N, MAXN);
    std::vector<int> minTimeN = std::vector<int>(N, MAXN);
    for (auto i: timeDist[source]) {
        minTime[i.first] = i.second;
        minTimeN[i.first] = 1;
        path[i.first] = source;
    }
    visit[source] = true;
    minTime[source] = 0;
    minTimeN[source] = 0;
    while (true) {
        int minDist = MAXN;
        int node = -1;
        for (int j = 0; j < N; j++) {
            if (!visit[j] && minTime[j] != MAXN) {
                if (minTime[j] < minDist) {
                    node = j;
                    minDist = minTime[j];
                }
            }
        }
        if (node == -1) break;
        visit[node] = true;
        for (auto j: timeDist[node]) {
            if (!visit[j.first]) {
                if (minTime[node] + j.second < minTime[j.first]
                    || (minTime[node] + j.second == minTime[j.first]
                        && minTimeN[node] + 1 < minTimeN[j.first])) {
                    minTime[j.first] = minTime[node] + j.second;
                    path[j.first] = node;
                    minTimeN[j.first] = minTimeN[node] + 1;
                }
            }
        }
    }

    std::vector<int> pathTime;
    cur = destination;
    while (path[cur] > 0) {
        pathTime.push_back(cur);
        cur = path[cur];
    }

    bool unique = pathTime.size() == pathDistance.size();
    for (int i = 0; unique && i < pathDistance.size(); i++) {
        if (pathDistance[i] != pathTime[i]) {
            unique = false;
            break;
        }
    }

    if (unique) {
        printf("Distance = %d; Time = %d: %d", minDistance[destination], minDistanceTime[destination], source);
        for (int i = pathDistance.size() - 1; i >= 0; i--) {
            printf(" -> %d", pathDistance[i]);
        }
    } else {
        printf("Distance = %d: %d", minDistance[destination], source);
        for (int i = pathDistance.size() - 1; i >= 0; i--) {
            printf(" -> %d", pathDistance[i]);
        }
        printf("\n");
        printf("Time = %d: %d", minTime[destination], source);
        for (int i = pathTime.size() - 1; i >= 0; i--) {
            printf(" -> %d", pathTime[i]);
        }
    }

    return 0;
}
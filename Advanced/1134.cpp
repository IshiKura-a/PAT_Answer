#include <iostream>
#include <set>
#include <unordered_set>

class Edge : public std::pair<int, int> {
public:
    Edge(int a, int b) {
        this->first = std::min(a, b);
        this->second = std::max(a, b);
    }
};

int main() {
    int N, M, K;
    std::cin >> N >> M;
    int i, x, y;

    std::set<Edge> edges;
    for (i = 0; i < M; i++) {
        std::cin >> x >> y;
        edges.insert(Edge(x, y));
    }

    std::cin >> K;
    for (i = 0; i < K; i++) {
        int j, nv;
        std::unordered_set<int> vertexCover;
        std::cin >> nv;
        for (j = 0; j < nv; j++) {
            std::cin >> x;
            vertexCover.insert(x);
        }
        bool flag = true;
        for (auto e: edges) {
            if (vertexCover.find(e.first) == vertexCover.end()
            && vertexCover.find(e.second) == vertexCover.end()) {
                flag = false;
                break;
            }
        }
        std::cout << (flag ? "Yes\n" : "No\n");
    }

    return 0;
}


#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

class Node {
public:
    std::string addr;
    int val = 0;
    std::string next;
    int index = 0;

    Node() {}

    Node(std::string addr, int val, std::string next) : addr(std::move(addr)), val(val), next(std::move(next)) {}
};

int main() {
    std::string start;
    int N, K;
    std::unordered_map<std::string, Node> nodeMap;
    std::cin >> start >> N >> K;

    int i;
    std::string addr, next;
    int val;
    for (i = 0; i < N; i++) {
        std::cin >> addr >> val >> next;
        nodeMap.insert(std::make_pair(addr, Node(addr, val, next)));
    }

    std::vector<Node> v;
    for (addr = start, i = 0; addr != "-1"; i++) {
        auto node = nodeMap[addr];
        node.index = i;
        v.push_back(node);
        addr = node.next;
    }

    std::sort(v.begin(), v.end(), [K](const Node &a, const Node &b) {
        if ((a.val < 0 && b.val >= 0) || (a.val <= K && b.val > K)) {
            return true;
        } else if ((a.val >= 0 && b.val < 0) || (a.val > K && b.val <= K)) {
            return false;
        } else if (a.index < b.index) {
            return true;
        } else {
            return false;
        }
    });

    for (i = 0; i < v.size(); i++) {
        printf("%s %d ", v[i].addr.c_str(), v[i].val);
        if (i < v.size() - 1) {
            printf("%s\n", v[i + 1].addr.c_str());
        } else {
            printf("-1");
        }
    }
    return 0;
}

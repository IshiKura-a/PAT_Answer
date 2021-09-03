#include <iostream>
#include <vector>
#include <unordered_map>

const int MAXKEY = 1e4 + 5;
bool visit[MAXKEY];

class Node {
public:
    std::string addr;
    int key;
    std::string next;

    Node(std::string addr, int key, std::string next) : addr(std::move(addr)), key(key), next(std::move(next)) {}
};

void print(std::vector<Node *> &v) {
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i]->addr << " " << v[i]->key << " "
                  << ((i < v.size() - 1) ? v[i + 1]->addr : "-1") << std::endl;
    }
}

int main() {
    std::string start, addr, next;
    std::unordered_map<std::string, Node *> nodeMap;
    std::vector<Node *> removeList;
    std::vector<Node *> remainList;
    int N, key;
    std::cin >> start >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> addr >> key >> next;
        nodeMap[addr] = new Node(addr, key, next);
    }

    for (auto s = start; s != "-1";) {
        auto node = nodeMap[s];
        key = std::abs(node->key);
        if (!visit[key]) {
            visit[key] = true;
            remainList.push_back(node);
        } else {
            removeList.push_back(node);
        }
        s = node->next;
    }

    print(remainList);
    print(removeList);

    return 0;
}
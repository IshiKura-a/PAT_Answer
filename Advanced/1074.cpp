#include <iostream>
#include <vector>
#include <unordered_map>

class Node {
public:
    std::string addr, next;
    int data;

    Node(std::string addr, int data, std::string next) : addr(std::move(addr)), data(data), next(std::move(next)) {}
};

int main() {
    std::string start, addr, next;
    int data, n, k;
    std::cin >> start >> n >> k;

    std::unordered_map<std::string, Node *> nodeMap;
    for (int i = 0; i < n; i++) {
        std::cin >> addr >> data >> next;
        nodeMap[addr] = new Node(addr, data, next);
    }

    std::vector<Node *> v;
    std::string p = start;
    int i = 0;
    std::vector<Node *>::iterator it;
    while (p != "-1") {
        if (!(i % k)) {
            it = v.end();
        }
        auto node = nodeMap[p];
        it = v.insert(it, node);
        i++;
        p = node->next;
    }

    for (i = 0; i < (v.size() / k) * k; i++) {
        if (i) {
            std::cout << v[i]->addr << std::endl;
        }
        std::cout << v[i]->addr << " " << v[i]->data << " ";
    }

    // cout可能会超时
    for (int j = v.size() - 1; j >= i; j--) {
        std::cout << v[j]->addr << std::endl;
        std::cout << v[j]->addr << " " << v[j]->data << " ";
    }

    std::cout << "-1";
    return 0;
}
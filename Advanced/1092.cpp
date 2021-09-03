#include <iostream>
#include <vector>

int map(char c) {
    if ('0' <= c && c <= '9') {
        return c - '0';
    } else if ('A' <= c && c <= 'Z') {
        return c - 'A' + 10;
    } else {
        return c - 'a' + 36;
    }
}

int main() {
    std::string source, target;
    std::cin >> source >> target;
    std::vector<int> record(10 + 26 + 26);

    for (auto c: source) {
        record[map(c)]++;
    }

    for (auto c: target) {
        record[map(c)]--;
    }

    int remain = 0;
    int need = 0;
    for (auto i: record) {
        if (i > 0) remain += i;
        else need -= i;
    }

    if (need > 0) {
        printf("No %d", need);
    } else {
        printf("Yes %d", remain);
    }
    return 0;
}
#include <iostream>
#include <vector>

std::vector<int> ins;
std::vector<int> target;
std::vector<int> mer;
bool ident = true, mFlag = true;

void mergeSort(int step) {
    std::vector<int> v(mer);
    int n = v.size();
    for (int i = 0; i < v.size(); i += step * 2) {
        int p = i, q = i + step, j = i;
        while (p < i + step && q < i + step * 2 && p < n && q < n) {
            if (mer[p] < mer[q]) {
                v[j++] = mer[p++];
            } else {
                v[j++] = mer[q++];
            }
        }
        while (p < i + step && p < n) {
            v[j++] = mer[p++];
        }
        while (q < i + step * 2 && q < n) {
            v[j++] = mer[q++];
        }
    }

    if (ident && mFlag) {
        bool flag = true;
        for (int i = 0; i < v.size(); i++) {
            if (target[i] != v[i]) {
                flag = false;
                break;
            }
        }

        if (flag) {
            ident = false;
        }
    } else if (mFlag) {
        printf("Merge Sort\n");
        for (int j = 0; j < v.size(); j++) {
            if (j) {
                printf(" ");
            }
            printf("%d", v[j]);
        }
        mFlag = false;
    }
    mer = std::vector<int>(v);
    if(step < v.size()) {
        mergeSort(step * 2);
    }
}

int main() {
    int n;
    std::cin >> n;
    ins = std::vector<int>(n);
    target = std::vector<int>(n);

    for (int i = 0; i < n; i++) {
        std::cin >> ins[i];
    }
    mer = std::vector<int>(ins);

    for (int i = 0; i < n; i++) {
        std::cin >> target[i];
    }

    bool flag = true;
    for (int i = 1; i < n; i++) {
        auto key = ins[i];
        int j = i - 1;
        while (ins[j] > key && j >= 0) {
            ins[j + 1] = ins[j];
            j--;
        }
        ins[j + 1] = key;

        flag = true;
        for (int k = 0; k < n; k++) {
            if (ins[k] != target[k]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            i++;
            key = ins[i];
            j = i - 1;
            while (ins[j] > key) {
                ins[j + 1] = ins[j];
                j--;
            }
            ins[j + 1] = key;

            printf("Insertion Sort\n");
            for (j = 0; j < n; j++) {
                if (j) {
                    printf(" ");
                }
                printf("%d", ins[j]);
            }
            break;
        }
    }

    if (!flag) {
        mergeSort(1);
    }
    return 0;
}
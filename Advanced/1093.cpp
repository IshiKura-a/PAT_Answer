#include <iostream>
#include <vector>

const int MOD = 1000000007;

int main() {
    std::string s;
    std::cin >> s;
    std::vector<int> nP(s.size());
    std::vector<int> nPA(s.size());
    std::vector<int> nPAT(s.size());

    if (s[0] == 'P') {
        nP[0] = 1;
    }
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == 'P') {
            nP[i] = (nP[i - 1] + 1) % MOD;
            nPA[i] = nPA[i - 1];
            nPAT[i] = nPAT[i - 1];
        } else if (s[i] == 'A') {
            nP[i] = nP[i - 1];
            nPA[i] = (nPA[i - 1] + nP[i - 1]) % MOD;
            nPAT[i] = nPAT[i - 1];
        } else if (s[i] == 'T') {
            nP[i] = nP[i - 1];
            nPA[i] = nPA[i - 1];
            nPAT[i] = (nPAT[i - 1] + nPA[i - 1]) % MOD;
        } else {
            nP[i] = nP[i - 1];
            nPA[i] = nPA[i - 1];
            nPAT[i] = nPAT[i - 1];
        }
    }
    printf("%d", nPAT[s.size() - 1]);
}
#include <iostream>
#include <vector>

int main() {
    int K, N;
    std::cin >> K;
    for (int i = 0; i < K; i++) {
        std::cin >> N;
        int col;
        std::vector<bool> column(N);
        std::vector<bool> mainDiag(2 * N - 1);
        std::vector<bool> voiceDiag(2 * N - 1);

        std::fill(column.begin(), column.end(), true);
        std::fill(mainDiag.begin(), mainDiag.end(), true);
        std::fill(voiceDiag.begin(), voiceDiag.end(), true);
        bool flag = true;
        for (int j = 1; j <= N; j++) {
            std::cin >> col;
            if (flag) {
                flag &= column[col - 1] && mainDiag[col + j - 2] && voiceDiag[j - col + N - 1];
                column[col - 1] = false;
                mainDiag[col + j - 2] = false;
                voiceDiag[j - col + N - 1] = false;
            }
        }
        printf("%s\n", flag ? "YES" : "NO");
    }
    return 0;
}
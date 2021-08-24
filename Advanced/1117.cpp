#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    std::vector<int> ride;
    int N, x, maxRide = 0;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> x;
        if (maxRide < x) maxRide = x;
        ride.push_back(x);
    }

    std::sort(ride.begin(), ride.end());
    for (int i = maxRide; i >= 0; i--) {
        auto low = std::lower_bound(ride.begin(), ride.end(), i + 1);
        auto n = std::distance(low, ride.end());
        if (n >= i) {
            std::cout << i;
            break;
        }
    }

    return 0;
}
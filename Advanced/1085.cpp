#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;
int main() {
    ll n, p;
    std::cin >> n >> p;
    std::vector<ll> arr(n);

    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    std::sort(arr.begin(), arr.end());
    ll maxL = 0;
    for (int i = 0; i < n; i++) {
        auto it = std::upper_bound(arr.begin(), arr.end(), p * arr[i]);
        auto distance = std::distance(arr.begin(), it);
        if (maxL < distance - i) {
            maxL = distance - i;
        }
    }
    printf("%lld", maxL);
    return 0;
}
#include <iostream>
#include <queue>

const int MAXM = 1286;
const int MAXN = 128;
const int MAXL = 60;

bool slice[MAXM][MAXN][MAXL];

class Index {
public:
    int x = 0, y = 0, z = 0;

    Index(int x, int y, int z) : x(x), y(y), z(z) {}
};

int main() {
    int m, n, l, t;
    std::cin >> m >> n >> l >> t;
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                std::cin >> slice[j][k][i];
            }
        }
    }

    std::queue<Index *> stroke;
    int area = 0, tot = 0;
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                if (slice[j][k][i]) {
                    area = 1;
                    slice[j][k][i] = false;
                    stroke.push(new Index(j, k, i));
                    while (!stroke.empty()) {
                        auto c = stroke.front();
                        int x = c->x, y = c->y, z = c->z;
                        if (x > 0 && slice[x - 1][y][z]) {
                            slice[x - 1][y][z] = false;
                            area++;
                            stroke.push(new Index(x - 1, y, z));
                        }
                        if (x < m - 1 && slice[x + 1][y][z]) {
                            slice[x + 1][y][z] = false;
                            area++;
                            stroke.push(new Index(x + 1, y, z));
                        }
                        if (y > 0 && slice[x][y - 1][z]) {
                            slice[x][y - 1][z] = false;
                            area++;
                            stroke.push(new Index(x, y - 1, z));
                        }
                        if (y < n - 1 && slice[x][y + 1][z]) {
                            slice[x][y + 1][z] = false;
                            area++;
                            stroke.push(new Index(x, y + 1, z));
                        }
                        if (z > 0 && slice[x][y][z - 1]) {
                            slice[x][y][z - 1] = false;
                            area++;
                            stroke.push(new Index(x, y, z - 1));
                        }
                        if (z < l - 1 && slice[x][y][z + 1]) {
                            slice[x][y][z + 1] = false;
                            area++;
                            stroke.push(new Index(x, y, z + 1));
                        }
                        stroke.pop();
                    }
                    if (area >= t) {
                        tot += area;
                    }
                }
            }
        }
    }

    printf("%d", tot);
    return 0;
}
#include <iostream>

double toDouble(std::string s) {
    bool negFlag = s[0] == '-';
    bool validFlag = !negFlag || s.size() > 1;
    double res = 0;
    double exp = 1;
    int nDecimal = 0;
    bool decimalFlag = false;
    for (int i = negFlag ? 1 : 0; i < s.size() && validFlag; i++) {
        switch (s[i]) {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                if (decimalFlag) {
                    exp *= 0.1;
                    res += exp * (s[i] - '0');
                    nDecimal++;
                    if (nDecimal > 2) {
                        validFlag = false;
                    }
                } else {
                    res *= 10;
                    res += s[i] - '0';
                }
                break;
            case '.':
                if (decimalFlag) {
                    validFlag = false;
                } else {
                    decimalFlag = true;
                }
                break;
            default:
                validFlag = false;

        }
    }
    if(res > 1000) validFlag = false;
    if (validFlag) {
        return negFlag ? -res : res;
    } else {
        throw std::exception();
    }
}

int main() {
    int N, cnt = 0;
    double tot = 0;
    std::string num;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> num;
        try {
            tot += toDouble(num);
            cnt++;
        } catch (...) {
            std::cout << "ERROR: " << num << " is not a legal number\n";
        }
    }
    if (cnt == 0) {
        printf("The average of 0 numbers is Undefined");
    } else if (cnt == 1) {
        printf("The average of %d number is %.2f", cnt, tot / cnt);
    } else {
        printf("The average of %d numbers is %.2f", cnt, tot / cnt);
    }
    return 0;
}
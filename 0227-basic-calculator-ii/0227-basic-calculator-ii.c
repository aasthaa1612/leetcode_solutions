#include <ctype.h>

int calculate(char *s) {
    long num = 0;
    long last = 0;
    long result = 0;
    char op = '+';

    for (int i = 0;; i++) {
        char c = s[i];

        if (isdigit(c))
            num = num * 10 + (c - '0');

        if ((!isdigit(c) && c != ' ') || c == '\0') {
            if (op == '+') {
                result += last;
                last = num;
            } else if (op == '-') {
                result += last;
                last = -num;
            } else if (op == '*') {
                last = last * num;
            } else if (op == '/') {
                last = last / num;
            }

            op = c;
            num = 0;
        }

        if (c == '\0')
            break;
    }

    return result + last;
}
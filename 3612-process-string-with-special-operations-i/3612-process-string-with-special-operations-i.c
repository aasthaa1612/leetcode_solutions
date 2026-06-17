
char* processStr(char* s) {
    int cap = 16, len = 0;
    char *res = (char *)malloc(cap);

    for (int i = 0; s[i]; i++) {
        char c = s[i];

        if (c >= 'a' && c <= 'z') {
            if (len + 1 >= cap) {
                while (len + 1 >= cap) cap <<= 1;
                res = (char *)realloc(res, cap);
            }
            res[len++] = c;
        }
        else if (c == '*') {
            if (len > 0) len--;
        }
        else if (c == '#') {
            int oldLen = len;

            if (2 * len + 1 >= cap) {
                while (2 * len + 1 >= cap) cap <<= 1;
                res = (char *)realloc(res, cap);
            }

            memcpy(res + len, res, oldLen);
            len += oldLen;
        }
        else if (c == '%') {
            for (int l = 0, r = len - 1; l < r; l++, r--) {
                char t = res[l];
                res[l] = res[r];
                res[r] = t;
            }
        }
    }

    res[len] = '\0';
    return res;
}
// sync test
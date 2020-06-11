// ********************************************
//  util - string.c
//  Update  develop  4.0
// ********************************************


int strlen(char *s) {
    unsigned int i = 0;
    while (*s++) i++;
    return i;
}

int strcmp(char *s, char *t) {
    int i = 0;
    int ret = 0;
    for (i = 0; i < strlen(s); i++) {
        if (s[i] != t[i]) {
            ret = s[i] - t[i];
            break;
        }
    }
    return ret;
}

int strncmp(char *s, char *t, unsigned int n) {
    int i, ret = 0;
    for (i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            ret = s[i] - t[i];
            break;
        }
    }
    return ret;
}

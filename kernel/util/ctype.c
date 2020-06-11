// *****************************************
//  util - ctype.c
//  Update  develop4.0
// *****************************************

char isupper(unsigned char ch) {
    if ('A' <= ch && ch <= 'Z')
        return 1;
    return 0;
}

char islower(unsigned char ch) {
    if ('a' <= ch && ch <= 'z')
        return 1;
    return 0;
}

char isalpha(unsigned char ch) {
    if (islower(ch) || isupper(ch))
        return 1;
    return 0;
}

char isdigit(unsigned char ch) {
    if ('0' <= ch && ch <= '9')
        return 1;
    return 0;
}

char isalnum(unsigned char ch) {
    if (isalpha(ch) || isdigit(ch))
        return 1;
    return 0;
}


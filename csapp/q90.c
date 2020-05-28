float u2f(unsigned u) {
    return *(float*)(&u);
}

float fpwr2(int x) {
    unsigned exp, frac;
    unsigned u;

    if (x < 0 - (1 << 7) - 1) {
        // too small, return 0
        exp = 0;
        frac = 0;
    } else if (x <)
}

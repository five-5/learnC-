int main()
{
    const int v2 = 0, i = 0;
    int v1 = v2;
    int *p1 = &v1, &r1 = v1;
    const int *p2 = &v2, *const p3 = &i, &r2 = v2;

    // (a)
    r1 = v2;  // 合法 => v1 = v2

    // (b)
    p1 = p2;  // invalid conversion from 'const int*' to 'int *'
    p2 = p1;  // 合法 => int xx = (const int) xx

    // (c)
    p1 = p3;  // invalid conversion from 'const int*' to 'int *'
    p2 = p3;  // 合法 => int xx = (const int) xx

    return 0;
}

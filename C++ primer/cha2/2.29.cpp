int main()
{
    int i;
    const int ic = 0;
    int *p1;
    int *const p2 = &i;
    const int *const p3 = &ic;

    // (a)
    i = ic;    // ��

    // (b)
    p1 = p3;   // ��

    // (c)
    p1 = &ic;    // ��

    // (d)
    p3 = &ic; // ��

    // (e)
    p2 = p1;  // ��

    // (f)
    ic = *p3;   // ��

    return 0;
}

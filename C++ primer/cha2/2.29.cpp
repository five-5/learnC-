int main()
{
    int i;
    const int ic = 0;
    int *p1;
    int *const p2 = &i;
    const int *const p3 = &ic;

    // (a)
    i = ic;    // ¡Ì

    // (b)
    p1 = p3;   // ¡Á

    // (c)
    p1 = &ic;    // ¡Á

    // (d)
    p3 = &ic; // ¡Á

    // (e)
    p2 = p1;  // ¡Á

    // (f)
    ic = *p3;   // ¡Á

    return 0;
}

int coppie(int N, int *C)
{

    int res = 0;
    int step = 0;
    for (int i = 0; i < N; i++)
    {

        int j = i;
        while (C[j] != -1 && j < N)
        {
            step++;
            j = C[j];
        }
        if (C[j] == -1)
        {
            res += step;
        }
        step = 0;
    }
    return res;
}

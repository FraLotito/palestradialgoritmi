
int frec(int *C, int i, int *dp)
{
	if (C[i] == -1)
	{
		return 0;
	}
	if (dp[i] != -1)
	{
		return dp[i];
	}
	dp[i] = 1 + frec(C, C[i], dp);
	return dp[i];
}

int coppie(int N, int *C)
{

	int res = 0;
	int dp[N];
	for (int i = 0; i < N; i++)
	{
		dp[i] = -1;
	}

	for (int i = 0; i < N; i++)
	{
		if (dp[i] == -1)
		{
			dp[i] = frec(C, i, dp);
		}
	}
	for (int i = 0; i < N; i++)
	{
		res += dp[i];
	}

	return res;
}

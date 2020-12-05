int main()
{
	int *p;
	p = malloc(sizeof(int) * 5);
	int res;
	int min = 5;
	int max = 10;
	res = ft_ultimate_range(&p, min, max);
	if (res > 0)
	{
		for(int i = 0; i < res; i++)
			printf("%d ", p[i]);
		printf("\n");
	}
	else if (res == 0)
		printf("Null array");
	else if (res == -1)
		printf("Error!");
}
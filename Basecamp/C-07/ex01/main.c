int main()
{
	int *p;
	int min = 3;
	int max = 9;
	p = malloc((max - min) * sizeof(int));
	p = ft_range(min, max);
	if (p)
	{
		for(int i = 0; i < (max - min); i++)
			printf("%d ", p[i]);
		printf("\n");
	}
	else
		printf("Null array");
}
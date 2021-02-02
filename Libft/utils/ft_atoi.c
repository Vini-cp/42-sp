int		ft_atoi(const char *str)
{
	int i;
	int mult;
	int res;

	i = 0;
	mult = 1;
	res = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-' && mult == 1)
			mult = -1;
		else if (str[i] >= '0' && str[i] <= '9')
		{
			while (str[i] >= '0' && str[i] <= '9')
			{
				res = res * 10 + str[i] - '0';
				i++;
			}
			return (mult * res);
		}
		else
			return(0);
		i++;
	}
	return(0);
}

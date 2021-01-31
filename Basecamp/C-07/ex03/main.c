#include <stdio.h>

int main()
{
	char sep[] = " -";
	char *c;
	char *strs[] = {"I", "am", "your", "father", "!"};
	c = ft_strjoin(5, strs, sep);
	printf("%s\n", c);
}
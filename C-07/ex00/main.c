int main()
{
	char c[] = "TesteANDcmdeqD";
	char *dest;
	char *new;
	new = strdup(c);
	dest = ft_strdup(c);
	printf("%s\n", dest);
	printf("%s\n", new);
}
#include <stdlib.h>
#include <stdio.h>

int	ft_get_len(char *str, int i, char c)
{
	int	len;

	len = 0;
	while (str[i] != c && str[i++])
		len++;
	return (len);
}

int	ft_count_word(char *str, char c, int i)
{
	int	count;

	count = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			while (str[i] != c || str[i] == '\0')
				i++;
			count++;
		}
		i++;
	}
	return (count);
}

int	test(char *str, int i, char c)
{
	while (str[i])
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char	*str;

	len = 0;
	while (src[len])
		len++;
	str = (char*)malloc(sizeof(*str) * (len + 1));
	i = 0;
	while (i < len)
	{
		str[i] = src[i];
		i++;
	}
	return (str);
}

char	**ft_split(char *str, char c)
{
	char	**res;
	int		i;
	int		j;
	int		x;

	i = 0;
	j = 0;
	x = 0;
	if (test(str, i, c))
	{
		res = malloc(sizeof(char *) * 1 + 1);
		res[j++] = ft_strdup(str);
		res[j] = NULL;
		return (res);
	}
	printf("word = %d\n", ft_count_word(str, c, i));
	res = malloc(sizeof(char *) * ft_count_word(str, c, i) + 1);
	while (str[i])
	{
		while (str[i] == c)
			i++;
		printf("len %d\n", ft_get_len(str, i, c));
		res[j] = malloc(sizeof(char) * ft_get_len(str, i, c) + 1);
		if (str[i] != c && str[i])
		{
			while (str[i] != c && str[i])
			{
				printf("i = %d j = %d\n", i, j);
				res[j][x++] = str[i++];
			}
			res[j++][x] = '\0';
		}
		x = 0;
	}
	res[j] = NULL;
	return (res);
}

int	main(int argc, char **argv)
{
	char **res;
	int	i;

	if(argc != 3)
		return (0);
	i = 0;
	printf("str = [%s]\n c = [%c]\n", argv[1], argv[2][0]);
	res = ft_split(argv[1], 0);
//	res = ft_split(argv[1], argv[2][0]);
	while (res[i])
	{
		printf("[%d] %s\n", i, res[i]);
		i++;
	}
	system("leaks a.out");
}

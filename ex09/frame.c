#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*str;

	if (!s)
		return (NULL);
	s_len = strlen(s);
	if (len > s_len - start)
		len = s_len - start;
	if (start >= s_len)
		return (strdup(""));
	str = (char *) malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	memcpy(str, s + start, len);
	str[len] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	s1_len = strlen(s1);
	s2_len = strlen(s2);
	i = -1;
	result = (char *) malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result = memcpy(result, s1, s1_len);
	while (++i < s2_len)
		result[i + s1_len] = s2[i];
	result[s1_len + s2_len] = '\0';
	return (result);
}

static size_t	rows_count(char const *s, char c)
{
	size_t	i;
	size_t	rows;

	i = 0;
	rows = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			rows++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (rows);
}

static void	optimize_code(char const *s, char c, size_t *i, size_t *row_len)
{
	*row_len = 0;
	while (s[*i] && s[*i] == c)
		(*i)++;
	while (s[*i] && s[*i] != c)
	{
		(*i)++;
		(*row_len)++;
	}
}

static char	**free_all(char **t)
{
	int	i;

	i = -1;
	while (t[++i])
		free (t[i]);
	free (t);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	i;
	size_t	j;
	size_t	rows;
	size_t	row_len;

	if (!s)
		return (NULL);
	rows = rows_count(s, c);
	res = (char **) malloc(sizeof(char *) * (rows + 1));
	if (!res)
		return (NULL);
	j = 0;
	i = 0;
	while (s[i] && j < rows)
	{
		optimize_code(s, c, &i, &row_len);
		res[j++] = ft_substr(s, i - row_len, row_len);
		if (!res[j - 1])
			return (free_all(res));
	}
	res[j] = NULL;
	return (res);
}

char	*parse_args(int c, char **args)
{
	char	*str1;
	char	*tmp;
	int		i;

	i = 0;
	if (c != 1)
		str1 = ft_strjoin(args[0], " ");
	else
		str1 = strdup(args[0]);
	while (args[++i])
	{
		tmp = str1;
		str1 = ft_strjoin(tmp, args[i]);
		if (i < c - 1)
		{
			free(tmp);
			tmp = str1;
			str1 = ft_strjoin(tmp, " ");
		}
		free(tmp);
	}
	return (str1);
}

size_t longest(char **s)
{
	size_t len = 0;
	int i = -1;

	while (s[++i])
		if (len < strlen(s[i]))
			len = strlen(s[i]);
	return len;
}

void	print(char **s)
{
	int	i;
	int	j;
	int maxlen;
	
	maxlen = longest(s);
	i = -1;
	while (++i < maxlen + 4)
		printf("*");
	printf("\n");
	i = -1;
	while (s[++i])
	{
		j = -1;
		printf("* ");
		while (s[i][++j])
				printf("%c", s[i][j]);
		while (j++ <= maxlen)
			printf(" ");
		printf("*\n");
	}
	i = -1;
	while (++i < maxlen + 4)
		printf("*");
	printf("\n");
}

int	main(int c, char **v)
{
	char	*s;
	char	**strings;
	int		i;

	if (c < 2)
		return (1);
	i = -1;
	s = parse_args(c - 1, &v[1]);
	strings = ft_split(s, ' ');
	print(strings);
}


#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}


int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if (ft_strlen(s1) != ft_strlen(s2))
		return (-1);
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int correct_stack(int i, char **argv)
{
	if (ft_strcmp(argv[i], "1") == 0)
		return (1);
	return (0);
}

static int	select_strategy(char *argv)
{
	if (ft_strcmp(argv, "--simple") == 0 || ft_strcmp(argv, "--medium") == 0
		|| ft_strcmp(argv, "--complex") == 0
		|| ft_strcmp(argv, "--adaptive") == 0)
		return (1);
	return (0);
}

int	check_args(int argc, char **argv)
{
	int	ret;

	ret = -1;
	if (argc == 1)
		return (0);
	if (ft_strcmp(argv[1], "--bench") == 0 && argc > 2)
	{
		if (select_strategy(argv[2]) == 1 && argc > 3)
		{
			if (correct_stack(3, argv) == 1)
				ret = 321;
		}
		else if (correct_stack(2, argv) == 1)
			ret = 31;
	}
	else if (select_strategy(argv[1]) == 1)
	{
		if (correct_stack(2, argv) == 1)
			ret = 32;
	}
	else if (correct_stack(1, argv) == 1)
		ret = 3;
	return (ret);
}

int main(int argc, char **argv)
{
	printf("ret: %i\n", check_args(argc, argv));
}
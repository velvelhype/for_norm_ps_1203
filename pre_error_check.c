#include "push_swap.h"

void	error_case(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

long	custom_atoi(const char *str)
{
	long	sum;
	long	i;
	long	j;

	sum = 0;
	i = 0;
	j = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			j = j * -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		sum = (sum * 10) + str[i] - '0';
		i++;
	}
	if (j * sum > 2147483647 || j * sum < -2147483648)
		error_case();
	return ((long)j * sum);
}

void	digit_and_value_type_check(char **argv, int c)
{
	int	i;

	i = 0;
	if (ft_strlen(*(argv + c)) > 11)
		error_case();
	if (*(*(argv + c) + i) == '\0')
		error_case();
	if (*(*(argv + c) + i) == '-')
		i++;
	if (*(*(argv + c) + i) == '\0')
		error_case();
	while (*(*(argv + c) + i))
	{
		if (ft_isdigit(*(*(argv + c) + i)) == FALSE)
		{
			error_case();
		}
		i++;
	}
}

void	pre_error_check(int argc, char **argv)
{
	int	c;

	c = 1;
	if (argc < 2)
		error_case();
	while (*(argv + c))
	{
		digit_and_value_type_check(argv, c);
		c++;
	}
}

void	check_duplicates(t_list *list)
{
	t_list	*cur_list;

	list = list->next;
	cur_list = list->next;
	while (list->is_dummy == FALSE)
	{
		while (cur_list->is_dummy == FALSE)
		{
			if (list->value == cur_list->value)
				error_case();
			cur_list = cur_list->next;
		}
		list = list->next;
		cur_list = list->next;
	}
}

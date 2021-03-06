#include "push_swap.h"

void	free_lists(t_list *a_head, t_list *b_head)
{
	a_head = a_head ->prev;
	while (a_head->is_dummy == FALSE)
	{
		a_head = a_head->prev;
		free(a_head->next);
	}
	free(a_head);
	free(b_head);
}

void	free_copy(t_list *copy)
{
	copy = copy ->prev;
	while (copy->is_dummy == FALSE)
	{
		copy = copy->prev;
		free(copy->next);
	}
	free(copy);
}

void	is_int(t_list *a_head)
{
	a_head = a_head->next;
	while (a_head->is_dummy == FALSE)
	{
		a_head = a_head->next;
	}
}

void	post_error_check(t_list *a_head, t_list *b_head)
{
	check_duplicates(a_head);
	if (is_sorted(a_head) == TRUE)
	{
		free_lists(a_head, b_head);
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_list	*a_head;
	t_list	*a_copy;
	t_list	*b_head;

	a_head = NULL;
	b_head = NULL;
	pre_error_check(argc, argv);
	a_head = prepare_a_list(argc, argv, a_head);
	a_copy = prepare_a_list(argc, argv, a_head);
	tend_values(a_head, a_copy);
	free_copy(a_copy);
	b_head = prepare_b_list(b_head);
	post_error_check(a_head, b_head);
	if (len_list(a_head) == 2)
		two_sort(a_head);
	else if (len_list(a_head) <= 3)
		three_sort(a_head);
	else if (len_list(a_head) <= 5)
		five_sort(a_head, b_head);
	else
		start_q_sort(a_head, b_head);
	free_lists(a_head, b_head);
	return (0);
}

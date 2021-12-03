#include "push_swap.h"

t_list	*find_min(t_list *list)
{
	t_list	*min_list;

	list = list->next;
	min_list = list;
	list = list->next;
	while (list->is_dummy == FALSE)
	{
		if (list->value < min_list->value)
			min_list = list;
		list = list->next;
	}
	return (min_list);
}

int	len_list(t_list	*head)
{
	int	count;

	count = 0;
	head = head->next;
	while (head->is_dummy == FALSE)
	{
		count++;
		head = head->next;
	}
	return (count);
}

int	diff_rotate(t_list	*head, t_list	*min)
{
	int	distance;

	distance = 0;
	head = head->next;
	while (1)
	{
		if (head == min)
			return (distance);
		head = head->next;
		distance++;
	}
}

int	diff_r_rotate(t_list *head, t_list *min)
{
	int	distance;

	distance = 0;
	head = head->prev;
	while (1)
	{
		if (head == min)
			return (distance);
		head = head->prev;
		distance++;
	}
}

void	push_min(t_list *a_head, t_list *b_head)
{
	t_list	*min_list;
	int		use_rotate;

	min_list = find_min(a_head);
	if (diff_rotate(a_head, min_list) <= diff_r_rotate(a_head, min_list))
		use_rotate = TRUE;
	else
		use_rotate = FALSE;
	while (1)
	{
		if (a_head->next == min_list)
		{
			push(a_head, b_head);
			break ;
		}
		if (use_rotate == TRUE)
			rotate(a_head);
		else
			r_rotate(a_head);
	}
}

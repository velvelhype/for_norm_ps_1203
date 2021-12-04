#include "push_swap.h"

int	is_sorted(t_list *a_head)
{
	a_head = a_head->next;
	while ((a_head->next)->is_dummy == FALSE)
	{
		if (a_head->value > (a_head->next)->value)
			return (FALSE);
		a_head = a_head->next;
	}
	return (TRUE);
}

void	two_sort(t_list *dum)
{
	t_list	*one;
	t_list	*two;

	one = dum->next;
	two = one->next;
	if (one->value > two->value)
		swap(dum);
}

void	three_control(t_list *dum, t_list *one, t_list *two, t_list *three)
{
	if (one->value < two->value && one->value < three->value)
	{
		if (two->value > three->value)
		{
			swap(dum);
			rotate(dum);
		}
	}
	else if (one->value > two->value && one->value > three->value)
	{
		rotate(dum);
		if (two->value > three->value)
			swap(dum);
	}
	else if ((two->value + three->value) / 2 == one->value)
	{
		if (one->value > two->value)
			swap(dum);
		else
			r_rotate(dum);
	}
}

void	three_sort(t_list *dum)
{
	t_list	*one;
	t_list	*two;
	t_list	*three;

	one = dum->next;
	two = one->next;
	three = two->next;
	three_control(dum, one, two, three);
}

void	five_sort(t_list *a_head, t_list *b_head)
{
	while (len_list(a_head) > 3)
	{
		push_min(a_head, b_head);
	}
	three_sort(a_head);
	while (len_list(b_head) != 0)
	{
		push(b_head, a_head);
	}
	if ((a_head->next)->value > ((a_head->next)->next)->value)
		swap(a_head);
}

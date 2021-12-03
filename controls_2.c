#include "push_swap.h"

void	swap(t_list	*head)
{
	int	save;

	save = (head->next)->value;
	(head->next)->value = ((head->next)->next)->value;
	((head->next)->next)->value = save;
	if (head->is_dummy == TRUE_A)
		write(1, "sa\n", 3);
	else if (head->is_dummy == TRUE_B)
		write(1, "sb\n", 3);
}

void	ss(t_list *a_head, t_list *b_head)
{
	int	save_a;
	int	save_b;

	save_a = (a_head->next)->value;
	(a_head->next)->value = ((a_head->next)->next)->value;
	((a_head->next)->next)->value = save_a;
	save_b = (b_head->next)->value;
	(b_head->next)->value = ((b_head->next)->next)->value;
	((b_head->next)->next)->value = save_b;
	write(1, "ss\n", 3);
}

void	rr(t_list *a_head, t_list *b_head)
{
	t_list	*cut_a;
	t_list	*cut_b;

	cut_a = cut_out_list(a_head->next);
	implant(cut_a, a_head->prev);
	cut_b = cut_out_list(b_head->next);
	implant(cut_b, b_head->prev);
	write(1, "rr\n", 3);
}

void	rrr(t_list *a_head, t_list *b_head)
{
	t_list	*cut_a;
	t_list	*cut_b;

	cut_a = cut_out_list(a_head->prev);
	implant(cut_a, a_head);
	cut_b = cut_out_list(b_head->prev);
	implant(cut_b, b_head);
	write(1, "rrr\n", 4);
}

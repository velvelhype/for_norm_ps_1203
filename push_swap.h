#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"
# define FALSE 0
# define TRUE 1
# define TRUE_A 3
# define TRUE_B 4
# define CLEANING_VOL 15

typedef struct s_list
{
	struct s_list	*next;
	struct s_list	*prev;
	long			value;
	int				is_dummy;
}	t_list;

void	error_case(void);
void	pre_error_check(int argc, char **argv);
long	custom_atoi(const char *str);
t_list	*append(void);
t_list	*prepare_a_list(int argc, char **argv, t_list *a_head);
t_list	*prepare_b_list(t_list *b_head);
void	tend_values(t_list *list, t_list *ranking);
void	check_duplicates(t_list *list);
void	swap(t_list *head);
void	push(t_list *a_head, t_list *b_head);
void	rotate(t_list *head);
void	r_rotate(t_list *head);
t_list	*cut_out_list(t_list *cut);
void	implant(t_list *pushing_list, t_list *dst);
int		is_sorted(t_list *a_head);
void	two_sort(t_list *dum);
void	three_sort(t_list *dum);
void	five_sort(t_list *a_head, t_list *b_head);
void	push_min(t_list *a_head, t_list *b_head);
t_list	*find_min(t_list *list);
int		len_list(t_list *head);
void	start_q_sort(t_list *a_head, t_list *b_head);
void	process_b(t_list *a_head, t_list *b_head);
void	ruminant(int ruminant_count, t_list *a_head, t_list *b_head);

#endif
#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

#define FALSE 0
#define TRUE 1
#define TRUE_A 3
#define TRUE_B 4
#define CLEANING_VOL 15

typedef struct t_list
{
    struct t_list *next;
    struct t_list *prev;
    long value;
    int is_dummy;
    int sort_status;
} t_list;

//pre_error_check
void    error_case();
void    pre_error_check(int argc, char **argv);
long    custom_atoi(const char *str);

//preparetions
t_list* append();
t_list* prepare_a_list(int argc, char ** argv, t_list *a_head);
t_list* prepare_b_list(t_list *b_head);
void    tend_values(int len, t_list* list, t_list *ranking);

//post_process
void    check_duplicates(t_list *list);

//controls
void    swap(t_list* head);
void    push(t_list* a_head, t_list* b_head);
void    rotate(t_list *head);
void    r_rotate(t_list *head);
t_list* cut_out_list(t_list *cut);
void    implant(t_list *pushing_list, t_list *dst);

//sort
int     is_sorted(t_list *a_head);
void    two_sort(t_list *dum);
void    three_sort(t_list *dum);
void    five_sort(t_list    *a_head, t_list *b_head);

//funcs_for_sort
void    push_min(t_list    *a_head, t_list *b_head);
t_list* find_min(t_list *list);
int     len_list(t_list*    head);

// 2
void    start_q_sort(t_list *a_head, t_list *b_head);
void    process_b(t_list *a_head, t_list *b_head);
void    ruminant(int ruminant_count, t_list *a_head, t_list *b_head);

#endif
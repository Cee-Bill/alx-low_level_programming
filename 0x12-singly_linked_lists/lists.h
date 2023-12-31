#ifndef LIST_H
#define LIST_H

/**
 * struct list_t - singly list list
 * @str: string element
 * @len: length of string
 * @next: pointer to the next node
 */

struct list_t
{
	char *str;
	unsigned int len;
	struct list_t *next;
};

typedef struct list_t list_t;

int _putchar(char c);
/*unsigned int str_len(const char *c);*/

size_t print_list(const list_t *h);
size_t list_len(const list_t *h);
list_t *add_node(list_t **head, const char *str);
list_t *add_node_end(list_t **head, const char *str);
void free_list(list_t *head);

#endif /* LIST_H */

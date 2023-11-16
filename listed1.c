#include "naomi.h"
/**
 * node_starts_with - searches for a node in a
 * list starting with a specified prefix.
 * @node: A pointer to the head of the list.
 * @prefix: The string to match as a prefix.
 * @c: The next character after the prefix to match.
 * Return: Returns either NULL if no match is
 * found or a pointer to the matching node.
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *v = NULL;

	while (node)
	{
		v = starts_with(node->str, prefix);
		if (v && ((c == -1) || (*v == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}
/**
 * get_node_index - retrieves the index of a given node within a linked list.
 * @head: A pointer to the head of the list.
 * @node: A pointer to the specific node
 * whose index needs to be determined.
 * Return:  Returns either -1 if the node is not
 * found or the index of the node in the list
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t g = 0;

	while (head)
	{
		if (head == node)
			return (g);
		head = head->next;
		g++;
	}
	return (-1);
}
/**
 * list_len - calculates the length of a linked
 * list starting from a given node.
 * @h:  A pointer to the next node in the list.
 * Return:Returns the size or length of the linked list.
 */
size_t list_len(const list_t *h)
{
	size_t o = 0;

	while (h)
	{
		h = h->next;
		o++;
	}
	return (o);
}
/**
 * list_to_strings - Returns array of strings of the list->str
 * @head: ptr to next node
 *
 * Return: strings Arrays
 */
char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t u = list_len(head), i;
	char **strs;
	char *str;

	if (!head || !u)
		return (NULL);
	strs = malloc(sizeof(char *) * (u + 1));
	if (!strs)
		return (NULL);
	for (u = 0; node; node = node->next, u++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (i = 0; i < u; i++)
				free(strs[i]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[u] = str;
	}
	strs[u] = NULL;
	return (strs);
}
/**
 * print_list - displays the elements of a linked list of type list_t.
 * @h: A pointer to the next node in the list.
 * Return: Returns the size of the list
 */
size_t print_list(const list_t *h)
{
	size_t r = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		r++;
	}
	return (r);
}

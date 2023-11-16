#include "naomi.h"
/**
 * free_list -  deallocates memory for all nodes in a linked list.
 * @head_ptr: The address of a pointer to the head node
 * Return: This function does not return a value (void).
 */
void free_list(list_t **head_ptr)
{
	list_t *node, *next_node, *head;

	if (!head_ptr || !*head_ptr)
		return;
	head = *head_ptr;
	node = head;
	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}
	*head_ptr = NULL;
}
/**
 * add_node - adds a new node to the beginning of a linked list.
 * @head: The address of a pointer to the head node.
 * @str: The string field of the new node
 * @num: The index of the node
 * Return: Returns the size of the list
 */
list_t *add_node(list_t **head, const char *str, int num)
{
	list_t *duck;

	if (!head)
		return (NULL);
	duck = malloc(sizeof(list_t));
	if (!duck)
		return (NULL);
	_memset((void *)duck, 0, sizeof(list_t));
	duck->num = num;
	if (str)
	{
		duck->str = _strdup(str);
		if (!duck->str)
		{
			free(duck);
			return (NULL);
		}
	}
	duck->next = *head;
	*head = duck;
	return (duck);
}
/**
 * add_node_end - appends a new node to the end of a linked list.
 * @head: The address of a pointer to the head node.
 * @str: The string field of the new node.
 * @num: The index of the node.
 *
 * Return: Returns the size of the list.
 */
list_t *add_node_end(list_t **head, const char *str, int num)
{
	list_t *old_shoe, *egg;

	if (!head)
		return (NULL);

	egg = *head;
	old_shoe = malloc(sizeof(list_t));
	if (!old_shoe)
		return (NULL);
	_memset((void *)old_shoe, 0, sizeof(list_t));
	old_shoe->num = num;
	if (str)
	{
		old_shoe->str = _strdup(str);
		if (!old_shoe->str)
		{
			free(old_shoe);
			return (NULL);
		}
	}
	if (egg)
	{
		while (egg->next)
			egg = egg->next;
		egg->next = old_shoe;
	}
	else
		*head = old_shoe;
	return (old_shoe);
}
/**
 * print_list_str - displays the string elements of
 * a linked list of type list_t.
 * @h: Pointer to the very first node.
 *
 * Return: Pointer to the first node.
 */

size_t print_list_str(const list_t *h)
{
	size_t a = 0;

	while (h)
	{
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		a++;
	}
	return (a);
}
/**
 * delete_node_at_index - removes a node from a linked
 * list at a specified index.
 * @head: The address of a pointer to the first node.
 * @index: The index of the node to be deleted.
 * Return: Returns 1 upon success, and 0 otherwise.
 */

int delete_node_at_index(list_t **head, unsigned int index)
{
	list_t *node, *prev_node;
	unsigned int r = 0;

	if (!head || !*head)
		return (0);

	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *head;
	while (node)
	{
		if (r == index)
		{
			prev_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		r++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}

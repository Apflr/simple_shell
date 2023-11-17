#include "naomi.h"

/**
 * list_len - finds out length of linked list
 * @h: pointer to next
 *
 * Return:  size
 */
size_t list_len(const list_t *h)
{
        size_t z = 0;

        while (h)
        {
                h = h->next;
                z++;
        }
        return (z);
}

/**
 * list_to_strings - Returns vector of str of the list->str
 * @head: pointer to next node
 *
 * Return: str vector
 */
char **list_to_strings(list_t *head)
{
        list_t *node = head;
        size_t z = list_len(head), x;
        char **strs;
        char *str;

        if (!head || !z)
                return (NULL);
        strs = malloc(sizeof(char *) * (z + 1));
        if (!strs)
                return (NULL);
        for (z = 0; node; node = node->next, z++)
        {
                str = malloc(_strlen(node->str) + 1);
                if (!str)
                {
                        for (x = 0; x < z; x++)
                                free(strs[x]);
                        free(strs);
                        return (NULL);
                }

                str = _strcpy(str, node->str);
                strs[z] = str;
        }
        strs[z] = NULL;
        return (strs);
}


/**
 * print_list - writes  element of a list_t linked list
 * @h: pointer to next 
 *
 * Return:list size
 */
size_t print_list(const list_t *h)
{
        size_t z = 0;

        while (h)
        {
                _puts(convert_number(h->num, 10, 0));
                _putchar(':');
                _putchar(' ');
                _puts(h->str ? h->str : "(nil)");
                _puts("\n");
                h = h->next;
                z++;
        }
        return (z);
}

/**
 * node_starts_with - takes back node  with prefix
 * @node: list head
 * @prefix: Str  match
 * @c: next char after prefix to match
 *
 * Return: Null or match node
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
        char *p = NULL;

        while (node)
        {
                p = starts_with(node->str, prefix);
                if (p && ((c == -1) || (*p == c)))
                        return (node);
                node = node->next;
        }
        return (NULL);
}

/**
 * get_node_index - finds index of a node
 * @head: points to list head
 * @node: Pointer to the node
 *
 * Return: -1 or Index node
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
        size_t z = 0;

        while (head)
        {
                if (head == node)
                        return (z);
                head = head->next;
                z++;
        }
        return (-1);
}


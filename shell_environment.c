#include "shellenv.h"

/**
 * build_env_array - Build an environment variable array from a linked list
 * @ptr: Pointer to the linked list of environmental variables
 *
 * Return: A dynamically allocated array of environmental variable strings
 *         (in the format "KEY=VALUE") terminated with a NULL pointer, or
 *         NULL if memory allocation fails or if the linked list is empty.
 */
char **build_env_array(shell_dict_t *ptr)
{
    char **env;
    size_t length = 0;
    shell_dict_t *temp = ptr;

    /*loop througth the list to get length*/
    while (temp)
    {
        temp = temp->link;
        ++length;
    }

    env = malloc(sizeof(char *) * (length + 1));
    if (!env)
        return (NULL);
    for (length = 0; ptr; ptr = ptr->link)
        env[length++] = str_concat(NULL, "=", ptr->key, ptr->value);
    env[length] = NULL;

    return (env);
}

/**
 * build_dict_from_env - Build a shell dictionary from environment variables.
 * @head_ptr: Pointer to the head of the shell dictionary.
 * @env: Array of environment variables.
 * @head_ptr: Pointer to the head of the shell dictionary.
 * Return: A pointer to the populated shell dictionary on success, or NULL on failure.
 */
shell_dict_t *build_dict_from_env(shell_dict_t **head_ptr, char **env)
{
   shell_dict_t *tail;
	char *env_str;
	ssize_t key_len;

	if (!*env)
		return (*head_ptr);

	env_str = _strdup(*env);
	if (!env_str)
		return (NULL);

	key_len = _strchr(*env, '=');

	if (key_len == -1)
		return (NULL);

	env_str[key_len] = '\0';
	tail = add_dict_to_the_end(head_ptr, env_str, env_str + key_len + 1);
	free(env_str);

	return (build_dict_from_env(&tail, env + 1));
}

/**
 * build_dict_from_env_caller - Build a shell dictionary from environment variables.
 * @env: Array of environment variables.
 * Return: A pointer to the populated shell dictionary on success, or NULL on failure.
 */
shell_dict_t *build_dict_from_env_caller(char **env)
{
    shell_dict_t *head = NULL;
    if (!(env && *env))
       return (NULL);
    
    if (!build_dict_from_env(&head, env))
        free_dictionary(&head);
    return (head);
}
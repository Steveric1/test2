#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "shell.h"

/**
 * init_prmpt - initilize the shell prompt
 * @av: argument vector
 * @ac: argument counter
 * Return: pointer to the calling function
*/
store_info_t *init_prmpt(int ac, char **av)
{
    static store_info_t my_info;
    char *errorno = NULL;

    my_info.argc = ac;
    my_info.argv = av;
    my_info.fileno = STDIN_FILENO;

    if (ac > 1)
    {
        my_info.file = av[1];
        my_info.fileno = open(my_info.file, O_RDONLY);
        
        if (my_info.fileno == -1)
        {
            errorno = str_concat(NULL, " ", "Can't open", my_info.file);
            handle_error(*av, my_info.line_read, errorno, NULL);
            free_all(1, errorno);
            my_info.status = 127;
            exit(release_store_infomation(&my_info));
        }
    }
    my_info.interactive = isatty(my_info.fileno);
    my_info.p_pid = getpid();
    my_info.cwd_s = getcwd(NULL, 0);
    my_info.env = build_dict_from_env_caller(environ);
    return (&my_info);
}

/**
 * release_store_infomation - Release memory and reset store_info structure.
 * @store_info: Pointer to the store_info_t structure to release.
 * Return: The status code stored in the store_info structure after cleanup.
 */
int release_store_infomation(store_info_t *store_info)
{
    free_all(3, store_info->line, store_info->cwd_s, store_info->execute);
    store_info->line = my_getline(-1);
    release_mem(&store_info->tokens);
    store_info->cwd_s = NULL;
    store_info->execute = NULL;
    free_dictionary(&store_info->env);
    free_dir(&store_info->path);
    free_command_lst(&store_info->cmd);
    return (store_info->status);
}
/*
** EPITECH PROJECT, 2021
** mini_shell.c
** File description:
** function
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <dirent.h>
#include "my.h"
#include "init.h"
#include "com.h"
#include "struct.h"

int shell(char **env, info_t *f, int nb);

static int print_error(int wstat)
{
    if (wstat == 136) {
        write(2, &"Floating exception (core dumped)\n", 33);
        return 0;
    }
    if (wstat == 139) {
        write(2, &"Segmentation fault (core dumped)\n", 33);
        return 0;
    }
    return 0;
}

void child_issues(pid_t child, info_t *f)
{
    pid_t value = 0;
    int wstat = 0;

    value = waitpid(child, &wstat, 0);
    if (value == -1)
        shell(f->new_env, f, 1);
    if (WIFEXITED(wstat))
        shell(f->new_env, f, WEXITSTATUS(wstat));
    else {
        print_error(wstat);
        shell(f->new_env, f, wstat);
    }
}

int exec(char *path, info_t *f)
{
    pid_t child = 0;
    

    child = fork();
    if (child == -1) {
        write(2, &"Segmentation fault\n", 19);
        shell(f->new_env, f, 139);
    }
    if (child == 0) {
        if (execve(path, f->com, f->new_env) == -1)
        if (access(path, X_OK) == -1 || opendir(path) != NULL) {
            write(2, path, my_strlen(path));
            write(2, &": Permission denied.\n", 21);
            shell(f->new_env, f, 1);
        }    
    }
    else
        child_issues(child, f);
    return 0;
}

int shell(char **env, info_t *f, int nb)
{
    char *str = NULL;
    char *tmp = NULL;

    f->new_env = env;
    while (1) {
        if ((tmp = get_paths(f)) == NULL)
            f->path = f->valid_path;
        else {
            f->path = my_str_to_word_array_shell(tmp);
            f->path = add_slash(f->path);
        }
        if ((str = get_com()) == NULL)
            exit(nb);
        str = valid_com(str, f);
        f->com = my_str_to_word_array(str);
        nb = exe_com(f);
    }
    return nb;
}

int main(int argc, char **argv, char **env)
{
    info_t f = {0};
    int res = 0;
    char *tmp = NULL;

    if (argc > 1)
        return 84;
    if (argv[0] == NULL)
        return 84;
    if (env[0] == NULL)
        return 84;
    f.new_env = env;
    tmp = get_paths(&f);
    f.valid_path = my_str_to_word_array_shell(tmp);
    f.valid_path = add_slash(f.valid_path);
    res = shell(env, &f, 0);
    return res;
}

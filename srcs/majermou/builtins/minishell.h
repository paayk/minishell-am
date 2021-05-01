/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majermou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 13:46:55 by majermou          #+#    #+#             */
/*   Updated: 2021/04/11 13:47:01 by majermou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include <sys/param.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <term.h>
#include <termios.h>
#include <curses.h>

# define ARRW_UP 4283163
# define ARRW_DOWN 4348699
# define BACK_SPACE 127
# define ENTER 10

typedef struct          s_cmd_list
{
    char	            **args;
    int		            nbrpipe;
    int                 iterator;
    struct s_cmd_list   *next;
}                       t_cmd_list;

typedef struct          s_envlist
{
    char	            **vars;
    char                **envp;
    char                *line;
    char                **history;
    int                 status;
}                       t_envlist;

int                     g_ret;




size_t                  ft_strlen(const char *s);
size_t                  ft_strlcpy(char *dst, const char *src, size_t size);
int                     ft_strncmp(const char *s1, const char *s2, size_t n);
char	                *ft_strjoin(char const *s1, char const *s2);
int                     ft_strcmp(const char *s1, const char *s2);
char                    **ft_split(char const *s, char c);

void	        cleanup(char **arr, int limit);
int             array_lenght(char **arr);
unsigned int	random_num_generator(int range);
int             str_copying(char **dst, char *src, int index);
int             ft_isalpha(int c);
int             ft_isalnum(int c);
int             is_valid_id(char *id);
int             is_equalkey(char *str);

int			    search_var(t_envlist *envlist, char *var);
int	            replace_var(t_envlist *envlist,int index,char *new_var);
int	            addto_envlist(t_envlist *envlist, char *new_var);
int	            rmfrom_envlist(t_envlist *envlist, char *rm_var);
int	            env_varsdup(t_envlist *envlist, char **envp);
int             builtin_unset(t_cmd_list *cmd, t_envlist *envlist);
int             builtin_export(t_cmd_list *cmd, t_envlist *envlist);
int             builtin_env(t_envlist *envlist);

int             builtin_pwd(void);
int             builtin_cd(t_envlist *envlist, t_cmd_list *cmd);
char            **ft_split(char const *s, char c);
int             is_valid_id0(char *id);
int			    insert_var(t_envlist *envlist, char *var);

char	        *ft_strdup(const char *s);
int             print_envlist(t_envlist *envlist);
void            printing(char **arr);
void            sorting(char **arr);

int	            check_homepath(t_envlist *envlist, t_cmd_list *cmd);
int             builtin_exit(t_cmd_list *cmd, int status);
int             builtin_echo(t_cmd_list *cmd);
int             handle_redirection(t_cmd_list *command);
int             is_redir(t_cmd_list *cmd);
int             execute_cmd(t_cmd_list *cmd, t_envlist *envlist);
int	            isbuiltin(t_cmd_list *command);
int	            call_builtin(t_cmd_list *cmd, t_envlist *envlist);
char            *get_home_path(char **args, char **envp);
void            sig_handle(int sig);




int     ft_putstrs(char *str);
int     ft_putchars(int c);
int     addToline(t_envlist *envlist, char buff);
int     removeFromline(t_envlist *envlist);
int     addTohistory(t_envlist *envlist);
void    handle_arrawkeys(t_envlist *envlist, long buff, int *curs, int *index);
int     handleKeys(t_envlist *envlist, long buff, int *curs, int *index);
int     readline(t_envlist *envlist);


#endif
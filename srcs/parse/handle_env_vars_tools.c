/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_env_vars_tools.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 14:01:12 by abdait-m          #+#    #+#             */
/*   Updated: 2021/04/30 16:24:46 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	_isspec_(char c)
{
	if (c == '_' || c == '@' || c == '&' || c == '!' || c == '#')
		return (1);
	return (0);
}

void	_push_back_string_(char *buff, int index, char *fill, int size)
{
	while (*fill && size > 0)
	{
		buff[index++] = *fill++;
		size--;
	}
}

void	_count_env_vars_(t_mp *prs)
{
	prs->count = 0;
	prs->j = ++prs->i;
	while ((ft_isalpha(prs->buff[prs->j]) || ft_isdigit(prs->buff[prs->i]))
		&& prs->buff[prs->j++])
		prs->count++;
	prs->temp = (char *)malloc(sizeof(char) * (prs->count + 1));
	prs->j = 0;
	while ((ft_isalpha(prs->buff[prs->i]) || ft_isdigit(prs->buff[prs->i]))
		&& prs->buff[prs->i])
		prs->temp[prs->j++] = prs->buff[prs->i++];
	prs->temp[prs->j] = '\0';
	prs->env = getenv(prs->temp);
	if (prs->env)
		prs->counter += ft_strlen(prs->env);
	free(prs->temp);
	prs->temp = NULL;
}

void	_copy_dollar_digits_(t_mp *prs)
{
	if (prs->buff[++prs->i] == 48)
	{
		_push_back_string_(prs->global, prs->g, "bash", 4);
		prs->g +=4;
		prs->i++;
	}
	else
		prs->i++;
}

void	_copy_env_vars_(t_mp *prs)
{
	prs->count = 0;
	prs->j = ++prs->i;
	while ((ft_isalpha(prs->buff[prs->j]) || ft_isdigit(prs->buff[prs->i]))
		&& prs->buff[prs->j++])
		prs->count++;
	prs->temp = (char *)malloc(sizeof(char) * (prs->count + 1));
	prs->j = 0;
	while ((ft_isalpha(prs->buff[prs->i]) || ft_isdigit(prs->buff[prs->i]))
		&& prs->buff[prs->i])
		prs->temp[prs->j++] = prs->buff[prs->i++];
	prs->temp[prs->j] = '\0';
	prs->env = getenv(prs->temp);
	if (prs->env)
	{
		prs->count = ft_strlen(prs->env);
		_push_back_string_(prs->global, prs->g, prs->env, prs->count);
		prs->g += prs->count;
	}
	free(prs->temp);
	prs->temp = NULL;
}

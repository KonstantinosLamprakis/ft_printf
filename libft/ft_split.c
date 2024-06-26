/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:14:19 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/08 17:11:38 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_result(char const *str, char sep, char **result);
static void	free_mem(int k, char	**result);
static char	*get_str(char const *str, int start, int end);
static int	count_seps(char const *str, char sep);

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		k;
	int		i;

	result = malloc((count_seps(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	k = get_result(s, c, result);
	i = 0;
	while (i < k)
	{
		if (result[i] == NULL)
		{
			free_mem(k, result);
			free(result);
			return (NULL);
		}
		i++;
	}
	result[k] = NULL;
	return (result);
}

static void	free_mem(int k, char	**result)
{
	int	i;

	i = 0;
	while (i < k)
	{
		if (result[i] != NULL)
			free(result[i]);
		i++;
	}
}

static char	*get_str(char const *str, int start, int end)
{
	char	*result;
	int		i;

	i = 0;
	result = malloc((end - start + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (start < end)
	{
		result[i] = str[start];
		start++;
		i++;
	}
	result[i] = '\0';
	return (result);
}

static int	count_seps(char const *str, char sep)
{
	int	i;
	int	sep_c;

	i = 0;
	sep_c = 0;
	while (str[i] != '\0' && str[i] == sep)
		i++;
	if (str[i] != '\0')
		sep_c++;
	while (str[i] != '\0')
	{
		if (str[i] == sep && str[i + 1] != sep && str[i + 1] != '\0')
			sep_c++;
		i++;
	}
	return (sep_c);
}

static int	get_result(char const *str, char sep, char **result)
{
	int	i;
	int	k;
	int	start;
	int	is_sep;

	i = 0;
	start = 0;
	k = 0;
	is_sep = 1;
	while (str[i] != '\0')
	{
		is_sep = (str[i] == sep);
		if (is_sep)
		{
			if (start != i)
				result[k++] = get_str(str, start, i);
			start = i + 1;
		}
		i++;
	}
	if (!is_sep)
		result[k++] = get_str(str, start, i);
	return (k);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char **result;
// 	result = ft_split("....This.is.a.fucking.", '.');
// 	// result = ft_split("a  a  a", ' ');
// 	while (*result != NULL)
// 	{
// 		printf("%s\n", *result);
// 		result++;
// 	}
// }

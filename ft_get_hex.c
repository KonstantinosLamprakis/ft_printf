/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:41:39 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/12 12:48:59 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_digits(unsigned int num);
static void	get_hex(unsigned int nbr, int upper_case, char *result);
static void	str_revert(char *str);

char	*print_x(va_list par_list, char c)
{
	int		ch_num;
	char	*result;
	int		nbr;

	nbr = va_arg(par_list, ssize_t);
	ch_num = (count_digits(nbr));
	result = malloc((count_digits(nbr) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	if (c == 'x')
		get_hex(nbr, 0, result);
	else
		get_hex(nbr, 1, result);
	str_revert(result);
	return (result);
}

static void	str_revert(char *str)
{
	char	*temp;
	int		i;
	int		j;

	temp = malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!temp)
		return ;
	i = 0;
	while (str[i] != '\0')
	{
		temp[i] = str[i];
		i++;
	}
	i--;
	j = 0;
	while (i >= 0)
	{
		str[j++] = temp[i];
		i--;
	}
	free(temp);
}

static void	get_hex(unsigned int nbr, int upper_case, char *result)
{
	static char	upper_digits[] = "0123456789ABCDEF";
	static char	lower_digits[] = "0123456789abcdef";

	if (nbr >= 16)
		get_hex((nbr / 16), upper_case, result + 1);
	if (upper_case)
		*result = upper_digits[nbr % 16];
	else
		*result = lower_digits[nbr % 16];
}

static int	count_digits(unsigned int num)
{
	int	result;

	result = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		result += 1;
		num /= 16;
	}
	return (result);
}
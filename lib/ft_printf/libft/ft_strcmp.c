/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtaboada <rtaboada@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:09:18 by rtaboada          #+#    #+#             */
/*   Updated: 2024/08/30 21:22:34 by rtaboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*us1;
	unsigned char	*us2;

	i = 0;
	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	while (us1[i] && us2[i] && us1[i] == us2[i])
		i++;
	if (!us1[i] && !us2[i])
		return (0);
	if (!us1[i] || !us2[i])
		return (-1);
	return (us1[i] - us2[i]);
}

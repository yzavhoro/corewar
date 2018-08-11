/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtupikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 08:30:52 by mtupikov          #+#    #+#             */
/*   Updated: 2018/07/28 14:55:11 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strdup(const char *str)
{
	char	*dst;
	size_t	len;

	len = ft_strlen(str);
	dst = ft_strnew(len);
	if (!dst)
		return (NULL);
	while (len--)
		dst[len] = str[len];
	return (dst);
}

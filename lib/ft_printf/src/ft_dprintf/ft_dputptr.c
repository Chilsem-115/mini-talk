/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dputptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itamsama <itamsama@student.42.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:35:15 by itamsama          #+#    #+#             */
/*   Updated: 2025/03/22 23:51:26 by itamsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

void	ft_dputptr(int fd, va_list args, int *count)
{
	void	*ptr;

	ptr = va_arg(args, void *);
	if (ptr == NULL)
		*count += ft_dputstr(fd, "(nil)");
	else
	{
		*count += ft_dputstr(fd, "0x");
		*count += ft_dputhexa(fd, (unsigned long)ptr, 'a');
	}
}

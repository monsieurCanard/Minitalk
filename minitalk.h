/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:35:29 by marvin            #+#    #+#             */
/*   Updated: 2023/11/29 19:35:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>
# include <string.h>
# include <stdio.h>
# include <signal.h>
# include <sys/types.h>

typedef struct my_char
{
	int		nb_bits;
	char	*binary;
}	t_my_char;
void	*ft_calloc(size_t nb, size_t size);
int		ft_atoi(char *str);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
void	ft_bzero(void *s, size_t n);
int		ft_printf(const char *format, ...);

#endif
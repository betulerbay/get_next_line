/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berbay <berbay@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 21:36:00 by berbay            #+#    #+#             */
/*   Updated: 2023/02/21 16:57:59 by berbay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

int		ft_n(char *s1);

char	*ft_strjoin(char *s1, char *s2);

int		ft_strlen(char *str);

char	*ft_new_line(char *str);

char	*ft_new_str(char *str);

char	*get_next_line(int fd);

#endif

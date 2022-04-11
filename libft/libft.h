/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taejkim <taejkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 17:19:00 by taejkim           #+#    #+#             */
/*   Updated: 2022/04/11 17:52:25 by taejkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

int		ft_isdigit(int c);

void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);

size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin_free_s1(char *s1, char *s2);

void	*ft_calloc(size_t count, size_t size);
char	**ft_split(char const *s, char c);

#endif

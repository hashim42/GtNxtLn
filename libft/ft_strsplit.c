/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hazzout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 21:42:55 by hazzout           #+#    #+#             */
/*   Updated: 2016/11/24 18:25:03 by hazzout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		wnbr(char const *s, char c)
{
	int		nbw;
	char	prv;
	char	cur;

	nbw = 0;
	prv = c;
	while (*s != '\0')
	{
		cur = *s;
		if (cur != c && prv == c)
			nbw++;
		prv = cur;
		s++;
	}
	return (nbw);
}

static char		**wpop(const char *s, int nbw, int nbc, char **tab)
{
	int i;

	tab[nbw - 1] = (char *)malloc(sizeof(char) * (nbc + 1));
	if (tab[nbw - 1] == NULL)
		return (NULL);
	i = 0;
	while (i < nbc)
	{
		tab[nbw - 1][i] = s[i];
		i++;
	}
	tab[nbw - 1][i] = '\0';
	return (tab);
}

static char		**wfetch(const char *s, int c, char **tab)
{
	int nbw;
	int nbc;
	int i;

	nbw = 0;
	nbc = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		nbw = nbw + (s[i] != c && s[i] != '\0' ? 1 : 0);
		nbc = s[i] != c && s[i] != '\0' ? 0 : nbc;
		while (s[i] != c && s[i] != '\0')
		{
			nbc++;
			i++;
		}
		if (s[i - 1] != c)
			if (wpop(s + (i - nbc), nbw, nbc, tab) == NULL)
				return (NULL);
	}
	return (tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		wnb;

	if (s == NULL)
		return (NULL);
	wnb = wnbr(s, c);
	tab = (char **)malloc(sizeof(char *) * (wnb + 1));
	if (tab == NULL)
		return (NULL);
	if (wfetch(s, c, tab) == NULL)
		return (NULL);
	tab[wnb] = 0;
	return (tab);
}

#include "ft_utils.h"

int	ft_is_digit(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!(s[i] == ' ' || (s[i] >= '\t' && s[i] <= '\r') ||
				(s[i] >= '0' && s[i] <= '9')))
			return (0);
		i++;
	}
	return (1);
}

void	addlist(char *s, t_list *l, int i)
{
	int		nbr;
	int		sign;

	while (s[i])
	{
		nbr = 0;
		sign = 1;
		while (s[i] == ' ' || (s[i] >= '\t' && s[i] <= '\r'))
			i++;
		if (s[i] == '+' || s[i] == '-')
		{
			if (s[i] == '-')
				sign = -1;
			i++;
		}
		while (s[i] >= '0' && s[i] <= '9')
		{
			nbr = nbr * 10 + (s[i] - '0');
			i++;
		}
		ft_lstadd_back(&l,  ft_lstnew(nbr * sign));
	}
	if (s[i] != '\0')
		addlist(s, l, i);
}

t_list	*parsing(int argc, char **t)
{
	t_list	*l;
	int		i;

	i = 1;
	l = NULL;
	while (i < argc)
	{
		if (!ft_is_digit(t[i]))
		{
			ft_lstclear(&l);
			return (NULL);
		}
		addlist(t[i], l, 0);
		i++;
	}
	
	return (l);
}

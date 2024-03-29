#include "libft.h"

char	*ft_strjoinca(const char *s1, const char *s2, char c)
{
	char	*new;
	size_t	i;
	size_t	j;

	new = NULL;
	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!new)
		return (0);
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	new[i++] = c;
	while (s2[j] != '\0')
	{
		new[i] = s2[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}

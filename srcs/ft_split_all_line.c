#include "../minish.h"

int skip_quote(int i, char *line)
{
	if (line[i] == '\"')
	{
		i++;
		while (line[i] && line[i] != '\"')
			i++;
		i++;
		return (i);
	}
	if (line[i] == '\'')
	{
		i++;
		while (line[i] && line[i] != '\'')
			i++;
		i++;
		return (i);
	}
	return (0);
}

char **ft_split_all_line(char *line)
{
	char *new_line;
	int i;
	int j;
	int now;

	i = 0;
	j = 0;
	while (line[i])
	{
		//i = (skip_quote(i, line) == 0 ? i : skip_quote(i, line));
		if (line[i] == '\"')
		{
			i++;
			while (line[i] && line[i] != '\"')
				i++;
			i++;
		}
		else if (line[i] == '\'')
		{
			i++;
			while (line[i] && line[i] != '\'')
				i++;
			i++;
		}
		else if (line[i] == '<' && line[i + 1] == '<')
			error("Syntex error '<'"); // только для бонусной части
		else if (line[i] == '>' && line[i + 1] == '>' && line[i + 2] == '>')
			error("Syntex error '>'");
		else if ((line[i] == ';' || line[i] == '|') || ((line[i] == '>' && line[i + 1] != '>') || (line[i] == '<' && line[i + 1] != '<')))
		{
			new_line = (char *)malloc(sizeof(char *) * (ft_strlen(line) + 3));
			j = 0;
			while (j < i)
			{
				new_line[j] = line[j];
				j++;
			}
			new_line[j++] = ' ';
			new_line[j++] = line[i++];
			new_line[j++] = ' ';
			now = j;
			while (line[i])
				new_line[j++] = line[i++];
			new_line[j] = '\0';
			free(line);
			line = ft_strdup(new_line);
			free(new_line);
			i = now;
		}
		else if (line[i] == '>' && line[i + 1] == '>')
		{
			new_line = (char *)malloc(sizeof(char *) * (ft_strlen(line) + 3));
			j = 0;
			while (j < i)
			{
				new_line[j] = line[j];
				j++;
			}
			new_line[j++] = ' ';
			new_line[j++] = line[i++];
			new_line[j++] = line[i++];
			new_line[j++] = ' ';
			now = j;
			while (line[i])
				new_line[j++] = line[i++];
			new_line[j] = '\0';
			free(line);
			line = ft_strdup(new_line);
			free(new_line);
			i = now;
		}
		else
			i++;
	}
	return (ft_split(line, ' '));
}

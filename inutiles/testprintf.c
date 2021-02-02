#include <libc.h>

// void	ft_putchar(char c)
// {
// 	write(1, &c, 1);
// }

/*void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}*/

int	ft_test_printf(char *format, ...)
{
	int i;
	char *str;

	i = 0;
	str = NULL;
	while (format[i])
	{
		ft_putchar(format[i]);
		i++;
	}
	return (0);
}

void	ft_test_arg(char* arg0, ...)
{
	va_list ap;
	int nombre_arg;
	char *arguments;
	int i;

	nombre_arg = 0;
	i = 1;
	arguments = arg0;
	va_start(ap, arg0);
	while (arguments != NULL)
	{
		nombre_arg++;
		arguments = va_arg(ap, char*);
	}
	va_end(ap);
	printf("Il y a %d flags : ", nombre_arg);
	printf("%s", arg0); 
	/* imprime le premier argument car celui lu avec va_arg est le deuxiemme */
	va_start(ap, arg0);
	while (i < nombre_arg)
	{
		if (i == (nombre_arg - 1))
			printf(" et ");
		else 
			printf(", ");
		printf("%s", va_arg(ap, char*));
		i++;
	}
	va_end(ap);
}


int main(void)
{
	ft_test_printf("------c-----\n");
	ft_test_arg("\'-\'", "\'+\'", "\'0\'", "\' \'", "\'#\'", NULL);
	return (0);
}

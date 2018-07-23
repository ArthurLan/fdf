#include "ft_printf.h"

int main()
{
	size_t i;

	i = 0;
	while (i++ < 4096)
		write(1, "20 ", 3);	
	write(1, "\n", 1);	
	i = 0;
	while (i++ < 4096)
		write(1, "20 ", 3);	
	write(1, "\n", 1);	
	i = 0;
	while (i++ < 4096)
		write(1, "20 ", 3);	
	write(1, "\n", 1);	
	return (0);
}

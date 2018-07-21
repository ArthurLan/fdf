#include "ft_printf.h"

int main()
{
	size_t i;

	i = 0;
	while (i++ < 2147483649)
		write(1, "0\n", 4);	
	return (0);
}

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alanter <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/11 21:05:53 by alanter           #+#    #+#              #
#    Updated: 2018/07/19 16:31:22 by alanter          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
INCLUDE = ./includes/
SRCS_DIR = ./srcs/
O_DIR = ./ofiles/
FILES = ft_printf convert flags get_next_line

LIBFT = libft.a
LIBFTI = libft/includes/
LIBFTS = libft/srcs/
LIBFTO = libft/ofiles/
LIBFTF = ft_putchar ft_putstr ft_strlen ft_strcmp \
		 ft_strncmp ft_strdup ft_strcpy ft_strncpy ft_strcat \
		 ft_strncat ft_memalloc ft_memset ft_isdigit ft_isalpha \
		 ft_isalnum ft_isascii ft_isprint ft_toupper ft_tolower \
		 ft_isspace ft_putchar_fd ft_putstr_fd ft_putnbr ft_putnbr_fd \
		 ft_memdel ft_bzero ft_memcpy ft_memmove ft_memccpy ft_memchr \
		 ft_memcmp ft_strchr ft_strrchr ft_strstr ft_atoi ft_strnew \
		 ft_strclr ft_strdel ft_striter ft_striteri ft_strmap ft_strequ \
		 ft_strnequ ft_strsub ft_strjoin ft_strmapi ft_strtrim \
		 ft_strsplit ft_itoa ft_putendl ft_putendl_fd ft_strlcat \
		 ft_strnstr ft_lstnew ft_lstdelone ft_lstdel ft_lstadd \
		 ft_lstiter ft_lstmap ft_islower ft_isupper ft_str_is_lowercase \
		 ft_str_is_uppercase ft_str_is_numeric ft_str_is_alpha \
		 ft_isblank ft_strtrimc ft_strndup ft_strnlen \
		 ft_putnbr_base ft_ulltoa_base ft_lltoa_base ft_ctostr \
		 ft_strjoinfree ft_strupcase ft_putwchar ft_putwstr \
		 ft_charwlen ft_strwlen ft_wtostr ft_ultim_join \
		 ft_cleanfree ft_atoll ft_switchar ft_statjoin ft_wctostr \
		 ft_wordcounter

CFLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

CFILES = $(patsubst %, $(SRCS_DIR)%.c, $(FILES))
OFILES = $(patsubst %, $(O_DIR)%.o, $(FILES))
LIBFTCF = $(patsubst %, $(LIBFTS)%.c, $(LIBFTF))
LIBFTOF = $(patsubst %, $(LIBFTO)%.o, $(LIBFTF))

all : $(NAME)

$(LIBFT): $(LIBFTCF)
	@mkdir -p $(LIBFTO)
	@gcc $(CFLAGS) -c -I$(LIBFTI) $(LIBFTCF)
	@mv *.o $(LIBFTO)
	@ar -rc $(LIBFT) $(LIBFTOF)

$(OFILES): $(CFILES)
	@mkdir -p $(O_DIR)
	gcc $(CFLAGS) -c -I$(INCLUDE) $(CFILES)
	@mv *.o $(O_DIR)

$(NAME): $(LIBFT) $(OFILES)
	@cp ./$(LIBFT) ./$(NAME)
	@ar -rc $(NAME) $(OFILES)
	@ranlib $(NAME)

clean:
	@rm -f $(OFILES)
	@rm -f $(LIBFTOF)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(LIBFT)

re: fclean all

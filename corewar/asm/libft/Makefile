CC 	= 	gcc
CFLAGS 	=	-Wall -Wextra -Werror
SOURCES = ./srcs/libft/ft_abs.c \
		  ./srcs/libft/ft_destroy_2d.c \
		./srcs/libft/ft_atoi.c \
		./srcs/libft/ft_strdel.c \
		./srcs/libft/ft_bzero.c \
		./srcs/libft/ft_replace.c \
		./srcs/libft/ft_get_line.c \
		./srcs/libft/ft_isascii.c \
		./srcs/libft/ft_isdigit.c \
		./srcs/libft/ft_items_in_grid.c \
		./srcs/libft/ft_itoa_base.c \
		./srcs/libft/ft_lstadd.c \
		./srcs/libft/ft_lstnew.c \
		./srcs/libft/ft_max.c \
		./srcs/libft/ft_memalloc.c \
		./srcs/libft/ft_memchr.c \
		./srcs/libft/ft_memcpy.c \
		./srcs/libft/ft_memdel.c \
		./srcs/libft/ft_memmove.c \
		./srcs/libft/ft_memset.c \
		./srcs/libft/ft_min.c \
		./srcs/libft/ft_putchar_fd.c \
		./srcs/libft/ft_putchar.c \
		./srcs/libft/ft_putendl.c \
		./srcs/libft/ft_putstr_fd.c \
		./srcs/libft/ft_putstr.c \
		./srcs/libft/ft_putline.c \
		./srcs/libft/ft_putwchar_fd.c \
		./srcs/libft/ft_putwstr_fd.c \
		./srcs/libft/ft_strcat.c \
		./srcs/libft/ft_strchr.c \
		./srcs/libft/ft_strclen.c \
		./srcs/libft/ft_strcmp.c \
		./srcs/libft/ft_strcpy.c \
		./srcs/libft/ft_strequ.c \
		./srcs/libft/ft_strdefix.c \
		./srcs/libft/ft_strdup.c \
		./srcs/libft/ft_strlen.c \
		./srcs/libft/ft_strncat.c \
		./srcs/libft/ft_strncmp.c \
		./srcs/libft/ft_strncpy.c \
		./srcs/libft/ft_strndup.c \
		./srcs/libft/ft_strnew.c \
		./srcs/libft/ft_strrchr.c \
		./srcs/libft/ft_strsplit.c \
		./srcs/libft/ft_strstr.c \
		./srcs/libft/ft_strsub.c \
		./srcs/libft/ft_strjoin.c \
		./srcs/libft/ft_strtrim.c \
		./srcs/ft_printf/srcs/ft_printf_core.c \
		./srcs/ft_printf/srcs/ft_printf_fd.c \
		./srcs/ft_printf/srcs/ft_printf.c \
		./srcs/ft_printf/srcs/ft_printf_char.c \
		./srcs/ft_printf/srcs/ft_printf_handlings.c \
		./srcs/ft_printf/srcs/ft_printf_noconv.c \
		./srcs/ft_printf/srcs/ft_printf_parser.c \
		./srcs/ft_printf/srcs/ft_printf_signed_decimal.c \
		./srcs/ft_printf/srcs/ft_printf_signedtostr.c \
		./srcs/ft_printf/srcs/ft_printf_string.c \
		./srcs/ft_printf/srcs/ft_printf_unsigned_decimal.c \
		./srcs/ft_printf/srcs/ft_printf_unsigned_hex.c \
		./srcs/ft_printf/srcs/ft_printf_unsigned_octal.c \
		./srcs/ft_printf/srcs/ft_printf_unsignedtostr_base.c \
		./srcs/ft_printf/srcs/ft_printf_utils.c \
		./srcs/ft_printf/srcs/ft_printf_wchar.c \
		./srcs/ft_printf/srcs/ft_printf_wstring.c

INCLUDES =	./includes/libft.h \
		./includes/ft_printf_handler.h \
		./includes/ft_printf_internal.h

OBJECTS  = 	$(notdir $(SOURCES:.c=.o))
NAME     = 	libft.a

vpath %.c ./srcs/libft ./srcs/ft_printf/

all: $(NAME)
	@echo > /dev/null

$(NAME): $(OBJECTS)
	@ printf "\33[2K"
	@ printf "Creating library => "
	@ if ar rc $(NAME) $(OBJECTS) ; \
		then printf "✅\n"; \
		else printf "❌\n"; fi
	@ ranlib $(NAME)
	@ echo "Finished"

%.o: %.c $(INCLUDES)
	@ printf "\33[2K"
	@ printf "Compiling: $< ..."
	@ $(CC) -o $@ -c $(CFLAGS) $< $(addprefix -I ,$(sort $(dir $(INCLUDES))))
	@ printf "\r"

clean:
	@ echo "Deleting object files"
	@ rm -f $(OBJECTS)

fclean: clean
	@ echo "Deleting $(NAME)"
	@ rm -f $(NAME)

re: fclean all


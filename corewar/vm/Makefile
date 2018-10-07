# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akhanye <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/30 10:25:20 by akhanye           #+#    #+#              #
#    Updated: 2017/10/23 09:53:57 by akhanye          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	corewar

SRC_FLDR	=	src/
SRC_INSTR	=	src/instructions/

SRC			=	main.c							\
				$(SRC_FLDR)ft_getoptions.c		\
				$(SRC_FLDR)get_fd.c				\
				$(SRC_FLDR)champs.c				\
				$(SRC_FLDR)arena.c				\
				$(SRC_FLDR)cycles.c				\
				$(SRC_FLDR)values.c				\
				$(SRC_FLDR)decode.c				\
				$(SRC_FLDR)debug.c				\
				$(SRC_FLDR)access_mem.c		    \
				$(SRC_FLDR)trace.c              \
				$(SRC_FLDR)wait.c               \
				$(SRC_FLDR)correct_size.c       \
				$(SRC_FLDR)remove.c				\
				$(SRC_FLDR)add_champ.c			\
				$(SRC_INSTR)ft_live.c			\
				$(SRC_INSTR)ft_and.c			\
				$(SRC_INSTR)ft_sti.c			\
				$(SRC_INSTR)ft_ld.c				\
				$(SRC_INSTR)ft_st.c				\
				$(SRC_INSTR)ft_add.c			\
				$(SRC_INSTR)ft_sub.c			\
				$(SRC_INSTR)ft_or.c				\
				$(SRC_INSTR)ft_xor.c			\
				$(SRC_INSTR)ft_zjmp.c			\
				$(SRC_INSTR)ft_ldi.c			\
				$(SRC_INSTR)ft_fork.c			\
				$(SRC_INSTR)ft_lld.c			\
				$(SRC_INSTR)ft_lldi.c			\
				$(SRC_INSTR)ft_lfork.c			\
				$(SRC_INSTR)ft_aff.c


FLAGS		=  -Wall -Wextra -Werror -g

TERMCAP     =   -ltermcap

LIBRARY 	=	-L libft -lft

all: $(NAME)

$(NAME):
	make -C libft/ fclean && make -C libft/
	clang $(SRC) $(FLAGS) $(LIBRARY) $(TERMCAP) -o $(NAME)

clean:
	make -C libft/ clean

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: 	fclean all

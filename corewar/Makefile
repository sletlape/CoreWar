NAME 	=	corewar
ASMPATH = 	./asm/
VMPATH  =	./vm/

all: $(NAME)

$(NAME):
	make -C $(ASMPATH)
	make -C $(VMPATH)
	echo "\033[32;1m$(ASMPATH) and $(VMPATH) created successfully!\033[0m"

clean:
	make -C $(ASMPATH) clean
	make -C $(VMPATH) clean

fclean:
	make -C $(ASMPATH) fclean
	make -C $(VMPATH) fclean
	echo "\033[31;1m$(ASMPATH) and $(VMPATH) removed!\033[0m"
re:
	make -C $(ASMPATH) re
	make -C $(VMPATH) re

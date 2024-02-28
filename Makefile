NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

GARBAGE = *.o */*.o *.gch */*.gch *.out */*.out

SRCS = ft_printf.c \

OBJS = $(SRCS:.c=.o)

.c.o:
	@cc -c $(SRCS) -I ./

all: $(OBJS)
	@cd ./libft && \
	make clean bonus && \
	cp libft.a ../$(NAME) && \
	rm libft.a && \
	cd ../
	@ar rcs $(NAME) $(OBJS)
	@make clean
	@ranlib $(NAME)

debug: FLAGS += -g
debug:
	@cc $(FLAGS) -L. -lftprintf && ./a.out

clean: $(OBJS)
	@rm -rf $(OBJS) $(GARBAGE)

fclean: clean
	@rm -rf $(NAME) */*.a

re: fclean
	@make all

.PHONY: all clean fclean re
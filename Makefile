NAME = libftprintf.a

SRCS = libftprintf.c \

OBJS = $(SRCS:.c=.o)

.c.o:
	@cc -c $(SRCS) -I ./ */*

all: $(NAME)
	@cd ./libft && make && cp libft.a ../
	@cd ../ && mv libft.a libftprintf.a
	@ar rcs $(NAME) $(OBJS)

clean: $(OBJS)
	@rm -rf $(OBJS)

fclean:
	@rm -rf *.o $(NAME)

re: clean fclean all

.PHONY: all clean fclean re
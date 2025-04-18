
NAME_SERVER = server
NAME_CLIENT = client

CC     = cc
CFLAGS = -Iinc -Wall -Wextra -Werror

INC = -Iinc -Ilib/ft_printf/inc

FT_PRINTF_LIB = lib/ft_printf/ft_printf.a

SRCS = src/server.c src/client.c src/utils.c

OBJS = $(SRCS:src/%.c=obj/%.o)

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): obj/server.o obj/utils.o $(FT_PRINTF_LIB)
	$(CC) $(CFLAGS) -o $(NAME_SERVER) obj/server.o obj/utils.o $(FT_PRINTF_LIB)

$(NAME_CLIENT): obj/client.o obj/utils.o $(FT_PRINTF_LIB)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) obj/client.o obj/utils.o $(FT_PRINTF_LIB)

obj/%.o: src/%.c inc/minitalk.h
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(FT_PRINTF_LIB):
	$(MAKE) -C lib/ft_printf

clean:
	@rm -rf obj
	$(MAKE) -C lib/ft_printf clean

fclean: clean
	@rm -f $(NAME_SERVER) $(NAME_CLIENT)
	$(MAKE) -C lib/ft_printf fclean

re: fclean all

.PHONY: all clean fclean re

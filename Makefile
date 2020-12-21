# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fbes <fbes@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2020/12/21 17:22:55 by fbes          #+#    #+#                  #
#    Updated: 2020/12/21 18:27:19 by fbes          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME =		beepboopbeep.a

SRCS =		*.c

CFLAGS =	-Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS)

clean:


fclean: clean
	rm -f $(NAME)

re: fclean all

test: fclean $(NAME)
	./$(NAME)

.PHONY: all clean fclean re

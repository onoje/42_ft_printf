NAME 			= libftprintf.a

AR 				= ar rcs

CC 				= cc

RM 				= rm -f

CFLAGS 			= -Wall -Werror -Wextra

SRCS 			= ft_printf.c \
					ft_printf_extra_functions.c

OBJECTS 		= $(SRCS:.c=.o)

all: 			$(NAME)

$(NAME):		$(OBJECTS)
					$(AR) $(NAME) $(OBJECTS)

clean:
				$(RM) $(OBJECTS)

fclean:			clean
					$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re 

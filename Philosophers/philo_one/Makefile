NAME			= philo_one

# FLAGS
CC				= clang
C_FLAGS			= -Wall -Wextra -Werror -o1 -pthread

# DIRECTORIES
SRCS_DIR		= ./
BUILDING_DIR	= ./building_dir/
INCLUDES_DIR	= ./


# FILES
SRCS			= 	main \
					utils \
					parse_init \
					events

FILES			= $(addsuffix .c, $(SRCS))
OBJECTS			= $(addprefix $(BUILDING_DIR),$(FILES:.c=.o))

# BUILDING RULES
all:			$(NAME)

$(BUILDING_DIR)%.o:$(SRCS_DIR)%.c
				mkdir -p building_dir
				$(CC) $(C_FLAGS) -I ${INCLUDES_DIR} -c $< -o $@

${NAME}:		${OBJECTS}
				$(CC) $(C_FLAGS) ${OBJECTS} -o ${NAME}

# CLEANING RULES
clean:
				rm -f $(OBJECTS)
				rm -Rf building_dir

fclean:			clean
				rm -f $(NAME)

re:				fclean all

# TESTING RULES
test:			all
				./${NAME} 200 200 200 200 200;

.PHONY:			all clean fclean re


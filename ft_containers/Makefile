###############################################################################
##								MAKEFILE									 ##
###############################################################################

NAME			=	ft_containers
STL_NAME		=	std_containers

OUTPUTS 		=	ft.out \
					std.out \
					diff.out

# FLAGS
CC			= clang++
FLAGS 		= -Wall -Wextra -Werror -std=c++98

# DIRECTORIES
SRCS_DIR		= ./
BUILDING_DIR	= ./building_dir/
INCLUDES_DIR	= ./


# FILES
SRCS			= 	main

FILES			= $(addsuffix .cpp, $(SRCS))
OBJECTS			= $(FILES:.cpp=.o)

# BUILDING RULES
all:			$(NAME)

$(BUILDING_DIR)%.o:$(SRCS_DIR)%.cpp
				mkdir -p building_dir
				$(CC)  $(FLAGS) -I ${INCLUDES_DIR} -c $< -o $@

${NAME}:		${OBJECTS}
				$(CC) $(FLAGS) -DNM=ft 	${FILES} -o ${NAME}
				$(CC) $(FLAGS) -DNM=std	${FILES} -o ${STL_NAME}

compare :
	./compare.sh

# CLEANING RULES
clean:
				rm -f $(OBJECTS)
				rm -Rf building_dir

fclean:			clean
				rm -f $(NAME) $(STL_NAME) $(OUTPUTS)

re:				fclean all

.PHONY:			all clean fclean re

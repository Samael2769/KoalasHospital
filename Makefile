############################DIRECTORY:#####################
INC_DIR 	= ./includes/

SRC_DIR 	= ./sources/

############################FILES:#########################

SRC_FILES 	= \

SRC_FMAIN	= main.cpp	\

SRC			= $(addprefix $(SRC_DIR), $(SRC_FILES))

SRC_MAIN 	= $(addprefix $(SRC_DIR), $(SRC_FMAIN))

############################OBJ:###########################

OBJ			= $(SRC:.cpp=.o)

OBJ_MAIN 	= $(SRC_MAIN:.cpp=.o)

############################USEFULL:#######################

GXX			= g++

CP			= cp

RM			= rm -rf

CHMOD		= chmod

ECHO		= echo

###########################################################

CXXFLAGS 	= -Wall

LDFLAGS		= -Iincludes

NAME		= KoalaHospital

###########################################################

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_MAIN)
	@$(ECHO) "\e[31;1mMaking $(NAME)\e[0m"
	$(CXX) -o $(NAME) $(OBJ) $(OBJ_MAIN) $(LDFLAGS)
	@$(ECHO) "\e[92;1mCompleted\e[0m"


clean:
	$(RM) $(OBJ) $(OBJ_MAIN)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
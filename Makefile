############################DIRECTORY:#####################
INC_DIR 	= ./includes/

SRC_DIR 	= ./sources/

ENC_DIR		= Encapsulated/

CLASS_DIR	= Classes/

############################FILES:#########################


SRC_ENC		= Fork.cpp		\
			  Mutex.cpp 	\
			  ThreadPool.cpp\
			  MsgQueue.cpp	\

SRC_CLASS	= Doctor.cpp	\
			  Hospital.cpp	\
			  Nurse.cpp		\
			  Patient.cpp	\
			  Rooms.cpp		\
			  Deases.cpp	\



SRC_FILES 	= $(addprefix $(ENC_DIR), $(SRC_ENC)) 		\
		      $(addprefix $(CLASS_DIR), $(SRC_CLASS)) 	\

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

CXXFLAGS 	= -Wall -Iincludes -g3

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
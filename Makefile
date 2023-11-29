# This is a minimal set of ANSI/VT100 color codes
END			=	\e[0m
BOLD		=	\e[1m
UNDER		=	\e[4m
REV			=	\e[7m

# Colors

DEF_COLOR 	= 	\033[0;39m
GRAY 		= 	\033[0;90m
GREY_01		=	\033[30m
RED 		= 	\033[0;91m
RED_01		=	\033[31m
GREEN 		= 	\033[0;92m
GREEN_01	=	\033[32m
YELLOW 		= 	\033[0;93m
YELLOW_01	=	\033[33m
BLUE 		= 	\033[0;94m
BLUE_01		=	\033[34m
PURPLE		=	\033[35m
MAGENTA 	= 	\033[0;95m
CYAN 		= 	\033[0;96m
CYAN_01		=	\033[36m
WHITE 		= 	\033[0;97m
WHITE_01	=	\033[37m

# Inverted, i.e. colored backgrounds
IGREY		=	\e[40m
IRED		=	\e[41m
IGREEN		=	\e[42m
IYELLOW		=	\e[43m
IBLUE		=	\e[44m
IPURPLE		=	\e[45m
ICYAN		=	\e[46m
IWHITE		=	\e[47m

# **************************************************************************** #

#Variables‹

NAME			= pipex
INCLUDE			= include/
LIBFT			= libft
SRC_DIR			= src/
OBJ_DIR			= obj/
CC				= gcc
CFLAGS			= -Wall -Werror -Wextra -g3 -I
RM				= rm -f
AR				= ar rcs

# =========================================================================== #


#Sources

SRC_FILES	=	main mem error free_mem ft_strjoin_pipex pipe_exec
# Files 

SRCS 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

###

OBJF		=	.cache_exists

all:		$(NAME)

$(NAME):	$(OBJS)
			@make -C $(LIBFT)
			@cp libft/libft.a .
			@mv libft.a $(NAME)
			@$(CC) $(OBJS) -o $(NAME) $(LIBFT)/libft.a
			@echo "$(GREEN)pipex compiled!$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
			@echo "$(MAGENTA)Compiling: $< $(DEF_COLOR)"
			@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)

# Rules

clean:
			@$(RM) -rf $(OBJ_DIR)
			@$(RM) -rf utils/
			@make clean -C $(LIBFT)
			@echo "$(BLUE)pipex object files cleaned!$(DEF_COLOR)"

fclean:		clean
			@$(RM) -f $(NAME)
			@$(RM) -f $(NAME2)
			@$(RM) -f $(NAME_TEST)
			@$(RM) -f $(NAME_DEBUG)
			@$(RM) -f $(LIBFT)/libft.a
			@$(RM) -f $(TEST_DIR)/libft.a
			@$(RM) -f libft.a
			@echo "$(CYAN)pipex executable files cleaned!$(DEF_COLOR)"
			@echo "$(CYAN)libft executable files cleaned!$(DEF_COLOR)"

re:			fclean all
			@echo "$(MAGENTA)Cleaned and rebuilt everything for pipex!$(DEF_COLOR)"
			@echo "$(GREY)                                     ..                                      "
			@echo "$(GREEN)                           .:---===++++*++==-:.                              "
			@echo "$(YELLOW)                      .:-=++==--------++***#*+++=-.                          "
			@echo "$(BLUE)                  .-=++=--------------------=+****++=:.                      "
			@echo "$(MAGENTA)               .-+*=-----------------------------+*+=++=-                    "
			@echo "$(CYAN)             .=*#*+---------------------------------=*#*++=.                 "
			@echo "$(RED_01)           :=*#*=------------::::::::::::--------------=##=+=.               "
			@echo "$(GRAY)         .++#*=--------------::::::::::::----------------+%==+-              "
			@echo "$(GREEN)        .**#=---------------------------------------------=#*=++.            "
			@echo "$(RED)       :*+%=-----------------------------------------------=====*.           "
			@echo "$(YELLOW)      :*=%=-----------------------------------------------======+=           "
			@echo "$(MAGENTA)     .*==+---------------=--------------------------------=======#.          "
			@echo "$(CYAN)    .*=======-------=--==--------------------------------========*+          "
			@echo "$(WHITE)    +===============---===-----------------------------===========#.         "
			@echo "$(GREEN_01)    *==============----=--==------------------------==============+=         "
			@echo "$(RED)   :*=================-==-====-------===---------==================*.        "
			@echo "$(GREEN)   =+==================================----========================*:        "
			@echo "$(MAGENTA)   +=================================================================        "
			@echo "$(YELLOW)   +================================================================*        "
			@echo "$(BLUE)   =+===============================================================*        "
			@echo "$(MAGENTA)   :*===============================================================*        "
			@echo "$(CYAN)   .*===============================================================*-*+     "
			@echo "$(PURPLE)    ++==============================================================%%=%.    "
			@echo "$(WHITE) :=--*==========+=+++++++++**++===========+***######**#*****+=====*%%==#     "
			@echo "$(GRAY) +=+%%*===*#***%+++====+++++++%@+========%+-=*:..:::-------=##==*%%%++%-     "
			@echo "$(RED_01) ++=*%%%*=%%:-#+:.::::::::::---*@========%=+#+.....:::::::::-%+%%%@*##%      "
			@echo "$(BLUE) :**++%%%%%%:*+#....:::::::::::-#*+**##*+%=+#=.  ....::::::::%%#%#+##+#      "
			@echo "$(BLUE_01)  -***+#@%%%::#-.....::::::::::-=@%%%%%%@@==-:.......:::::::-#@%++##=#=      "
			@echo "$(GREEN)   -**+=+#@%-:::....::::::::::---%@*+++*#@=-:::......::::::--##==#*=#-       "
			@echo "$(GREEN_01)    -*#+=++%:::::::::::::::::----%+======*#-:::::::::::::::--%+====%-        "
			@echo "$(MAGENTA)     #*#=++@-:::::::::::::-----=##========##+=--:::::::---=+%#++==+#         "
			@echo "$(PURPLE)     ++=##=*#+=======++*****###**+=========++*********#####*+=+%+#+*         "
			@echo "$(CYAN)   .:*++@*===+****++++=============++++=======================+%%%%#:        "
			@echo "$(RED)   :*#%%%*=====================+=======+==+===================+%##%#:        "
			@echo "$(WHITE)   =*#%%%+====================+*===========#==================#%#%%-         "
			@echo "$(BLUE)   ..-*%%#%===================+*+======+*=+*=================#%###%.         "
			@echo "$(WHITE_01)      :%%#%#+===================**#%###%#*=================+%%#####:         "
			@echo "$(MAGENTA)      +%###%%#================*#%%%%%%%%%%%%#+===========+*%######%+         "
			@echo "$(BLUE_01)      :%#####%%+============#%####%%##%%#####%##+=======*%%#######%-         "
			@echo "$(GREEN)      -%%######%%+========%%#####%%%#%%%%%%#####%*====*%%#########%:         "
			@echo "$(PURPLE)       :%########%#=+==+#%###%%%%##%%#%####%%%%##%*+##%###########%-         "
			@echo "$(RED)        *%%########%%#%%###%%#######%%%########%###%##############%=         "
			@echo "$(CYAN)        #%#############%%%*+###################*#%%%#############%%+.        "
			@echo "$(BLUE)        .%%##############%*+==+*###########%#*==+#%#################%.       "
			@echo "$(MAGENTA)        .%################%*+++===*%%%%%%%@+=++++#%#################%.       "
			@echo "$(GREEN_01)        =%#################%%++++++%######%++++++%#################%=        "
			@echo "$(PURPLE)        .%###################%%#*+++%####%**+++*%%################%=         "
			@echo "$(RED_01)         -%#####################%%%#%%%%@%%%%%%###################%-         "
			@echo "$(PURPLE)         =#%####################################################%%=          "
			@echo "$(GREEN)          .%%###################################################%=           "
			@echo "$(GRAY)           :=%#%##############################################%#%-           "
			@echo "$(BLUE)             ==+#%##%%#####################################%#%+-.            "
			@echo "$(WHITE)                 .==-#%##%#################################%#+               "
			@echo "$(CYAN)                        .+%#%@#######################%#%@%%+                 "
			@echo "$(RED)                          :---*#%%%##%######%##%%%#%#=+=.:.                  "
			@echo "$(GREEN_01)                                  =*#@%%%%#%%%%#.:-:                         "
			@echo "$(RED_01)                                     .:==:-:...                              "

.PHONY:		all clean fclean re

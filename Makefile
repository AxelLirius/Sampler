# COLORS #
_RED        =    \e[31m
_GREEN        =    \e[32m
_YELLOW        =    \e[33m
_BLUE        =    \e[34m
_END        =    \e[0m

# COMPILATION #
CC_FLAGS    =   -Werror -D__LINUX_ALSA__ -lasound -lpthread -lsfml-audio

# DIRECTORIES #
DIR_HEADERS        =    ./includes/
DIR_SRCS        =    ./srcs/
DIR_OBJS        =    ./compiled_srcs/

# FILES #
SRCS            =  ./srcs/main.cpp \
		./srcs/sound.cpp \
		./srcs/pad.cpp \
		./srcs/Bank.cpp \
		./srcs/program.cpp \
		./srcs/mididevice.cpp \
		./rtmidi/RtMidi.cpp

# COMPILED_SOURCES #
OBJS         =    $(SRCS:%.c=$(DIR_OBJS)%.o)
NAME         =    Sampler

## RULES ##
all debug:        $(NAME)

# VARIABLES RULES #

$(NAME):        $(OBJS)
		@printf "\033[2K\r$(_BLUE) All files compiled into '$(DIR_OBJS)'. $(_END)\n"
		@g++ $(CC_FLAGS) -I $(DIR_HEADERS) $(OBJS) -o $(NAME)
		@printf "\033[2K\r$(_GREEN) Executable '$(NAME)' created. $(_END)\n"

# COMPILED_SOURCES RULES #
$(OBJS):        | $(DIR_OBJS)


$(DIR_OBJS)%.o: $(DIR_SRCS)%.c
		@printf "\033[2K\r $(_YELLOW)Compiling $< $(_END) "
		@g++ $(CC_FLAGS) -I $(DIR_HEADERS) -c $< -o $@

$(DIR_OBJS):
		@mkdir -p $(DIR_OBJS)

# MANDATORY PART #
clean:
		@rm -rf $(DIR_OBJS)
		@printf "\033[2K\r$(_RED) '"$(DIR_OBJS)"' has been deleted. $(_END)\n"

fclean:            clean
		@rm -rf $(NAME)
		@printf "\033[2K\r$(_RED) '"$(NAME)"' has been deleted. $(_END)\n"

lancement:
		@printf "\033[2K\r$(_END)Lancement du programe $(_END)\n"
		@./$(NAME)

sampler:                fclean all lancement

# PHONY #

.PHONY:            all debug clean fclean re


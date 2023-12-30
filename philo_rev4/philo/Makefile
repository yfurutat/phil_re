NAME			:=	philo

MAIN_FILE		:=	main.c \
					destroy.c \
					init.c \
					observe_party.c \
					parse_args.c \
					philo_act.c \
					prep_party.c \
					start_party.c 

UTIL_FILES		:=	ft_atoll.c \
					ft_isdigit.c \
					print_error.c \
					print_str.c \
					time_wait_sleep.c

SRC_PATH		:=	./srcs/
OBJ_PATH		:=	./objs/
INC_PATH		:=	./includes/
UTILS_PATH		:=	./utils/

SRC				=	$(addprefix $(SRC_PATH), $(MAIN_FILE))
OBJ				=	$(addprefix $(OBJ_PATH), $(MAIN_FILE:.c=.o))
UTILS			=	$(addprefix $(UTILS_PATH), $(UTIL_FILES))
UTILS_OBJ		=	$(addprefix $(OBJ_PATH), $(UTIL_FILES:.c=.o))

CC				:=	cc
# CFLAGS			:=	-Wall -Wextra -Werror -MMD -g -pthread -fsanitize=thread -Iincludes 
# CFLAGS			:=	-Wall -Wextra -Werror -MMD -g -pthread -fsanitize=address -Iincludes 
CFLAGS			:=	-Wall -Wextra -Werror -MMD -g -pthread -Iincludes 
RM				:=	rm -fr

all				:	$(NAME)

$(NAME)			:	$(OBJ_PATH) $(OBJ) $(UTILS_OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(UTILS_OBJ) -o $@

$(SRC_PATH)		:
	@mkdir -p $@

$(OBJ_PATH)		:
	@mkdir -p $@

$(INC_PATH)		:
	@mkdir -p $@

$(UTILS_PATH)	:
	@mkdir -p $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_PATH)%.o: $(UTILS_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@

-include $(OBJS:%.o=%.d) $(UTILS_OBJ:%.o=%.d)

clean			:
	$(RM) $(OBJ_PATH)

fclean			:	clean
	$(RM) $(NAME)

re				:	fclean all

sall			:
	@$(MAKE) -s all

sclean			:
	@$(MAKE) -s fclean

sre				:	sclean sall
	@echo "\nSILENT MAKE SUCCESSFULLY DONE\n"

files			:	$(SRC_PATH) $(INC_PATH) $(UTILS_PATH)
	@touch $(INC_PATH)philo.h $(SRC) $(UTILS)

norm	:
	@norminette $(INC_PATH)*.h $(SRC) $(UTILS)
normd	:
	@norminette -R CheckDefine $(INC_PATH)*.h $(SRC) $(UTILS)
normf	:
	@norminette -R CheckForbiddenSourceHeader $(INC_PATH)*.h $(SRC) $(UTILS)
norma	:	norm normd normf

commit			:
	@$(MAKE) fclean
	git add $(INC_PATH)*.h $(SRC) $(UTILS) Makefile
	git commit -m "commit through makefile"
	git status

.PHONY			:	all clean fclean re \
					sall sclean sre files commit \
					norm normd normf norma
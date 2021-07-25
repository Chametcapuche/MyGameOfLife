CC_CPP				=	g++

CFLAGS				:=	-Wall -Wextra -std=c++17	\
						-I./include -lsfml-graphics	\
						-lsfml-window -lsfml-system

RM					=	rm -rf

SRC_MAIN			:=	src/main.cpp

SRC					:=	src/Args.cpp					\
						src/GameOfLife.cpp				\
						src/Graphics.cpp				\
						src/CoreLogic.cpp

SRC_TEST			:=	src_unit_test/unit_tests.cpp

OBJ_MAIN			=	$(SRC_MAIN:.cpp=.o)

OBJ					=	$(SRC:.cpp=.o)

OBJ_TEST			=	$(SRC_TEST:.cpp=.o)

%.o: %.cpp
	@$(CC_CPP) $(CPPFLAGS) $(CFLAGS) -o $@ -c $< $(LDFLAGS) &&	\
    echo -e "\033[92m[OK]\033[0m" $< || echo -e "\033[91m[KO]\033[0m" $<

EXEC_NAME			=	myGOL

EXEC_NAME_TEST		=	unit_tests

all:	vm

vm:	$(OBJ_MAIN) $(OBJ)
	@$(CC_CPP) $(CFLAGS) -o $(EXEC_NAME) $(OBJ_MAIN) $(OBJ) && 	\
	(echo -e "\033[92m[MYGOL OK]\033[0m" $<) || \
	(echo -e "\033[91m[MYGOL NO COMPIL]\033[0m" $<; false)

test_run:
	@$(CC_CPP) $(CFLAGS) -o unit_tests $(SRC_TEST) $(SRC) --coverage -lcriterion && \
	(echo -e "\033[1;35m************************\033[0m" $<) && \
	(echo -e "\033[1;35m*      UNIT TESTS      *\033[1;35m" $<) && \
	(echo -e "\033[1;35m************************\033[0m" $<)
	-./unit_tests
	-gcovr

clean:
	@$(RM) $(OBJ_MAIN) $(OBJ) $(OBJ_TEST) *.o *.gcda *.gcno
	@echo -e "\033[91m[RM]\033[0m *.o *# *~"
	@echo -e "\033[91m[RM]\033[0m *.gcno *.gcda"

fclean:	clean
	@$(RM) $(EXEC_NAME) $(EXEC_NAME_TEST)
	@echo -e "\033[91m[RM]\033[0m Binary"

re: fclean all

.PHONY = all re clean fclean $(EXEC_NAME) $(EXEC_NAME_TEST)
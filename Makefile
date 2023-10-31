NAME	:= get_next_line
CFLAGS	:= -Wall -Wextra
# CFLAGS	+= -Werror
CFLAGS	:= -Ofast

HEADERS	:= -I ./include
SRC_DIR	:= ./src
OBJ_DIR	:= ./obj
SRCS	:= $(shell find $(SRC_DIR) -type f -name "*.c")
OBJS	:= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && echo "Compiled: $(notdir $@)"

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(HEADERS) -o $(NAME) && echo "Linked: $(NAME)"

clean:
	rm -rf $(OBJ_DIR) && echo "Removed: $(OBJ_DIR)"

fclean: clean
	rm -f $(NAME) && echo "Removed: $(NAME)"

re: clean all

.PHONY: all, clean, fclean, re
.SILENT:
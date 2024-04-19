NAME	:= libgnl.a
CFLAGS	:= -Wall -Wextra -Wunreachable-code -Ofast

HEADERS	:= -I./include
SRCS	:= $(shell find src -type f -name "*.c")
OBJS	:= $(SRCS:src/%.c=obj/%.o)

all: $(NAME)

obj/%.o: src/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && echo "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	$(AR) rcs $(NAME) $(OBJS) && echo "Linked: $(NAME)"

clean:
	rm -f $(OBJS) && echo "Removed: $(OBJS)"

fclean: clean
	rm -f $(NAME) && echo "Removed: $(NAME)"

re: clean all

.PHONY: all clean fclean re
.SILENT:

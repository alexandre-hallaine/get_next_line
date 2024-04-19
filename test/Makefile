NAME	:= test
CFLAGS	:= -Wall -Wextra -Wunreachable-code -Ofast
LIBGNL	:= ..

HEADERS	:= -I ./include -I $(LIBGNL)/include
LIBS	:= $(LIBGNL)/libgnl.a
SRCS	:= $(shell find src -type f -name "*.c")
OBJS	:= $(SRCS:src/%.c=obj/%.o)

all: libgnl $(NAME)

libgnl:
	make -C $(LIBGNL)

obj/%.o: src/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && echo "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME) && echo "Linked: $(NAME)"

clean:
	rm -f $(OBJS) && echo "Removed: $(OBJS)"
	make -C $(LIBGNL) clean

fclean: clean
	rm -f $(NAME) && echo "Removed: $(NAME)"

re: clean all

.PHONY: all clean fclean re libgnl
.SILENT:

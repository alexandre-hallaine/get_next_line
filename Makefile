NAME	:= get_next_line
CFLAGS	:= -Wall -Wextra -Werror -Wunreachable-code -Ofast

HEADERS	:= -I ./include
SRCDIR	:= ./src
OBJDIR	:= ./obj
SRCS	:= $(shell cd $(SRCDIR) && find . -name "*.c")
OBJS	:= $(SRCS:%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && echo "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(HEADERS) -o $(NAME)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: clean all

.PHONY: all, clean, fclean, re
.SILENT:
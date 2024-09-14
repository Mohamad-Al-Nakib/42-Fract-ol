# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Ofast -march=native -flto -funroll-loops -ffast-math -I./include -I./lib/minilibx -I./lib/ft_printf
#CFLAGS = -Wall -Wextra -Werror -O2 -march=native -flto -I./include -I./lib/minilibx -I./lib/ft_printf


# Directories
SRCDIR = ./src
LIBDIR = ./lib
MLXDIR = $(LIBDIR)/minilibx
PRINTF_DIR = $(LIBDIR)/ft_printf
OBJDIR = ./obj

# Source files
SRCS = $(SRCDIR)/main.c \
       $(SRCDIR)/ft_render.c \
       $(SRCDIR)/julia.c \
       $(SRCDIR)/burning_ship.c \
       $(SRCDIR)/mandelbrot.c \
       $(LIBDIR)/ft_atod.c \
       $(LIBDIR)/ft_exit.c \
       $(LIBDIR)/ft_get_color.c \
       $(LIBDIR)/ft_get_type.c \
       $(LIBDIR)/ft_key_pressed.c \
       $(LIBDIR)/ft_mouse_zoom.c \
       $(LIBDIR)/ft_strcmp.c \
       $(PRINTF_DIR)/ft_format.c \
       $(PRINTF_DIR)/ft_printf.c \
       $(PRINTF_DIR)/ft_putchar.c \
       $(PRINTF_DIR)/ft_puthex.c \
       $(PRINTF_DIR)/ft_putnbr.c \
       $(PRINTF_DIR)/ft_putptr.c \
       $(PRINTF_DIR)/ft_putstr.c \
       $(PRINTF_DIR)/ft_putunbr.c

# Object files
OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)

# Libraries
LIBS = -L$(MLXDIR) -lmlx -L$(PRINTF_DIR) -lftprintf -lX11 -lXext -lm

# Target executable
NAME = fractol

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C $(MLXDIR)
	@$(MAKE) -C $(PRINTF_DIR)
	$(CC) -g $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)/$(SRCDIR) $(OBJDIR)/$(LIBDIR) $(OBJDIR)/$(PRINTF_DIR)

clean:
	@$(MAKE) clean -C $(MLXDIR)
	@$(MAKE) clean -C $(PRINTF_DIR)
	rm -rf $(OBJDIR)

fclean: clean
	@$(MAKE) clean -C $(MLXDIR)
	@$(MAKE) fclean -C $(PRINTF_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

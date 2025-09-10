# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgil-fer <bgil-fer@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/04 12:18:29 by bgil-fer          #+#    #+#              #
#    Updated: 2025/09/10 12:15:38 by bgil-fer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nombre del ejecutable
NAME		=	philo

# Compilador y flags
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -Iinclude #-g3 #-fsanitize=address
#-g3 -fsanitize=address

# Directorios
SRCDIR		=	src
OBJDIR		=	obj

# Archivos fuente y objetos
# $(shell find $(SRCDIR) -name "*.c")
SRCS 		= 	src/main.c src/utils.c src/ft_atoi.c#Aquí tengo que poner el nombre de toddos los archivos que vaya a usar!!!

OBJS		=	$(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

# Regla principal
all: $(NAME)

# Crear el directorio de objetos si no existe
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Compilar los archivos fuente en objetos
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Enlazar con las librerías
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Limpiar archivos intermedios
clean:
	rm -rf $(OBJDIR)

# Eliminar el ejecutable y objetos
fclean: clean
	rm -f $(NAME)

# Recompilar desde cero
re: fclean all

.PHONY: all clean fclean re
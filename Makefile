# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rde-oliv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/31 21:55:18 by rde-oliv          #+#    #+#              #
#    Updated: 2020/07/18 21:19:53 by rde-oliv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ngn.a
CC   = clang
SRC  = ngn_init.c ngn_camera.c ngn_mini_map.c ngn_get_window_size.c \
	  ngn_int_circle.c ngn_set_movement.c ngn_int_getline.c \
	  ngn_int_config_header.c ngn_int_splittedline.c ngn_strerror.c \
	  ngn_int_resize.c ngn_set_window_size.c \
	  ngn_int_matrix.c ngn_int_mx_validn.c ngn_destroy.c
OBJS     := $(SRC:.c=.o)
CFLAGS    = -Werror -Wextra -Wall -g
SUBMOD    = libft lbmp
SUBMK    := $(addsuffix /Makefile,$(SUBMOD))
SUBLIB   := $(foreach D,$(SUBMOD),$D/$D.a)
CMOD     := $(patsubst %,-I %,$(SUBMOD))
CMODBACK := $(patsubst %,-I ../%,$(SUBMOD))
ARSCRIPT  = build_merge.ar

all: $(NAME)

$(NAME): $(OBJS) ngn_int.h
	ar rcs $(NAME) $(OBJS)

_$(NAME): $(SUBLIB) $(NAME) $(ARSCRIPT)
	ar -M < $(ARSCRIPT)

%.o: %.c ngn_int.h
	$(CC) $(CFLAGS) -c $< -o $@ $(CMOD) $(CMODBACK)

.FORCE:
$(SUBLIB): .FORCE $(SUBMK)
	make -C $(@D)

$(SUBMK):
	git submodule update --init

$(ARSCRIPT):
	@echo "CREATE _$(NAME)" > $(ARSCRIPT)
	@echo "ADDLIB $(NAME)" >> $(ARSCRIPT)
	@for lib in $(SUBLIB); do \
		echo "ADDLIB $$lib" >> $(ARSCRIPT); \
	done
	@echo "SAVE\nEND" >> $(ARSCRIPT)

clean:
	rm -f $(OBJS)
	rm -f $(ARSCRIPT)
	@for module in $(SUBMOD); do \
		if [ -f $$module/Makefile ]; then make clean -C $$module; fi; \
	done

fclean: clean
	rm -f $(NAME)
	rm -f _$(NAME)
	@for module in $(SUBMOD); do \
		if [ -f $$module/Makefile ]; then make fclean -C $$module; fi; \
	done

re: fclean $(NAME)

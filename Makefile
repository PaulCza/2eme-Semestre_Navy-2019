##
## EPITECH PROJECT, 2019
## makefile by yann
## File description:
## Makefile
##

.PHONY: all clean fclean re src/%.o everything yann secu git debuggit

define preparerepo =
*.o
*~
*.a
\#*#
vgcore*
Debug
.xml*
.iml*
Release
CMakeLists.txt*
*.kate-swp
endef

define my_important_secu =
#!/bin/bash

DELAY=5 # Number of seconds to display results
while true; do
    clear
	cat << EOF
        Please Select:
        1. Display Helps
        2. Sign up
        3. Sign in
        4. Encrypted a File
        5. Decryptted last File
        6. Display a file
        0. Quit
EOF
    read -p "Enter selection [0-6] > "
    case "$REPLY" in
        0)
            break
            ;;
        1)
            make help
            ;;
        2)
            echo "Username"
			read create_username
			echo "Password"
			read create_password1
			echo "Password"
			read create_password2
			if [$create_password1 != $create_password2] ; then
				break ;
			else
				echo $create_username > .account_username
				echo $create_password2 > .account_password
				gpg -c .account_username
				gpg -c .account_password
				rm -rf .account_username
				rm -rf .account_password
			fi
            ;;
        3)
			make sign
            ;;
        4)
            echo "write file at encrypted"
            read file
            gpg -c $file
            echo "I have encrypted the file sucessfully..."
            echo "Now I will be removing the original file"
            rm -rf $file
            ;;
        5)
            gpg -d $file.gpg > $file
            rm -rf $file.gpg
            echo "file decrypted"
            ;;
        6)
            echo "Entry the file:"
            read file2
            more $file2
            ;;
        *)
            echo "Invalid entry."
            ;;
    esac
    sleep "$DELAY"
done
echo "Program terminated."
endef

USER := $(shell whoami)

NAME	=	navy

git: m = git auto

debuggit: m = debug git auto

I-NAME = "$(preparerepo)"

DIR-NAME = src

FILE-NAME =

PERMITION-NAME = ramassage-tek

FILE = .gitignore

foo := $(if $(NAME),then!,tu n'est pas Yann!)

PROJECT := $(shell realpath .)

RM	=	rm -rf

PRINT = $(shell printf '%0.1s' '*'{1..5})

CLEAR = echo -e "\033[31m* * * * *  CLEANED SUCCESSFUL  * * * * *\033[0m"

SUBDIRS = $(shell ls)

SRCS	=	$(wildcard src/*.c)

LIBSRCS =	$(wildcard lib/*.c)

OBJS	=	$(SRCS:.c=.o)

LIBOBJS =	$(LIBSRCS:.c=.o)

CFLAGS	+=	 -Wall -Wextra -Iinclude -O3 #-ansi -pedantic -std=c99

CFLAGCLANG += clang -Wno-padded -Weverything -g -g3 -ggdb

all:	$(NAME)

## quick description of my makefile
help:
	@echo -e "\e[mmon executable \e[4m${NAME}\e[0m"
	@echo -e "\e[mj'utilise les flags \e[4m${CFLAGS}\e[0m et \e[4m$(CFLAGCLANG)\e[0m"

src/%.o:	src/%.c
	@$(CC) $(CFLAGS) $(LDFLAGS) -c -o $@ $< && echo -e "\e[32m[OK]\033[0m\e[1m\e[32m" $< "\033[0m" || echo -e "\e[91;5m[KO]\e[25m" $< "\033[5m\n    T'est même pas capable de compiler sans error t'est une merde yann"

$(NAME): $(OBJS)
#@ar -rc libmy.a $(LIBOBJS)
	@$(CC) $(OBJS) -o $(NAME) $(CFLAGS)
	@$(eval($(MAK) := 9))
	@if [ $(USER) = "YANN" ]; then echo -e " ██╗   ██╗███████╗ ███╗   ██╗ ███╗   ██╗"; fi
	@if [ $(USER) = "YANN" ]; then echo -e " ╚██╗ ██╔╝██╔══██║ ████╗  ██║ ████╗  ██║"; fi
	@if [ $(USER) = "YANN" ]; then echo -e "  ╚████╔╝ ███████║ ██╔██╗ ██║ ██╔██╗ ██║"; fi
	@if [ $(USER) = "YANN" ]; then echo -e "   ╚██╔╝  ██╔══██║ ██║╚██╗██║ ██║╚██╗██║"; fi
	@if [ $(USER) = "YANN" ]; then echo -e "    ██║   ██║  ██║ ██║ ╚████║ ██║ ╚████║"; fi
	@if [ $(USER) = "YANN" ]; then echo -e "    ╚═╝   ╚═╝  ╚═╝ ╚═╝  ╚═══╝ ╚═╝  ╚═══╝\033[0m"; fi

ifeq ($(MAK),)
	@if [ $(USER) != "YANN" ]; then echo -e "\e[1mCOMPILATION BY \e[4m$(USER)\e[0m \e[5mHAHAHA!\e[0m"; fi
ifeq ($(USER),YANN)
	@echo -e "\e[1mCOMPILATION BY THE KING \e[4m$(USER)\e[0m \033[5mHAHAHA!\e[0m"
	@echo -e "\033[32m$(PRINT) COMPLETED SUCCESSFUL $(PRINT)\033[0m"
endif
endif

git: fclean# for use:   make git m="your message"
	@git pull
	@git add .
	@git commit -m "$(m)"
	@git push

debuggit: fclean
	@git add .
	@git commit -m "$(m)"
	@git pull
	@git push

# delete files
fclean: clean
	@-$(RM) $(NAME)
	@-$(CLEAR)
#@-for i in $(SUBDIRS); do (cd $$i; $(MAKE) clear; $(RM) *.a; $(RM) *~); done

clean:
	@-$(RM) $(OBJS)

ifeq ($(USER),YANN)
#@clear
endif

re: fclean all

everything:
	@$(CFLAGCLANG) -I include $(SRCS) -o ${NAME}

debug:
	@make -d -w --trace

sign:
	@echo "Username"
	@read username
	@echo "Password"
	@read password
	@echo "Password"
	@gpg -d .account_username.gpg > .account_username
	@gpg -d .account_password.gpg > .account_password
	@rm .account_username.gpg
	@rm .account_password.gpg
	$(eval($(MAK2) := "yes"))
#@find . -type f | grep .account

ifeq ($(MAK2),)
	@echo "CONNEXION SUCCESSFUL"
else
	@echo "CONNEXION FAILURE"
endif

#$(if $(filter $$username,YANN), @echo SUCCESSFUL, @echo failure);

my-important-secu: ; $(value my_important_secu)

create_repo:
	blih -u yann.nshare@epitech.eu repository create $(name)
	blih -u yann.nshare@epitech.eu repository setacl $(name) $(PERMITION-NAME)
	blih -u yann.nshare@epitech.eu repository getacl $(name)

clone_repo:
	git config --global user.email "yann.nshare@epitech.eu"
	git clone git@git.epitech.eu:/yann.nshare@epitech.eu/$(name)

preparerepo:
	@-mkdir $(DIR-NAME)
	@-touch $(FILE-NAME)
	@-echo $(I-NAME) >> $(FILE)

.ONESHELL:

yann:
	@echo -e "\e[m\e[1mYANN IS A KING OF \e[44mEPITECH\e[0m"
	@echo -e "\e[1mbow down to me HAHAHA! \e[0m\e[5mRIGHT NOW\e[0m"
	@echo -e "\e[mmaintenant tu peu executer mon executable \e[4m${NAME}\e[0m"
	@echo -e "\e[men plus j'utilise les flags \e[4m${CFLAGS}\e[0m et \e[4m$(CFLAGCLANG)\e[0m"
	@echo -e "\e${SRCS}\e[0m"
	@echo $(foo)

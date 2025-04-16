WFLAGS=-Wall -Wextra

ifeq ($(subst cc,,${CC}),)
CC=gcc
endif

ifndef OPT
OPT=-O3
endif

ifeq ($(strip ${WARNINGS}), all)
WFLAGS+= -Wpedantic -Wshadow -Wconversion -Wpointer-arith
else ifeq ($(strip ${WARNINGS}), none)
WFLAGS=
endif

ifeq ($(strip ${STRICT}), 1)
WFLAGS+= -Werror
endif

ifeq ($(strip ${LTO}), 1)
LTOFLAG=-flto
else ifdef LTO
LTOFLAG=-flto=${LTO}
else
LTOFLAG=
endif

ifdef ARCH
ARCHFLAG=-march=${ARCH}
else
ARCHFLAG=
endif

refstr :
		$(CC) ${OPT} ${WFLAGS} ${ARCHFLAG} ${LTOFLAG} -o refstr src/refs.c
clean :
		@rm refstr
check :
		@"$(SHELL)" test/test_refstr.sh
.PHONY : clean check
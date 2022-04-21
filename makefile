CC=gcc

CFLAGS=-c -Wall

LDFLAGS=

SRCS=menu.c lab1t.c InfoDef.c composition.c

OBJS=$(SRCS:.c=.o)

EXE=lab1test

all: $(SRCS) $(EXE)

$(EXE): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@
.c.o:
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm -rf $(OBJS) $(EXE)
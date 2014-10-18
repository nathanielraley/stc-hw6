EXEC1:=linear_equation
EXEC2:=linear_inverse
SRC1:=$(wildcard *n.c)
SRC2:=$(wildcard *e.c)
OBJ1:=$(patsubst %.c,%.o,$(SRC1))
OBJ2:=$(patsubst %.c,%.o,$(SRC2))

CC:=icc
CFLAGS:=
LDFLAGS:= -L$$TACC_MKL_LIB 
LDLIBS:= -lmkl_intel_lp64 -lmkl_core -lmkl_sequential -lpthread


$all: $(EXEC1) $(EXEC2)

$(EXEC1): $(OBJ1)
	$(CC) $(LDFLAGS) $(LDLIBS) -o $@ $^
$(EXEC2): $(OBJ2)
	$(CC) $(LDFLAGS) $(LDLIBS) -o $@ $^
%.o: %.c
	$(CC) $(CFLAGS) -c $<
clean:
	$(RM) $(EXEC1) $(EXEC2) $(OBJ) *.o




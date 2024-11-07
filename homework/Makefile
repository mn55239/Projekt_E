# Definicija varijabli
CC = gcc
#CFLAGS = -Wall -Werror -Iinclude
OBJDIR = obj
SRCDIR = src
TESTDIR = test
LIBS =

# Automatsko otkrivanje svih .c datoteka u src direktoriju
SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SOURCES))

# Automatsko otkrivanje svih .c datoteka u test direktoriju
TEST_SOURCES = $(wildcard $(TESTDIR)/*.c)
TEST_OBJECTS = $(patsubst $(TESTDIR)/%.c,$(OBJDIR)/%.o,$(TEST_SOURCES))

INC = inc/
CFLAGS = -Wall -Werror -Iinclude -I $(INC)

# Cilj za izgradnju izvršnog programa
EXEC = main

# Default cilj koji gradi izvršni program
all: $(EXEC)

# Pravilo za izgradnju izvršnog programa
$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXEC) $(LIBS)

# Pravilo za izgradnju objektnih datoteka
$(OBJDIR)/%.o: $(SRCDIR)/%.c $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Pravilo za izgradnju direktorija obj
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Cilj za čišćenje svih objektnih i izvršnih datoteka
clean:
	rm -f $(OBJDIR)/*.o $(EXEC) $(TESTDIR)/test_file_io $(TESTDIR)/test_compute

# Cilj za pokretanje svih testova
run_tests: $(TESTDIR)/test_file_io $(TESTDIR)/test_compute
	./$(TESTDIR)/test_file_io
	./$(TESTDIR)/test_compute
	
# Cilj za izgradnju testova za file_io
test_io: $(TESTDIR)/test_file_io
	./$(TESTDIR)/test_file_io

# Cilj za pokretanje testova file_io
run_test_file_io: $(TESTDIR)/test_file_io
	./$(TESTDIR)/test_file_io

# Cilj za pokretanje testova compute
run_test_compute: $(TESTDIR)/test_compute
	./$(TESTDIR)/test_compute

# Pravilo za izgradnju testova
$(TESTDIR)/test_file_io: $(TESTDIR)/test_file_io.c $(SRCDIR)/file_io.c
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

$(TESTDIR)/test_compute: $(TESTDIR)/test_compute.c $(SRCDIR)/compute.c
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

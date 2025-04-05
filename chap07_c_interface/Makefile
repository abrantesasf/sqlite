# ******************************************************************************
# Arquivo: Makefile
# Versão : 3.2
# Data   : 2025-03-14 22:02
# Por    : Abrantes Araújo Silva Filho
# ------------------------------------------------------------------------------


# ******************************************************************************
# Configuração inicial da Makefile:

# Ajuste a variável DIRETORIO para o diretório de instalação da CSLIB.
# Acrescente outros diretórios para header files e arquivos conforme
# necessidade.
DIRETORIO = /opt/cr/cslib

# As variáveis abaixo estão OK (NÃO ALTERE!):
CC = gcc
CSLIB = -lcslib
CRPAIC = -lCRpaic
SQLITE = -ldl -lpthread -lreadline -lncurses
ICU = -licuio -licui18n -licuuc -licudata
CUNIT = -lcunit

# Configura as flags do compiler e do linkes. Não altere se não souber
# o que está fazendo!
CFLAGS = -L$(DIRETORIO) -I$(DIRETORIO) -std=c17 -Wall -Wextra -Werror -Wpedantic
CFLAGSSQLITE = -L$(DIRETORIO) -I$(DIRETORIO) -Wall
MODO = debug
ifeq ($(MODO), debug)
    CFLAGS += -ggdb -O0 -Ddebug
else ifeq ($(MODO), producao)
    CFLAGS += -O2
endif

LFLAGS = $(CSLIB) $(CRPAIC) -lm -lX11 -lcrypt -ledit $(SQLITE) $(ICU) $(CUNIT)
BIBS = dinamicas
ifeq ($(BIBS), estaticas)
    LFLAGS += -static
endif

SQLITEFLAGS = -DSQLITE_DEFAULT_FOREIGN_KEYS=1 -DSQLITE_CASE_SENSITIVE_LIKE \
	      -DSQLITE_ENABLE_COLUMN_METADATA -DSQLITE_ENABLE_EXPLAIN_COMMENTS \
	      -DSQLITE_ENABLE_FTS3 -DSQLITE_ENABLE_FTS3_PARENTHESIS -DSQLITE_ENABLE_FTS4 \
	      -DSQLITE_ENABLE_FTS5 -DSQLITE_ENABLE_GEOPOLY -DSQLITE_ENABLE_HIDDEN_COLUMNS \
	      -DSQLITE_ENABLE_ICU -DSQLITE_ENABLE_IOTRACE -DSQLITE_ENABLE_MATH_FUNCTIONS \
	      -DSQLITE_ENABLE_MEMORY_MANAGEMENT -DSQLITE_ENABLE_MEMSYS5 \
	      -DSQLITE_ENABLE_NORMALIZE -DSQLITE_ENABLE_ORDERED_SET_AGGREGATES \
	      -DSQLITE_ENABLE_PREUPDATE_HOOK -DSQLITE_ENABLE_RTREE -DSQLITE_ENABLE_STAT4 \
	      -DSQLITE_SOUNDEX -DHAVE_READLINE


# ******************************************************************************
# Programas a serem compilados (pode ser tudo em uma única linha, mas colocar um
# nome por linha facilita a exclusão e a visualização):
PROGRAMAS = \
	    sqlite3.o \
	    exemplo01 \
	    exemplo02


# ******************************************************************************
# Regra padrão: compila todos os programas (NÃO ALTERE!)
all: $(PROGRAMAS)


# ******************************************************************************
# Regras individuais de compilação: crie as regras específicas de cada target:
sqlite3.o: sqlite3.h sqlite3.c
	$(CC) $(SQLITEFLAGS) $(CFLAGSSQLITE) -c -o sqlite3.o sqlite3.c $(LFLAGS)

exemplo01: exemplo01.c sqlite3.h sqlite3.o
	$(CC) $(CFLAGS) -o exemplo01 exemplo01.c sqlite3.o $(LFLAGS)

exemplo02: exemplo02.c sqlite3.h sqlite3.o
	$(CC) $(CFLAGS) -o exemplo02 exemplo02.c sqlite3.o $(LFLAGS)


# ******************************************************************************
# Regras para a limpeza final (NÃO ALTERE!)
limpar:
	rm -f *~ a.out core graphics.ps

apagar: limpar
	rm -f *.o *.a $(PROGRAMAS)

# 3. Building and Installing SQLite

## 3.1. SQLite Products
O SQLite é formado, na verdade, por 4 grandes "produtos":

* **SQLite Core**: é a database engine propriamente dita e a API pública;
* **sqlite3**: é a aplicação CLI cliente;
* **TCL Extension**: é a database engine acrescida de bindings TCL; e
* **SQLite Analyzer**: é uma ferramenta de análise dos arquivos dos bancos de
  dados.
  
## 3.3. Documentação
A documentação disponível no site oficial reflete **sempre** a documentação da
versão mais recente, não existem cópias de documentação de versões
anteriores. Assim, para que se consiga manter cópias de versões "anteriores" da
documentação (para que corresponda à versão que se está de fato utilizando),
devemos fazer o download da documentação junto com o SQLite.

## 3.4. Distribuição dos fontes
Os arquivos disponíveis são os seguintes:

* `sqlite3.c`: é o arquivo conhecido como "The Amalgamation", um arquivo C único
  que contém o compilado de todos os outros arquivos de código; Esse arquivo
  corresponde à SQLite Core, a engine;
* `sqlite3.h`: é a interface com a API pública;
* `sqlite3ext.h`: é a interface utilizada para compilar algumas extensões;
* `shell.c`: é o arquivo C com o código da aplicação CLI cliente.

Existe também uma versão do "The Amalgamation" que tem um *configure script* que
pode ser utilizado em sistemas Unix/Linux.

## 3.5. Compilando
A compilação do SQLite pode ser feita diretamente, sem alterar nenhuma opção, ou
pode ser ajustada especificamente para suas necessidades. Existem **DEZENAS** de
opções de configuração, que devem ser consultadas na documentação.

Abaixo está um exemplo de comando de compilação que altera diversos
comportamentos e ativa muitas extensões do SQLite, incluindo o uso de threads,
readline, ICU e outros. O comando abaixo fará a compilação da Engine e da
Aplicação CLI cliente em uma única aplicação, fazendo com que o `sqlite3`
executável gerado não necessite de nenhuma outra biblioteca.

gcc -DSQLITE_DEFAULT_FOREIGN_KEYS=1 -DSQLITE_CASE_SENSITIVE_LIKE \
-DSQLITE_ENABLE_COLUMN_METADATA -DSQLITE_ENABLE_EXPLAIN_COMMENTS \
-DSQLITE_ENABLE_FTS3 -DSQLITE_ENABLE_FTS3_PARENTHESIS -DSQLITE_ENABLE_FTS4 \
-DSQLITE_ENABLE_FTS5 -DSQLITE_ENABLE_GEOPOLY -DSQLITE_ENABLE_HIDDEN_COLUMNS \
-DSQLITE_ENABLE_ICU -DSQLITE_ENABLE_IOTRACE -DSQLITE_ENABLE_MATH_FUNCTIONS \
-DSQLITE_ENABLE_MEMORY_MANAGEMENT -DSQLITE_ENABLE_MEMSYS5 \
-DSQLITE_ENABLE_NORMALIZE -DSQLITE_ENABLE_ORDERED_SET_AGGREGATES \
-DSQLITE_ENABLE_PREUPDATE_HOOK -DSQLITE_ENABLE_RTREE -DSQLITE_ENABLE_STAT4 \
-DSQLITE_SOUNDEX -DHAVE_READLINE -o sqlite3 shell.c sqlite3.c -ldl -lm \
-lpthread -lreadline -lncurses -licuio -licui18n -licuuc -licudata

## 3.6. Considerações
A maneira recomendada de compilar o SQLite é integrar a engine diretamente em
sua aplicação. A maneira mais fácil de fazer isso é compilar a engine como uma
biblioteca estática e, então, fazer linking com ela, ou então simplesmente
compilar o "The Amalgamation" diretamente junto com o código de sua
aplicação. Isso faz com que a engine seja diretamente ligada à sua aplicação,
eliminando a possibilidade de incompatibilidade entre versões.

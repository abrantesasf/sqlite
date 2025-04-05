/**
 * Exemplo 02: capítulo 7, página 132.
 */

#include "sqlite3.h"
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
    char *dbfile = "";
    sqlite3 *dbcon = NULL;
    int dbstatus = 0;

    if (argc > 1)
        dbfile = argv[1];

    sqlite3_initialize();

    dbstatus = sqlite3_open_v2(dbfile, &dbcon,
                               SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE,
                               NULL);
    if (dbstatus != SQLITE_OK)
    {
        sqlite3_close_v2(dbcon);
        fprintf(stderr, "Erro ao abrir a conexão ao SQLite.\n");
        return EXIT_FAILURE;
    }
    else
        printf("Conexão ao SQLite foi bem sucedida.\n");

    sqlite3_stmt *stmt = NULL;
    char *sql = "CREATE TABLE alunos ("
                "  nome  TEXT,"
                "  idade INTEGER,"
                "  sexo  TEXT"
                ");";
    dbstatus = sqlite3_prepare_v3(dbcon, sql, -1, 0, &stmt, NULL);
    if (dbstatus != SQLITE_OK)
    {
        sqlite3_close_v2(dbcon);
        fprintf(stderr, "Erro ao preparar SQL.\n");
        return EXIT_FAILURE;
    }

    dbstatus = sqlite3_step(stmt);
    if (dbstatus != SQLITE_DONE)
    {
        sqlite3_close_v2(dbcon);
        fprintf(stderr, "Erro ao executar SQL.\n");
        return EXIT_FAILURE;
    }

    sqlite3_finalize(stmt);

    printf("SQL executado com sucesso.\n");

    sqlite3_close_v2(dbcon);
    sqlite3_shutdown();

    return EXIT_SUCCESS;
}

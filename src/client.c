#include <stdio.h>
#include <libpq-fe.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

static void pg_exit(PGconn *pgconn) {
    PQfinish(pgconn);
    exit(1);
}

int main() {

    /* You can create your own environment variables and change their names and adapt them below */
    const char *host = getenv("PG_HOST");
    const char *port = getenv("PG_PORT");
    const char *database = getenv("PG_DATABASE");
    const char *user = getenv("PG_USER");
    const char *password = getenv("PG_PASSWORD");

    char connection[256];
    // Format: "host=your_host port=your_port dbname=your_database user=your_user password=your_password"
    snprintf(connection, sizeof(connection), "host=%s port=%s dbname=%s user=%s password=%s", host, port, database, user, password);

    PGconn *pgconn = PQconnectdb(connection);
    PGresult *res;

    if (PQstatus(pgconn) != CONNECTION_OK) {
        fprintf(stderr, "Error! No connection established! %s\n", PQerrorMessage(pgconn));
        pg_exit(pgconn);
    }
    
    res = PQexec(pgconn, "SELECT tablename FROM pg_catalog.pg_tables WHERE schemaname='public'");

    return 0;
}
#include <stdio.h>
#include <libpq-fe.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

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

    if (PQstatus(pgconn) == CONNECTION_OK) {
        printf("Connected!\n");
    } else {
        fprintf(stderr, "Error! No connection established! %s\n", PQerrorMessage(pgconn));
        PQfinish(pgconn);
        exit(1);
    }
    
    return 0;
}
#include <stdio.h>
#include <libpq-fe.h>
#include <ncurses.h>
#include <stdlib.h>

int main()
{

    /* You can create your own environment variables and change their names and adapt them below */
    const char *host = getenv("PG_HOST");
    const char *database = getenv("PG_DATABASE");
    const char *user = getenv("PG_USER");
    const char *password = getenv("PG_PASSWORD");

    return 0;
}
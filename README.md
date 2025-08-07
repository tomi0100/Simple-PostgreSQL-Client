# Simple-PostgreSQL-Client
A simple and lightweight client for connecting to a PostgreSQL-Database through the terminal

## Libraries used
- libpq
- libncurses

### For Linux
```
$ sudo apt install libpq-dev libncurses-dev
```

> [!WARNING]
> You might have to include the installation path of the header file "libpq-fe.h" in your IDE to be able to compile later on

Be sure to compile with the flags in the command below:

```
$ gcc -o /path/to/output/client /path/to/src/client.c -I/usr/include/postgresql -lpq -lncurses
```

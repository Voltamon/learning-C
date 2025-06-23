#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <string.h>

sqlite3 *open_database(char *DB_name); // For opening the database
void close_database(sqlite3 *DB); // For closing the database
void create_table(sqlite3 *DB, char *table_name, int fields_count, char *fields[]); // For creating a new table
void insert_data(sqlite3 *DB, char *table_name, int data_count, char *data[]); // For inserting data into table
void delete_data(sqlite3 *DB, char *table_name, char *condition); // For deleting data from table

sqlite3 *open_database(char *DB_name) {
    sqlite3 *DB;
    int exit;

    exit = sqlite3_open(DB_name, &DB);
    if (exit) {
        fprintf(stderr, "Failed to open %s\n", DB_name);
        fflush(stderr);

        return NULL;
    }

    fprintf(stdout, "Opened %s successfully\n", DB_name);
    fflush(stdout);

    return DB;
}

void close_database(sqlite3 *DB) {
    sqlite3_close(DB);
    return;
}

void create_table(sqlite3 *DB, char *table_name, int fields_count, char *fields[]) {
    char *query;
    size_t field_size = 50;
    size_t query_size = field_size * fields_count + 25;

    char *errorMessage;
    int exit;

    query = malloc(query_size);
    if (!query) {
        fprintf(stderr, "Failed to allocate memory");
        fflush(stderr);

        free(query);
        free(errorMessage);

        return;
    }

    snprintf(query, 25, "CREATE TABLE %s (", table_name);

    for (int i = 0; i < fields_count; i++) {
        if (query_size - strlen(query) <= strlen(fields[i]) + 3) {
            fprintf(stderr, "Too long fields. Failed to create %s\n", table_name);
            fflush(stderr);

            free(query);
            free(errorMessage);

            return;
        }

        strncat(query, fields[i], query_size - strlen(query) - 1);
        if (i < fields_count - 1)
            strncat(query, ", ", query_size - strlen(query) - 1);
    }

    strncat(query, ");", 3);

    exit = sqlite3_exec(DB, query, NULL, 0, &errorMessage);
    if (exit != SQLITE_OK) {
        fprintf(stderr, "Failed to create %s\n", table_name);
        fprintf(stderr, "%s", errorMessage);
        fflush(stderr);

        free(query);
        sqlite3_free(errorMessage);

        return;
    }

    fprintf(stdout, "Created %s successfully\n", table_name);
    fflush(stdout);

    return;
}

void insert_data(sqlite3 *DB, char *table_name, int data_count, char *data[]) {
    char *query;
    size_t data_size = 30;
    size_t query_size = data_size * data_count + 30;

    int exit;
    char *errorMessage;

    query = malloc(query_size);
    if (!query) {
        fprintf(stderr, "Failed to allocate memory");
        fflush(stderr);

        free(query);
        free(errorMessage);

        return;
    }

    snprintf(query, 30, "INSERT INTO %s VALUES (", table_name);

    for (int i = 0; i < data_count; i++) {
        if (query_size - strlen(query) <= strlen(data[i]) + 3) {
            fprintf(stderr, "Too much data. Failed to insert data into %s", table_name);
            fflush(stderr);

            free(query);
            free(errorMessage);

            return;
        }

        strncat(query, data[i], query_size - strlen(query) - 1);
        if (i < data_count - 1)
            strncat(query, ", ", query_size - strlen(query) - 1);
    }

    strncat(query, ");", 3);

    exit = sqlite3_exec(DB, query, NULL, 0, &errorMessage);
    if (exit != SQLITE_OK) {
        fprintf(stderr, "Failed to insert data into %s", table_name);
        fprintf(stderr, "%s", errorMessage);
        fflush(stderr);

        free(query);
        sqlite3_free(errorMessage);

        return;
    }

    fprintf(stdout, "Successfully inserted data into %s\n", table_name);
    fflush(stdout);

    return;
}

void delete_data(sqlite3 *DB, char *table_name, char *condition) {
    char *query;
    size_t query_size = strlen(table_name) + strlen(condition) + 30;

    int exit;
    char *errorMessage;

    query = malloc(query_size);
    if (!query) {
        fprintf(stderr, "Failed to allocate memory");
        fflush(stderr);

        free(query);
        free(errorMessage);

        return;
    }

    snprintf(query,query_size, "DELETE FROM %s WHERE %s;", table_name, condition);

    exit = sqlite3_exec(DB, query, NULL, 0, &errorMessage);
    if (exit != SQLITE_OK) {
        fprintf(stderr, "Failed to delete data from %s\n", table_name);
        fprintf(stderr, "%s\n", errorMessage);
        fflush(stderr);

        sqlite3_free(errorMessage);
        free(query);

        return;
    }

    fprintf(stdout, "Successfully deleted data from %s\n", table_name);
    fflush(stdout);

    free(query);
    free(errorMessage);

    return;
}

int main(int argc, char **argv) {
    sqlite3 *DB = open_database("example.db");
    if (!DB) return 1;

    // char *tableName = "PERSON";

    /*
    * For creating a table

    char *fields[3] = {
        "NAME TEXT NOT NULL",
        "AGE INT NOT NULL",
        "ADDRESS CHAR(50) NOT NULL"
    };

    create_table(DB, tableName, 3, fields);
    */

    /*
    * For inserting data into a table

    char *data[3] = {
        "\'SWARNAVO DE\'",
        "18",
        "\'RK Pally, Kolkata\'"
    };

    insert_data(DB, tableName, 3, data);
    */

    /*
    * Deleting data from a table;
    delete_data(DB, tableName, "NAME = \'SWARNAVO DE\'");
    */

    close_database(DB);
    return 0;
}

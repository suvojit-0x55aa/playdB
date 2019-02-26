#ifndef STATEMENT_HANDLER_H
#define STATEMENT_HANDLER_H

#include <string.h>
#include "console_handler.h"

enum PrepareResult_t { 
    PREPARE_SUCCESS, 
    PREPARE_UNRECOGNIZED_STATEMENT 
};
typedef enum PrepareResult_t PrepareResult;

enum StatementType_t {
    STATEMENT_INSERT,
    STATEMENT_SELECT
};
typedef enum StatementType_t StatementType;

struct Statement_t {
    StatementType type;
};
typedef struct Statement_t Statement;


PrepareResult prepare_statement(InputBuffer* input_buffer,
                                Statement* statement) {
    if(strncmp(input_buffer->buffer, "insert", 6) == 0) {
        statement->type = STATEMENT_INSERT;
        return PREPARE_SUCCESS;
    }
    else if(strncmp(input_buffer->buffer, "select", 6) == 0) {
        statement->type = STATEMENT_SELECT;
        return PREPARE_SUCCESS;
    }
    else {
        return PREPARE_UNRECOGNIZED_STATEMENT;
    }
}

void execute_statement(Statement* statement) {
    switch(statement->type) {
        case (STATEMENT_INSERT):
            printf("This is where we would do an insert.\n");
            break;
        case (STATEMENT_SELECT):
            printf("This is where we would do a select.\n");
            break;
    }
}

#endif
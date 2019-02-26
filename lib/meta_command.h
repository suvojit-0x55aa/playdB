#ifndef META_COMMAND_H
#define META_COMMAND_H

#include <string.h>
#include "console_handler.h"

enum MetaCommandResult_t {
  META_COMMAND_SUCCESS,
  META_COMMAND_UNRECOGNIZED
};
typedef enum MetaCommandResult_t MetaCommandResult;

MetaCommandResult do_meta_command(InputBuffer* input_buffer){
    if (strcmp(input_buffer->buffer, ".exit") == 0){
        exit(EXIT_SUCCESS);
    }
    else {
        return META_COMMAND_UNRECOGNIZED;
    }
}

#endif


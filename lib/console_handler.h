#ifndef CONSOLE_HANDLER_H
#define CONSOLE_HANDLER_H
#include <stdio.h>
#include <stdlib.h>
#include "input_buffer.h"

void print_prompt(){
    printf("db > ");
}

void read_input(InputBuffer* input_buffer){
    ssize_t bytes_read = getline(&(input_buffer->buffer), &(input_buffer->buffer_length), stdin);

    if (bytes_read <= 0){
        printf("Error reading input\n");
        exit(EXIT_FAILURE);
    }

    //Ignore trailing newline.
    input_buffer->input_length = bytes_read - 1;
    input_buffer->buffer[bytes_read - 1] = 0;
}

#endif
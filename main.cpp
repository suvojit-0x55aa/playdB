#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "lib/input_buffer.h"
#include "lib/console_handler.h"


int main(int argc, char* argv[]){
    InputBuffer* input_buffer = new_input_buffer();

    while(true){
        print_prompt();
        read_input(input_buffer);

        if (strcmp(input_buffer->buffer, ".exit") == 0){
            exit(EXIT_SUCCESS);
        }
        else{
            printf("Unrecognized command '%s'.\n", input_buffer->buffer);
        }
    }
}

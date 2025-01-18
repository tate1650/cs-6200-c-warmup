#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

// TODO: Check tests-to-write.todo for test cases I should check for in munit

int main(int argc, char *argv[])
{
  if (argc != 3) {
    printf("Usage: %s INPUT_PATH OUTPUT_PATH\n", argv[0]);
    exit(1);
  }

  char *input_file_name = argv[1];
  char *output_file_name = argv[2];

  FILE *input_file_ptr = fopen(input_file_name, "r");
  if (input_file_ptr == NULL) {
    printf("Error: File at path %s not found\n", input_file_name);
    exit(1);
  }

  FILE *output_file_ptr = fopen(output_file_name, "w");
  if (output_file_ptr == NULL) {
    printf("Error: File at path %s not found\n", output_file_name);
    exit(1);
  }

  size_t buffer_size = 128;
  char buffer[buffer_size];
  memset(buffer, 0, buffer_size); // So we can null-terminate and read buffer as a string
  int sum = 0;
  while (fgets(buffer, buffer_size, input_file_ptr) != NULL) {
    char *endptr = NULL;
    char *startptr = buffer;
    
    while (true) {
      // Assuming integer list is properly formatted
      int current_int = (int) strtol(startptr, &endptr, 10);
      
      if (*endptr == '\0' || *endptr == '-') break; // End of buffer; could have a lone '-' from a negative int
      
      sum += current_int;

      if (*endptr == '\n') { // Sum complete (and end of data in buffer)
        fprintf(output_file_ptr, "%d\n", sum);
        sum = 0;
        break;
      } else if (*endptr != ' ') { // Shouldn't happen
        printf("Error: strtol endptr pointing to non-null and non-whitespace character: '%c'\n", *endptr);
        exit(1);
      }

      startptr = endptr + 1; // Skip the current whitespace character to start next int
    }

    // If last character in buffer is a digit/- (instead of whitespace) we CANNOT add it!
    // We don't know if we're at the end of the int. Hence, we need to reset the file pointer to the
    // start of the current int.
    size_t offset = 0;
    size_t buffer_data_len = strlen(buffer);
    for (
      char *last_buffer_char = &buffer[buffer_data_len-1]; // Because buffer[buffer_data_len] is the null terminator
      isdigit(*last_buffer_char) || *last_buffer_char == '-';
      last_buffer_char--
    ) offset++;

    if (fseek(input_file_ptr, (-1 * offset), SEEK_CUR) == -1) {
      printf("Error while executing fseek (code: %d)\n", errno);
      exit(1);
    }
    
    memset(buffer, 0, buffer_size); // Clear buffer for next read
  }

  fclose(input_file_ptr);
  fclose(output_file_ptr);
}

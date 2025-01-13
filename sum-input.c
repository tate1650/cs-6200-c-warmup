#include <stdio.h>

// TOOD: Check tests-to-write.todo for test cases I should check for in munit

int main(int argc, char *argv[])
{
  if (argc != 3) {
    printf("Usage: %s INPUT_PATH OUTPUT_PATH\n", argv[0]);
    exit(1);
  }

  char *input_file_name = argv[1];
  char *output_file_name = argv[2];

  FILE *input_file_ptr;
  FILE *output_file_ptr;

  if (input_file_ptr = fopen(input_file_name, "r") == NULL) {
    printf("Error: File at path %s not found", input_file_name);
    exit(1);
  } else if (output_file_ptr = fopen(output_file_name, "w") == NULL) {
    printf("Error: File at path %s not found", output_file_name);
    exit(1);
  }

  // TODO: Read input file

  // TODO: convert input to ints and create sums

  // TODO: write sums to output file

  fclose(input_file_ptr);
  fclose(output_file_ptr);
}

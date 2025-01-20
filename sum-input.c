#include <stdlib.h>
#include "sum-input-main.h"

int main(int argc, char *argv[])
{
  int program_result = sum_input_main(argc, argv);
  if (program_result) exit(1);
}

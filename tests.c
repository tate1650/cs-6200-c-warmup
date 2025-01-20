#include "munit/munit.h"
#include "sum-input-main.h"

// TESTS

MunitResult test_incorrect_arg_count(const MunitParameter params[], void* user_data_or_fixture) {
  char *arg0 = "./sum-input";
  char *arg1 = "test-input.txt";
  char *arg2 = "test-output.txt";
  char *sample_args[3] = {arg0, arg1, arg2};

  if (sum_input_main(1, (char**) &sample_args) == 0) return MUNIT_FAIL;
  else if (sum_input_main(5, (char**) &sample_args) == 0) return MUNIT_FAIL;

  return MUNIT_OK;
}

// SUITES

MunitTest tests[] = {
  {
    "/example-test", /* name */
    test_incorrect_arg_count, /* test */
    NULL, /* setup */
    NULL, /* tear_down */
    MUNIT_TEST_OPTION_NONE, /* options */
    NULL /* parameters */
  },
  /* Mark the end of the array with an entry where the test
   * function is NULL */
  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

static const MunitSuite suite = {
  "/my-tests", /* name */
  tests, /* tests */
  NULL, /* suites */
  1, /* iterations */
  MUNIT_SUITE_OPTION_NONE /* options */
};

int main (int argc, char* argv[]) {
  return munit_suite_main(&suite, NULL, argc, argv);
}

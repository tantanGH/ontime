#include <stdio.h>
#include <stdint.h>
#include <process.h>
#include <iocslib.h>

int32_t main(int32_t argc, uint8_t* argv[]) {

  // default return code
  int32_t rc = -1;

  // argument check
  if (argc < 2) {
    printf("usage: ontime <exec-file> [exec-options]\n");
    goto exit;
  }

  // start time
  uint32_t t0 = ONTIME();

  // child process execution
  if (spawnvp(P_WAIT, argv[1], (const char**)(argv+1)) < 0) {
    printf("error: process execution error.\n");
    goto exit;
  }

  // end time
  uint32_t t1 = ONTIME();

  // output result
  printf("Execution time ... %4.2f [sec]\n", (t1 - t0) / 100.0);

  // success
  rc = 0;

exit:
  return rc;
}
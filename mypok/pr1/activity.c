/*
 *                               POK header
 *
 * The following file is a part of the POK project. Any modification should
 * be made according to the POK licence. You CANNOT use this file or a part
 * of a file for your own project.
 *
 * For more information on the POK licence, please see our LICENCE FILE
 *
 * Please follow the coding guidelines described in doc/CODING_GUIDELINES
 *
 *                                      Copyright (c) 2007-2021 POK team
 */

#include <core/thread.h>
#include <libc/stdio.h>

void kill_time(unsigned int cycle) {
  for (unsigned int i = 0; i < cycle; i++) {
    for (unsigned int j = 2; j < 1000; j++) {
      for (unsigned int k = 2; k < j; k++) {
        int temp = j % k;
      }
    }
  }
}

void *pinger_job() {
  while (1) {
    printf("Take a rest!\n");
    kill_time(100000);
    pok_thread_sleep(20000);
  }
}

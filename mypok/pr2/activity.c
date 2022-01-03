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

#include <core/partition.h>
#include <core/thread.h>
#include <core/time.h>
#include <libc/stdio.h>
char getc() {
  int ret;
  while (1) {
    ret = getChar();
    if (ret != -1) {
      return (char)ret;
    }
  }
}
void kill_time(unsigned int cycle) {
  for (unsigned int i = 0; i < cycle; i++) {
    for (unsigned int j = 2; j < 1000; j++) {
      for (unsigned int k = 2; k < j; k++) {
        int temp = j % k;
      }
    }
  }
}

void *learn_csp() {
  while (1) {
    printf("Learn CSP!\n");
    kill_time(10000);
    pok_thread_sleep(10000);
  }
}

void *learn_rtss() {
  while (1) {
    printf("Learn RTSS!\n");
    kill_time(10000);
    pok_thread_sleep(10000);
  }
}

void *input_job() {
  uint32_t tid;
  int ret;
  pok_thread_attr_t tattr;
  for (int i = 0; i < 2; i++) {
    printf("Input a number to add a job:\n");
    printf("    Input 0 to add nothing.\n");
    printf("    Input 1 to plan to learn csp.\n");
    printf("    Input 2 to plan to learn rtss.\n ");
    char c = getc();
    switch (c) {
    case '0': {
      printf("Nothing to do.\n");
      break;
    }
    case '1': {
      tattr.priority = 60;
      tattr.entry = learn_csp;
      tattr.period = 5000000;
      tattr.deadline = 5000000;
      tattr.time_capacity = 20000;
      tattr.weight = 1;
      ret = pok_thread_create(&tid, &tattr);
      printf("[INPUT] thread create returns=%d\n", ret);
      printf("csp planed.\n");
      break;
    }
    case '2': {
      tattr.priority = 20;
      tattr.entry = learn_rtss;
      tattr.period = 5000000;
      tattr.deadline = 4000000;
      tattr.time_capacity = 30000;
      tattr.weight = 2;
      ret = pok_thread_create(&tid, &tattr);
      printf("[INPUT] thread create returns=%d\n", ret);
      printf("rtss planed.\n");
      break;
    }
    default: {
      printf("We don't know what to do.\n");
    }
    }
    kill_time(100000);
    pok_thread_sleep(10000);
  }
}

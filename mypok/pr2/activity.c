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
char getc() {
  int ret;
  while (1) {
    ret = getChar();
    if (ret != -1) {
      return (char)ret;
    }
  }
}

void *pinger_job() {
  while (1) {
    printf("P2T1: begin of task\n");
    pok_thread_sleep(2000000);
  }
}

void *input_job() {
  uint32_t tid;
  int ret;
  pok_thread_attr_t tattr;
  while (1) {
    printf("input a number\n");
    char c = getc();
    printf("The c is %i\n", c);
    tattr.priority = 42;
    tattr.entry = pinger_job;
    tattr.processor_affinity = 0;

    ret = pok_thread_create(&tid, &tattr);
    printf("[P2] thread create returns=%d\n", ret);
  }
}
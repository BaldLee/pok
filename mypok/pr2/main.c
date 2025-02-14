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

#include "activity.h"
#include <core/partition.h>
#include <core/thread.h>
#include <libc/stdio.h>
#include <types.h>

int main() {
  uint32_t tid;
  int ret;
  pok_thread_attr_t tattr;

  tattr.priority = 0;
  tattr.entry = input_job;
  tattr.time_capacity = 10000;
  tattr.period = 100000;
  tattr.deadline = 100000;

  ret = pok_thread_create(&tid, &tattr);
  printf("[P2] input thread create returns=%d\n", ret);

  tattr.priority = 60;
  tattr.entry = learn_csp;
  tattr.period = 5000000;
  tattr.deadline = 5000000;
  tattr.time_capacity = 20000;
  ret = pok_thread_create(&tid, &tattr);
  printf("[P2] thread create returns=%d\n", ret);
  printf("csp planed.\n");

  tattr.priority = 20;
  tattr.entry = learn_rtss;
  tattr.period = 5000000;
  tattr.deadline = 4000000;
  tattr.time_capacity = 30000;
  ret = pok_thread_create(&tid, &tattr);
  printf("[P2] thread create returns=%d\n", ret);
  printf("rtss planed.\n");

  pok_partition_set_mode(POK_PARTITION_MODE_NORMAL);
  pok_thread_wait_infinite();

  return (1);
}

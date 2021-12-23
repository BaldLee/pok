// This file has been automatically generated by gen_deployment.
// Do not make manual modifications there or they will be lost.

#ifndef __POK_KERNEL_GENERATED_DEPLOYMENT_H_
#define __POK_KERNEL_GENERATED_DEPLOYMENT_H_

#include <core/schedvalues.h>

#define POK_CONFIG_NB_LOCKOBJECTS 1
#define POK_CONFIG_NB_PARTITIONS 2
#define POK_CONFIG_NB_PROCESSORS 1
#define POK_CONFIG_NB_THREADS 7
#define POK_CONFIG_PARTITIONS_NLOCKOBJECTS                                     \
  { 1, 0 }
#define POK_CONFIG_PARTITIONS_NTHREADS                                         \
  { 3, 2 }
#define POK_CONFIG_PARTITIONS_SCHEDULER                                        \
  { POK_SCHED_PRIORITY, POK_SCHED_RR, POK_SCHED_EDF, POK_SCHED_WRR }
#define POK_CONFIG_PARTITIONS_SIZE                                             \
  { 133120, 133120 }
#define POK_CONFIG_PROCESSOR_AFFINITY                                          \
  { 1, 1 }
#define POK_CONFIG_PROGRAM_NAME                                                \
  { "pr1/pr1.elf", "pr2/pr2.elf" }
#define POK_CONFIG_SCHEDULING_MAJOR_FRAME 53000000000
#define POK_CONFIG_SCHEDULING_NBSLOTS 4
#define POK_CONFIG_SCHEDULING_SLOTS                                            \
  { 2000000000, 40000000000, 1000000000, 10000000000 }
#define POK_CONFIG_SCHEDULING_SLOTS_ALLOCATION                                 \
  { 0, 1, 0, 1 }

#define POK_NEEDS_CONSOLE 1
#define POK_NEEDS_DEBUG 1
#define POK_NEEDS_LOCKOBJECTS 1
#define POK_NEEDS_SCHED_PRIORITY 1
// #define POK_NEEDS_SCHED_RR 1
// #define POK_NEEDS_SCHED_EDF 1
// #define POK_NEEDS_SCHED_WRR 1
#define POK_NEEDS_THREAD_SLEEP 1
#define POK_NEEDS_THREAD_SUSPEND 1
#define POK_NEEDS_TIME 1

typedef enum {
  pok_part_identifier_pr1 = 0,
  pok_part_identifier_pr2 = 1
} pok_part_identifiers_t;

typedef enum { pok_part_id_pr1 = 0, pok_part_id_pr2 = 1 } pok_part_id_t;

typedef enum { pok_nodes_node1 = 0 } pok_node_id_t;

#endif // __POK_KERNEL_GENERATED_DEPLOYMENT_H_

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
 *                                      Copyright (c) 2007-2020 POK team
 */

/**
 * \file libpok/include/core/shutdown.c
 * \brief This file implements a shutdown function.
 * \author Romain Guilloteau
 */

#ifdef POK_NEEDS_SHUTDOWN

#include <core/shutdown.h>
#include <core/syscall.h>

void pok_shutdown() { pok_syscall1(POK_SYSCALL_SHUTDOWN, 0); }

#endif
/* Copyright (c) 2017, 2018, 2019 Dennis Wölfing
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

/* kernel/include/cobalt/ucontext.h
 * User context.
 */

#ifndef _COBALT_UCONTEXT_H
#define _COBALT_UCONTEXT_H

#include <cobalt/registers.h>
#include <cobalt/sigset.h>

typedef struct {
    void* ss_sp;
    __SIZE_TYPE__ ss_size;
    int ss_flags;
} stack_t;

#define SS_DISABLE (1 << 0)

typedef struct {
    __registers_t __regs;
    __fpu_t __fpuEnv;
} mcontext_t;

typedef struct ucontext_t {
    struct ucontext_t* uc_link;
    sigset_t uc_sigmask;
    stack_t uc_stack;
    mcontext_t uc_mcontext;
} ucontext_t;

#endif

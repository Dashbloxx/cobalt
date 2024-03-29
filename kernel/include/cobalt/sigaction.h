/* Copyright (c) 2017, 2020, 2021 Dennis Wölfing
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

/* kernel/include/cobalt/sigaction.h
 * sigaction structure.
 */

#ifndef _COBALT_SIGACTION_H
#define _COBALT_SIGACTION_H

#include <cobalt/siginfo.h>
#include <cobalt/sigset.h>

struct sigaction {
    sigset_t sa_mask;
    int sa_flags;
    union {
        void (*sa_handler)(int);
        void (*sa_sigaction)(int, siginfo_t*, void*);
    };
};

#define SA_SIGINFO (1 << 0)
#define SA_RESETHAND (1 << 1)
#define SA_NODEFER (1 << 2)

#define SIG_BLOCK 0
#define SIG_UNBLOCK 1
#define SIG_SETMASK 2

#endif

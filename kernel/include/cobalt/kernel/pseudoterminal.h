/* Copyright (c) 2021 Dennis Wölfing
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

/* kernel/include/cobalt/kernel/pseudoterminal.h
 * Pseudo terminals.
 */

#ifndef KERNEL_PSEUDOTERMINAL_H
#define KERNEL_PSEUDOTERMINAL_H

#include <cobalt/kernel/terminal.h>

class DevPtmx : public Vnode {
public:
    DevPtmx();
    Reference<Vnode> resolve() override;
};

class DevPts : public Vnode {
public:
    DevPts();
    Reference<Vnode> getChildNode(const char* name) override;
    Reference<Vnode> getChildNode(const char* path, size_t length) override;
    size_t getDirectoryEntries(void** buffer, int flags) override;
    Reference<Vnode> open(const char* name, int flags, mode_t mode) override;
};

#endif

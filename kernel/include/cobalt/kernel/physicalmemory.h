/* Copyright (c) 2016, 2019, 2021 Dennis Wölfing
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

/* kernel/include/cobalt/kernel/physicalmemory.h
 * Physical memory management.
 */

#ifndef KERNEL_PHYSICALMEMORY_H
#define KERNEL_PHYSICALMEMORY_H

#include <cobalt/kernel/multiboot2.h>

namespace PhysicalMemory {
void initialize(const multiboot_info* multiboot);
paddr_t popPageFrame();
paddr_t popPageFrame32();
paddr_t popReserved();
void pushPageFrame(paddr_t physicalAddress);
bool reserveFrames(size_t frames);
void unreserveFrames(size_t frames);
}

#endif

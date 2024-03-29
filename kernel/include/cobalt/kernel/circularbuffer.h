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

/* kernel/include/cobalt/kernel/circularbuffer.h
 * Circular Buffer.
 */

#ifndef KERNEL_CIRCULARBUFFER_H
#define KERNEL_CIRCULARBUFFER_H

#include <cobalt/kernel/kernel.h>

class CircularBuffer {
public:
    CircularBuffer();
    CircularBuffer(char* buffer, size_t size);
    void initialize(char* buffer, size_t size);
    size_t bytesAvailable();
    size_t spaceAvailable();
    size_t read(void* buf, size_t size);
    size_t write(const void* buf, size_t size);
private:
    char* buffer;
    size_t bufferSize;
    size_t readPosition;
    size_t bytesStored;
};

#endif

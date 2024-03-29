/* Copyright (c) 2018, 2019, 2020, 2021, 2022 Dennis Wölfing
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

/* kernel/include/cobalt/thread.h
 * Thread class.
 */

#ifndef KERNEL_THREAD_H
#define KERNEL_THREAD_H

#include <signal.h>
#include <cobalt/kernel/clock.h>
#include <cobalt/kernel/interrupts.h>
#include <cobalt/kernel/kernel.h>
#include <cobalt/kernel/kthread.h>

class Process;

struct PendingSignal {
    siginfo_t siginfo;
    PendingSignal* next;
};

class Thread {
public:
    Thread(Process* process);
    ~Thread();
    InterruptContext* handleSignal(InterruptContext* context);
    void raiseSignal(siginfo_t siginfo);
    int sigtimedwait(const sigset_t* set, siginfo_t* info,
            const struct timespec* timeout);
    NORETURN void terminate(bool alsoTerminateProcess);
    void updateContext(vaddr_t newKernelStack, InterruptContext* newContext,
            const __fpu_t* newFpuEnv);
    void updatePendingSignals();
private:
    void checkSigalarm(bool scheduling);
    void raiseSignalUnlocked(siginfo_t siginfo);
public:
    Clock cpuClock;
    bool forceKill;
    __fpu_t fpuEnv;
    Process* process;
    sigset_t returnSignalMask;
    sigset_t signalMask;
    pid_t tid;
    uintptr_t tlsBase;
private:
    bool contextChanged;
    int errorNumber;
    InterruptContext* interruptContext;
    vaddr_t kernelStack;
    Thread* next;
    PendingSignal* pendingSignals;
    Thread* prev;
    kthread_mutex_t signalMutex;
    kthread_cond_t signalCond;
public:
    static void addThread(Thread* thread);
    static Thread* current() { return _current; }
    static Thread* idleThread;
    static void initializeIdleThread();
    static void removeThread(Thread* thread);
    static InterruptContext* schedule(InterruptContext* context);
private:
    static Thread* _current;
};

void setKernelStack(uintptr_t stack);
extern "C" {
extern __fpu_t initFpu;
}

#endif

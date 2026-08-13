# xv6-riscv with Priority-Based Scheduler

This repository is an enhanced version of **xv6-riscv** (MIT's teaching operating system) featuring a custom **Priority-Based Process Scheduler**, new system calls, and user-space tools.

---

## Key Features & Improvements

### 1. Priority-Based Scheduling
* **Preemption & Selection:** The process scheduler selects the runnable process with the highest priority (lower numerical value = higher precedence).
* **Round-Robin Fallback:** Processes sharing the same priority level are scheduled using a Round-Robin approach.
* **Compile-Time Selection:** Supports switching between the default scheduler and the priority-based scheduler via Makefile flags:
  ```bash
  make qemu SCHEDULER=PRIORITY
  ```

### 2. New System Calls
* **getinfo (Syscall #23):** Populates a `pinfo` structure containing details (PID, state, priority, tickets) for active processes.
* **setpriority (Syscall #24):** Dynamically alters the priority of a target process at runtime.

### 3. User-Space Utilities
* **ps:** Displays process information including PID, state, priority, and assigned tickets.
* **chpri:** Command-line tool to modify a process's priority (`chpri <pid> <priority>`).
* **test_sched:** Test utility verifying process execution order under priority scheduling.

---

## Building and Running

### Prerequisites
Requires the RISC-V toolchain (`riscv64-unknown-elf-` or `riscv64-linux-gnu-`) and QEMU configured for `riscv64-softmmu`.

### Commands
* **Run with Priority Scheduler:**
  ```bash
  make qemu SCHEDULER=PRIORITY
  ```

* **Run with Default Scheduler:**
  ```bash
  make qemu SCHEDULER=DEFAULT
  ```

---

## Original xv6 Overview

xv6 is a re-implementation of Dennis Ritchie's and Ken Thompson's Unix Version 6 (v6). xv6 loosely follows the structure and style of v6, but is implemented for a modern RISC-V multiprocessor using ANSI C.

### Acknowledgments
xv6 is inspired by John Lions's *Commentary on UNIX 6th Edition* (Peer to Peer Communications; ISBN: 1-57398-013-7; 1st edition (June 14, 2000)). See also MIT's course site: https://pdos.csail.mit.edu/6.1810/

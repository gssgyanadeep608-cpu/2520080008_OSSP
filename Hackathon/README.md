# Disk Scheduling Algorithm Simulator

## Project Overview
This project is a C-based operating systems simulation that implements and compares core disk scheduling algorithms—**First-Come, First-Served (FCFS)** and **Shortest Seek Time First (SSTF)**[cite: 1, 19]. The program calculates total disk arm movement (seek time) and visualizes the head traversal sequence for a given set of I/O requests.

---

## Algorithms Implemented
1. **FCFS (First-Come, First-Served):** Services I/O requests in the exact order they arrive in the queue[cite: 1, 19]. Simple and fair, but can result in high total head movement[cite: 1, 19].
2. **SSTF (Shortest Seek Time First):** Services the unvisited request closest to the current disk head position first, minimizing immediate seek time[cite: 1, 19].

---

## Compilation & Execution Instructions

### Prerequisites
- GCC Compiler
- Linux/Ubuntu terminal (or any POSIX-compliant environment)

### 1. Compile the Source Code
Open your terminal in the project directory and run the following `gcc` command (including the math library flag `-lm`):
```bash
gcc disc_scheduling.c -o disk_scheduler -lm

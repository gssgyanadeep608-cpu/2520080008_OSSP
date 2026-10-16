# Disk Scheduling Algorithm Simulator

## 📋 Table of Contents
1. [Project Overview](#project-overview)
2. [Operating Systems Concepts & Relevance](#operating-systems-concepts--relevance)
3. [Algorithms Implemented](#algorithms-implemented)
    - [First-Come, First-Served (FCFS)](#1-first-come-first-served-fcfs)
    - [Shortest Seek Time First (SSTF)](#2-shortest-seek-time-first-sstf)
4. [System Architecture & Code Structure](#system-architecture--code-structure)
5. [Prerequisites & Environment Setup](#prerequisites--environment-setup)
6. [Compilation & Execution Instructions](#compilation--execution-instructions)
7. [Sample Test Case & Output Walkthrough](#sample-test-case--output-walkthrough)
8. [Performance Analysis & Comparison](#performance-analysis--comparison)
9. [Team Contributions](#team-contributions)

---

## 🚀 Project Overview
The **Disk Scheduling Algorithm Simulator** is a low-level systems programming project written in C. Designed as part of the Operating Systems and Systems Programming curriculum, this tool simulates how modern operating systems manage and optimize input/output (I/O) request queues destined for secondary storage devices (hard disk drives). 

Because physical disk arm movement (seek time) represents the single greatest performance bottleneck in mechanical storage subsystems, evaluating scheduling algorithms is vital for minimizing average waiting times, reducing mechanical wear, and maximizing system-wide I/O throughput.

---

## 🧠 Operating Systems Concepts & Relevance
In modern computing architectures, multiple user processes and kernel threads constantly issue read and write requests to disk storage. Since the disk head can only service one request at a time, incoming requests are placed into an I/O wait queue. 
- **Seek Time:** The time taken for the disk arm to move to the specific cylinder containing the requested sector.
- **Rotational Latency:** The time waiting for the target sector to rotate beneath the read/write head.
- **Disk Bandwidth:** Total number of bytes transferred divided by the total time taken from the first request to the final service completion.

This project focuses specifically on minimizing **Seek Time** through intelligent request reordering heuristics.

---

## ⚙️ Algorithms Implemented

### 1. First-Come, First-Served (FCFS)
- **Mechanism:** Requests are serviced strictly in the chronological order of their arrival in the queue, regardless of where the disk head is currently positioned.
- **Advantages:** Completely fair to all processes; guarantees no request starvation; simple and straightforward to implement.
- **Disadvantages:** Highly unoptimized for seek performance; often results in excessive head movement ("convoy effect") when requests are scattered across wide cylinder tracks.

### 2. Shortest Seek Time First (SSTF)
- **Mechanism:** Inspects the pending request queue and selects the unvisited request that requires the minimum head movement distance from the current head position (calculating absolute differences).
- **Advantages:** Substantially lowers average response time and total head movement compared to FCFS.
- **Disadvantages:** Susceptible to **request starvation** (or indefinite postponement) if continuous new requests arrive near the active head position while outer tracks are neglected.

---

## 🏗️ System Architecture & Code Structure
The application is structured using modular C functions to ensure clean separation of concerns:
- `main()`: Handles user interface input, validation of request sizes, dynamic data capture, and orchestrates algorithm execution.
- `calculate_fcfs()`: Computes absolute traversal distance, tracks current head movement state, and prints the sequential path.
- `calculate_sstf()`: Tracks visited states across requests, dynamically evaluates minimum Euclidean/absolute distances, and determines optimal local choices iteratively.

---

## 💻 Prerequisites & Environment Setup
To build and execute this project, ensure your environment meets the following requirements:
- **Operating System:** Linux / Ubuntu (POSIX-compliant environment)
- **Compiler:** `gcc` (GNU Compiler Collection supporting C99 standard or higher)
- **Build Tools:** Standard terminal utilities (`make`, shell commands)

---

## 🛠️ Compilation & Execution Instructions

### Step 1: Open Terminal
Navigate to the directory where your source code (`disc_scheduling.c`) is saved:
```bash
cd ~/Disc_Scheduling

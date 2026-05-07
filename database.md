# VelocityDB / HashDB — Complete Learning & Building Roadmap

> **Goal:** Take you from *"I know C++ basics"* → *"I built a real database/storage engine"*

### Core Philosophy

```
Learn Concept → Build Small Component → Integrate Into Database
```

Do **not** try to build everything at once. Each stage compounds on the previous one.

---

## Stage 0 — Prerequisites

### What to Learn

**C++ Fundamentals** — you must be comfortable with:

- Classes, pointers, references
- RAII and smart pointers
- STL and templates

**Memory**
- Stack vs heap, `new`/`delete`, memory leaks

**OOP**
- Encapsulation, inheritance, polymorphism

**STL**
- `vector`, `unordered_map`, `queue`, `string`

### What to Build

**Project 1 — Mini STL Clone**

Build a dynamic array, stack, and queue from scratch.  
Purpose: understand manual memory management before relying on abstractions.

---

## Stage 1 — Data Structures

### What to Learn

**Hash Tables** — the most important topic in this entire roadmap.

- Hashing, collisions, chaining, open addressing
- Load factor and rehashing
- Time complexity: O(1) average vs O(log n) for trees

### What to Build

**Project 2 — Custom HashMap**

Implement `put()`, `get()`, `remove()` — no STL hashmap allowed.  
Use raw arrays and linked lists. Then improve with:

- Linear probing
- Robin Hood hashing

---

## Stage 2 — File Handling

### What to Learn

**Binary File I/O**
- `fstream`, `seekg`, `seekp`, binary reading/writing

**File Layouts**
- Offsets, headers, records, metadata

### What to Build

**Project 3 — Persistent Key-Value Store**

Store `key → value` inside a binary file.  
Features: insert, read, delete. No networking yet.

---

## Stage 3 — Database Internals

### What to Learn

**Storage Engines** — study the design of:
- B+ Trees
- LSM Trees
- Hash Indexing

**Why Databases Use Trees**
- Range scans, ordered iteration, disk page layout

**Collision Handling**
- Chaining vs Robin Hood hashing

**Tombstones / Bubble Space**
- Deleted records must be reusable — understand why

### What to Build

**Project 4 — HashDB v1**

Build a real storage engine with three files:

| File | Purpose |
|------|---------|
| `INDEX` | Hash index mapping keys to offsets |
| `DATA` | Raw key-value records |
| `META` | Engine metadata (count, version, etc.) |

---

## Stage 4 — Networking

### What to Learn

**TCP/IP Sockets**
- `socket()`, `bind()`, `listen()`, `accept()`, `send()`, `recv()`

### What to Build

**Project 5 — TCP Chat Server**

A multi-client server before touching database networking.  
Focus on connection handling and message framing.

---

## Stage 5 — Concurrent Programming

### What to Learn

**Threads**
- `std::thread`, `mutex`, `shared_mutex`, `atomics`, `condition_variable`

**Race Conditions** — critical to understand before writing any concurrent code.

### What to Build

**Project 6 — Multithreaded Server**

Convert the chat server into a thread pool architecture.  
Each worker thread handles a queue of client requests.

---

## Stage 6 — VelocityDB v1

### What to Build

Combine HashDB + networking + concurrency into a unified engine.

**Architecture:**

```
Client
  ↓
TCP Server
  ↓
Hash Engine
  ↓
Disk Storage
```

**Commands to implement:** `SET`, `GET`, `DEL`, `SIZE`

### What to Learn

**Serialization** — convert C++ structs/classes into bytes for wire transfer and disk storage.

---

## Stage 7 — Linux System Programming

### What to Learn

**`epoll`** — replaces the one-thread-per-client model with event-driven I/O.  
Scales to thousands of connections without proportional thread cost.

**Non-blocking I/O** — understand `O_NONBLOCK` and `EAGAIN`.

### What to Build

**Project 7 — epoll HTTP Server**

Build a minimal HTTP server using epoll before integrating into the database.

---

## Stage 8 — Performance Engineering

### What to Learn

**CPU Cache**
- Cache lines (64 bytes), spatial/temporal locality, false sharing

**Profiling Tools**
- `perf`, Valgrind/Cachegrind, Flame graphs

### What to Build

**Benchmark Suite**

Measure ops/sec, p99 latency, memory usage.  
Compare against Redis and LMDB on identical hardware.

---

## Stage 9 — Advanced Hashing

### What to Learn

| Algorithm | Key Property |
|-----------|-------------|
| Robin Hood | Minimises variance in probe length |
| Cuckoo Hashing | Worst-case O(1) lookup |
| Hopscotch Hashing | Cache-friendly neighbourhood |

### What to Build

Replace your basic hash table with one of the above.  
This becomes the core of your custom storage engine.

---

## Stage 10 — Memory Management

### What to Learn

**Allocators**
- Slab allocation, arenas, memory pools

### What to Build

**Custom Allocator** — replace `new`/`delete` inside the database with a slab allocator.  
Reduces fragmentation and allocation overhead significantly.

---

## Stage 11 — mmap Databases

### What to Learn

**`mmap()`** — used in LMDB and most modern embedded databases.  
Maps a file directly into virtual address space; the OS handles paging.

### What to Build

**Memory-Mapped Storage**

Replace explicit `read()`/`write()` syscalls with memory-mapped file access.  
Observe latency and throughput differences.

---

## Stage 12 — Sharded Architecture

### What to Learn

**Horizontal Scaling**

```cpp
shard_id = hash(key) % shard_count;
```

### What to Build

**Multi-Shard Engine**

Each shard owns its own hashmap, lock, and thread.  
No cross-shard coordination needed for exact-key lookups.

---

## Stage 13 — Lock-Free Programming

### What to Learn

> ⚠️ Very advanced — do not attempt before Stage 12.

- Compare-And-Swap (CAS)
- Memory ordering (`std::memory_order_*`)
- ABA problem

### What to Build

1. Lock-free queue
2. Lock-free hashmap segment

---

## Stage 14 — Redis Compatibility

### What to Learn

**RESP Protocol** — Redis Serialization Protocol (wire format).  
Simple text-based protocol, well documented.

### What to Build

**Redis-Compatible Server**

Once done, `redis-cli` connects to your engine out of the box.  
This is one of the most impressive demo-able milestones.

---

## Stage 15 — Distributed Systems

### What to Learn

| Topic | Why |
|-------|-----|
| Raft consensus | Practical, implementable agreement protocol |
| Paxos | Theoretical foundation |
| CAP Theorem | Understand consistency vs availability trade-offs |

### What to Build

**Replication**
- Leader/follower architecture
- WAL shipping to replicas

---

## Stage 16 — Research-Level Features

> Optional. Only pursue after Stages 0–15 are solid.

| Feature | Technology |
|---------|-----------|
| Compression | LZ4, Snappy |
| SIMD acceleration | AVX2, SSE |
| Async I/O | `io_uring` (modern Linux) |
| NUMA optimization | `libnuma` |
| GPU acceleration | CUDA / OpenCL |

---

## Timeline

### First 3 Months — Foundations

Learn: C++, hashing, binary file I/O, TCP sockets  
Build: Custom hashmap, persistent KV store, TCP server

### Next 3 Months — Integration

Build: HashDB v1, thread pool server, benchmark suite

### Next 6 Months — Production Quality

Add: epoll, mmap, sharding, custom allocators, Redis protocol

---

## Recommended Resources

| Category | Resource |
|----------|----------|
| C++ | [LearnCpp.com](https://www.learncpp.com) |
| C++ | *Effective Modern C++* — Scott Meyers |
| Systems | *Computer Systems: A Programmer's Perspective* — Bryant & O'Hallaron |
| Databases | *Database Internals* — Alex Petrov ⭐ |
| Networking | [Beej's Guide to Network Programming](https://beej.us/guide/bgnet/) |
| Linux | *The Linux Programming Interface* — Michael Kerrisk |

---

## What Makes This Project Impressive

It is **not** the number of features.

It is:

- **Architecture quality** — clean separation of storage, networking, and concurrency layers
- **Benchmark quality** — real numbers, fair comparisons, honest methodology
- **Systems understanding** — ability to explain every design decision and its trade-offs

### Realistic Final Goal

> "A specialized high-performance hash-based storage engine optimized for exact-key retrieval and concurrent workloads."

That is realistic, professional, and genuinely impressive — far more so than claiming to be a "Redis killer."
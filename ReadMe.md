**Parallel calculation**
--
Implementation parallel calc for primitive arithmetic types.
Parallel work based on simple thread pool worker.
Worker for work with any accepted signature functional object .

**How to build?**
--
1. Clone repo to any dir on your computer
2. Move to project root
3. 
```bash
   cmake -S . -B build
   cmake --build build
```

**How to run?**
--
1. Carry out _How to build_
2. 
```bash
   cd build
   ./ParallelCalc
```
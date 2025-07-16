# Pipex - UNIX Pipeline Implementation

## Project Overview
**Objective:** Replicate UNIX pipe (`|`) functionality in C, handling command execution with file redirection.  
**Key Achievement:** Achieved 100% behavioral parity with native shell pipes while implementing robust error handling.

---

## Prerequisites
- GCC or Clang compiler
- Linux or macOS (tested environments)
- [Valgrind](https://valgrind.org/) (for leak checking)
- Make

---

## Features
### Core Functionality
- **UNIX Pipe Emulation**:  
  ```bash
  ./pipex file1 "cmd1" "cmd2" file2  # Behaves like: < file1 cmd1 | cmd2 > file2
  ```
- **Process Management**:
  - Forking child processes
  - Pipe communication between commands
  - Proper file descriptor redirection

### Error Handling
- 15+ error cases detected:
  ```c
  if (access(argv[1], F_OK) == -1) {
      print_error("Error ", argv[1], ": No such file\n");
      exit(EXIT_FAILURE);
  }
  ```
- Memory leak-free (Valgrind-verified)

### Technical Implementation
| Component          | Key System Calls        |
|--------------------|------------------------|
| Process Creation   | `fork()`, `waitpid()`  |
| Pipe Communication | `pipe()`, `dup2()`     |
| Command Execution  | `execve()`             |
| File Operations    | `open()`, `close()`    |

---

## Installation & Usage

### Build
```bash
git clone https://github.com/TuqaSa/pipex.git
cd pipex && make
```

### Execution
```bash
# Basic usage
./pipex infile "ls -l" "wc -l" outfile

# Equivalent to shell:
# < infile ls -l | wc -l > outfile
```
- Surround commands containing spaces or special characters with double quotes, e.g. `"grep 'hello world'"`.

### Testing
```bash
# Check memory leaks
valgrind --leak-check=full ./pipex infile "grep a" "wc -c" outfile
```

### More Examples
```bash
./pipex input.txt "cat" "grep foo" output.txt
./pipex data.csv "awk '{print $2}'" "sort" sorted.txt
```

---

## Code Structure
```
pipex/
├── Makefile           # Build system
├── includes/          # Header files
│   └── pipex.h
├── src/               # Core logic
│   ├── command.c      # Command parsing/execution
│   ├── pipe.c         # Pipe management
│   ├── parsing.c      # Argument processing
│   └── utils.c        # Helper functions
└── libft/             # Custom library
```

Key Functions:
- `init_pipe()`: Creates pipe and initializes commands
- `execute_cmd()`: Handles redirection and `execve`
- `cleanup_cmd()`: Ensures proper resource freeing

---

## Technical Highlights

### Process Flow
1. **Setup**:
   ```mermaid
   graph LR
   A[Parent Process] --> B[Create Pipe]
   B --> C[Fork Child 1]
   B --> D[Fork Child 2]
   ```

2. **Execution**:
   - Child 1: Redirects `stdin` from infile, `stdout` to pipe
   - Child 2: Redirects `stdin` from pipe, `stdout` to outfile

### Error Cases Handled
| Error Type              | Solution                          |
|-------------------------|-----------------------------------|
| Missing input file      | Immediate exit with clear error   |
| Invalid command         | Skip execution, clean resources   |
| Permission issues       | Proper error messaging            |
| Pipe creation failure   | Graceful termination              |

---

## Skills Demonstrated
- **UNIX Systems Programming:** Mastery of process control and IPC
- **Resource Management:** Proper file descriptor and memory handling
- **Robust Error Handling:** 15+ edge cases covered
- **Makefile Expertise:** Standardized build process

---

## Example

**Input:**
```bash
./pipex infile "grep success" "wc -w" outfile
```

**Behavior:**
1. Reads `infile`
2. Filters lines containing "success"
3. Counts words in filtered output
4. Writes result to `outfile`

---

## Contributing

Bug reports, feature requests, and pull requests are welcome!  
To contribute:
1. Fork the repository.
2. Create your feature branch: `git checkout -b feature/fooBar`
3. Commit your changes: `git commit -am 'Add some fooBar'`
4. Push to the branch: `git push origin feature/fooBar`
5. Open a pull request.

---

## FAQ

**Q:** Why do I get "command not found"?  
**A:** Make sure the command exists in your system's PATH.

**Q:** Valgrind reports leaks?  
**A:** Please open an issue with your command and output.

**Q:** What if I get "permission denied"?  
**A:** Check file permissions on input/output files.

---

## License

This repository is part of the 42 curriculum and intended for educational use.  
Reuse or distribution outside of 42's policy is discouraged unless properly credited.

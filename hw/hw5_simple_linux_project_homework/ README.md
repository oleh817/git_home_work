# hw_5_simple_linux_project

This project demonstrates the use of Automake and Autoconf for building a C program.

## Prerequisites

- Make
- GCC (or any compatible C compiler)
- Autotools (Autoconf, Automake)

## Installation

1. Clone the repository or download the project files.

2. Run the following commands:

    ```bash
    autoreconf --install   # Generate the configure script
    ./configure            # Configure the project
    make                   # Compile the project
    sudo make install      # Install the program
    ```

3. After installation, the binary will be placed in `/usr/local/bin/` and the header file in `/usr/local/include/`.

## Cleaning Up

To clean the project, run:

```bash
make clean-all

### 7. **INSTALL**: Detailed Installation Instructions
```markdown
# INSTALL

To install this program, follow these steps:

1. Ensure you have the required dependencies:
   - `make`
   - `gcc` (or another C compiler)
   - `autotools` (e.g., `autoconf`, `automake`, `libtool`)

2. Run the following commands:

    ```bash
    autoreconf --install   # Generate the configure script
    ./configure            # Configure the project
    make                   # Build the project
    sudo make install      # Install the program
    ```

3. The program will be installed to:
   - Binary: `/usr/local/bin/my_program`
   - Header: `/usr/local/include/header.h`

## Uninstall

To uninstall the program, simply remove the installed files manually or use the `make clean-all` command to clean everything.

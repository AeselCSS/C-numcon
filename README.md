# Number converter

## Compilation Instructions

To compile the project, use the following command:

```sh
gcc -Wall -I./include -I./src/ui -o ./build/numconv1 ./src/*.c ./src/ui/*.c
```

## Running the Program

On unix-based systems, run the compiled program by using the following command:

```sh
./build/numconv1
```

On Windows-based systems, run the compiled program by using the following command:

```sh
./build/numconv1.exe
```

## Tests
To compile and run just the tests and thereby bypassing the usage of the UI please use the following commands:

```sh
gcc -Wall -I./include -o ./build/test_numconv1 ./src/*.c
```
Unix based systems:
```sh
./test_numconv1
```

Windows-based systems:
```sh
./test_numconv1.exe
```

### Development Environment
- **Machine**: Intel-based MacBook Pro
- **Operating System**: macOS Sonoma (14.6.1)
- **Compiler**: gcc-14 (Homebrew GCC 14.2.0)
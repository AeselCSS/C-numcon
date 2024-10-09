# Number converter

## Compilation Instructions

To compile the project, use the following command:

**Version 1**
```sh
gcc -Wall -I./include -I./src/ui -o ./build/numconv1 ./src/numconv1.c ./src/ui/numcon_ui.c
```

**Version 2**
```sh
gcc -Wall -I./include -I./src/ui -o ./build/numconv2 ./src/numconv2.c ./src/ui/numcon_ui.c
```

## Running the Program

On unix-based systems, run the compiled program by using the following command:


**Version 1**
```sh
./build/numconv1
```

**Version 2**
```sh
./build/numconv2
```

On Windows-based systems, run the compiled program by using the following command:

**Version 1**
```sh
./build/numconv1.exe
```

**Version 2**
```sh
./build/numconv2.exe
```

## Tests
To compile and run just the tests and thereby bypassing the usage of the UI please use the following commands:

**Version 1**
```sh
gcc -Wall -I./include -o ./build/test_numconv1 ./src/numconv1.c ./src/test_numcon.c
```
Unix based systems:
```sh
./build/test_numconv1
```

Windows-based systems:
```sh
./build/test_numconv1.exe
```

**Version 2**
```sh
gcc -Wall -I./include -o ./build/test_numconv2 ./src/numconv2.c ./src/test_numcon.c
```
Unix based systems:
```sh
./build/test_numconv2
```

Windows-based systems:
```sh
./build/test_numconv2.exe
```

### Development Environment
- **Machine**: Intel-based MacBook Pro
- **Operating System**: macOS Sequoia (15.0.1)
- **Compiler**: gcc-14 (Homebrew GCC 14.2.0)
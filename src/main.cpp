#include "main.hpp"

volatile unsigned int* const UART0DR = (unsigned int*) 0x101f1000;

void print_uart0(const char* str) {
    while (*str != 0) {
        *UART0DR = (unsigned int)*str;
        ++str;
    }
}

extern "C" void Main() {
    print_uart0("Hello from C++!\n");
}

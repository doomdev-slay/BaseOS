#include <stdint.h>

// Funkce pro tisk řetězce na obrazovku pomocí volání BIOS
void print(const char *str) {
    while (*str) {
        asm volatile (
            "movb $0x0E, %%ah;"   // BIOS služba pro výpis znaku (INT 10h, AH=0x0E)
            "movb %[char], %%al;" // Znak k výpisu
            "int $0x10;"          // Volání přerušení BIOSu
            :                     // Žádné výstupní operandy
            : [char] "r" (*str)   // Vstupní znak
            : "ah", "al"          // Změněné registry
        );
        str++; // Pokračujeme na další znak
    }
}



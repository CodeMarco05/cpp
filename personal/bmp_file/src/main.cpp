#include <iostream>
#include "../headers/bmp_editor.h"

int main() {
    const uint32_t width = 100;
    const uint32_t height = 100;

    BMPGenerator::generate("output2.bmp", width, height);

    return 0;
}

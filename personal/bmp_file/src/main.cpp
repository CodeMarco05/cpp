#include <iostream>
#include <vector>
#include "../headers/bmp_editor.h"

int main() {
    //Format for BMP bgr
    const uint32_t width = 16;
    const uint32_t height = 16;

    std::vector<uint8_t> pixelData(width*height*3, 255);
    pixelData[24+8*16*3] = 0;
    pixelData[25+8*16*3] = 255;
    pixelData[26+8*16*3] = 0;
    

    BMP::Generator::generate("../output/output2.bmp", width, height, &pixelData);

    return 0; 
}

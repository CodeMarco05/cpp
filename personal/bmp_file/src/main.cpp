#include <iostream>
#include <vector>
#include "../headers/bmp.h"

int main() {
    //Format for BMP bgr
    const uint32_t width = 16;
    const uint32_t height = 16;

    std::vector<BMP::Pixel> pixelData(width*height, {0xFF, 0xFF, 0xFF});
    
    pixelData[136].green = 0;

    bool success = BMP::Generator::generate("../output/output.bmp", width, height, &pixelData);

    
    std::vector<uint8_t> data = BMP::Reader::readBytes("../output/output.bmp");

    for(uint8_t u: data){
        std::cout << std::hex << static_cast<int>(u) << '\n';
    }


    return 0; 
}

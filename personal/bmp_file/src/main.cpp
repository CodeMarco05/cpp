#include "../headers/bmp.h"
#include <iostream>
#include <vector>

int main() {
  // Format for BMP bgr
  const uint32_t width = 16;
  const uint32_t height = 16;

  std::vector<BMP::Pixel> pixelData(width * height, {0xFF, 0xFF, 0xFF});

  pixelData[136].green = 0;
  pixelData[136].blue = 0;

  bool success = BMP::Generator::generate("../output/output.bmp", width, height,
                                          &pixelData);

  BMP::BMPHeader header;
  std::vector<BMP::Pixel> dataRead;
  BMP::Reader::completeRead("../output/output.bmp", &dataRead, &header);

  return 0;
}

#pragma once

#include <fstream>
#include <iostream>
#include <vector>

namespace BMP {
// Define the BMP header structure
#pragma pack(push, 2)
struct BMPHeader {
  char fileType[2] = {'B', 'M'};
  uint32_t fileSize;
  uint32_t reserved = 0;
  uint32_t offset;           // Offset to pixel data
  uint32_t headerSize = 40;  // Size of header
  uint32_t width;
  uint32_t height;
  uint16_t planes = 1;
  uint16_t bitsPerPixel = 24;            // 24-bit color depth (RGB)
  uint32_t compression = 0;              // No compression
  uint32_t dataSize;                     // Size of pixel data
  uint32_t horizontalResolution = 2835;  // 72 DPI
  uint32_t verticalResolution = 2835;    // 72 DPI
  uint32_t colorsUsed = 0;               // Number of colors in palette
  uint32_t importantColors = 0;          // Number of important colors
};
#pragma pack(pop)

class Generator {
 public:
  static void generate(const std::string& filename, uint32_t width,
                       uint32_t height, const std::vector<uint8_t>* pixelData);
};
}  // namespace BMP
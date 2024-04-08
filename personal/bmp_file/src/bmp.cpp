#include "../headers/bmp.h"

#include <fstream>

namespace BMP {

bool Generator::generate(const std::string& filename, uint32_t width,
                         uint32_t height, const std::vector<Pixel>* pixelData) {
  // Calculate the size of the pixel data
  const uint32_t dataSize = width * height * 3;  // 3 bytes per pixel (RGB)

  // Create pixel data (RGB format)
  // std::vector<uint8_t> pixelData(dataSize, 255); // Initialize with white
  // pixels (RGB: 255, 255, 255

  // Create the BMP header
  BMPHeader header;
  header.fileSize = sizeof(BMPHeader) + dataSize;
  header.offset = sizeof(BMPHeader);
  header.width = width;
  header.height = height;
  header.dataSize = dataSize;

  // Open the output file
  std::ofstream outFile(filename, std::ios::binary);
  if (!outFile.is_open()) {
    std::cerr << "Error: Unable to open file." << '\n';
    return false;
  }

  // Write the BMP header to the file
  outFile.write(reinterpret_cast<const char*>(&header), sizeof(BMPHeader));

  // Write the pixel data to the file
  outFile.write(reinterpret_cast<const char*>(pixelData->data()), dataSize);

  // Close the output file
  outFile.close();

  return true;
}

std::vector<uint8_t> Reader::readBytes(const std::string fileName) {
  std::vector<uint8_t> data;

  std::ifstream file(fileName, std::ios::binary);

  if (!file.is_open()) {
    std::cerr << "Unanble to open file: " << fileName << '\n';
    return data;
  }

  uint8_t byte;

  while (file.read(reinterpret_cast<char*>(&byte), sizeof(byte))) {
    data.push_back(byte);
  }
  file.close();

  return data;
}

}  // namespace BMP

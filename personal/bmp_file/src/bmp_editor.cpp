#include "../headers/bmp_editor.h"


void BMPGenerator::generate(const std::string& filename, uint32_t width,
                     uint32_t height, const std::vector<uint8_t>* pixelData) {
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
    std::cerr << "Error: Unable to open file." << std::endl;
    return;
  }

  // Write the BMP header to the file
  outFile.write(reinterpret_cast<const char*>(&header), sizeof(BMPHeader));

  // Write the pixel data to the file
  outFile.write(reinterpret_cast<const char*>(pixelData->data()), dataSize);

  // Close the output file
  outFile.close();

  std::cout << "BMP file generated successfully." << std::endl;
}
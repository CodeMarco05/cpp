#pragma once

#include <vector>
#include <fstream>
#include <iostream>

// Define the BMP header structure
#pragma pack(push, 2)
struct BMPHeader {
    char fileType[2] = {'B', 'M'};
    uint32_t fileSize;
    uint32_t reserved = 0;
    uint32_t offset;  // Offset to pixel data
    uint32_t headerSize = 40;  // Size of header
    uint32_t width;
    uint32_t height;
    uint16_t planes = 1;
    uint16_t bitsPerPixel = 24;  // 24-bit color depth (RGB)
    uint32_t compression = 0;  // No compression
    uint32_t dataSize;  // Size of pixel data
    uint32_t horizontalResolution = 2835;  // 72 DPI
    uint32_t verticalResolution = 2835;    // 72 DPI
    uint32_t colorsUsed = 0;  // Number of colors in palette
    uint32_t importantColors = 0;  // Number of important colors
};
#pragma pack(pop)

class BMPGenerator {
public:
    static void generate(const std::string& filename, uint32_t width, uint32_t height) {
        // Calculate the size of the pixel data
        const uint32_t dataSize = width * height * 3; // 3 bytes per pixel (RGB)

        // Create pixel data (RGB format)
        std::vector<uint8_t> pixelData(dataSize, 255); // Initialize with white pixels (RGB: 255, 255, 255)

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
        outFile.write(reinterpret_cast<const char*>(pixelData.data()), dataSize);

        // Close the output file
        outFile.close();

        std::cout << "BMP file generated successfully." << std::endl;
    }
};
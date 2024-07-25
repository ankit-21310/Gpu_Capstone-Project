# Gpu_Capstone-Project

# Image and Signal Processing Pipeline

## Project Description

This project is a pipeline for processing image and signal data. The image processing component converts images to grayscale, while the signal processing component applies a simple moving average filter to the signal data. The project is implemented in C++ using OpenCV for image processing and standard C++ libraries for signal processing.

## Features

- Convert images to grayscale
- Apply a simple moving average filter to signals

## Requirements

- OpenCV library
- C++17 or later
- CMake (for building the project)

## Usage

1. **Set Up Directories**:
   - Place your image files (`.jpg` or `.png`) and signal files (`.csv`) in the `data` directory.
   - Ensure the `output` directory exists or will be created by the program.

2. **Build the Project**:
   ```sh
   mkdir build
   cd build
   cmake ..
   make
3. **Run the Project**:
   ./ImageSignalProcessing

4. **Processed Files**:

Processed images will be saved in the output directory with grayscale conversion.
Processed signals will be saved in the output directory with the same filename as input but with filtered values.

5. **Directory Structure**:

     project_root/
├── data/
│   ├── image1.jpg
│   ├── image2.png
│   └── signal.csv
├── output/
│   ├── image1.jpg
│   ├── image2.png
│   └── signal.csv
├── src/
│   └── main.cpp
├── CMakeLists.txt
└── README.md



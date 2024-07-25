#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <filesystem>
#include <opencv2/opencv.hpp>

// Define the data directory
const std::string data_dir = "path/to/data";
const std::string output_dir = "path/to/output";

// Function to process images
void process_image(const std::string& image_path) {
    // Load the image
    cv::Mat image = cv::imread(image_path, cv::IMREAD_COLOR);
    if (image.empty()) {
        std::cerr << "Could not open or find the image: " << image_path << std::endl;
        return;
    }

    // Perform image processing operations
    // Example: Convert to grayscale
    cv::Mat grayscale_image;
    cv::cvtColor(image, grayscale_image, cv::COLOR_BGR2GRAY);

    // Save the processed image
    std::string save_path = output_dir + "/" + std::filesystem::path(image_path).filename().string();
    cv::imwrite(save_path, grayscale_image);
    std::cout << "Processed image: " << image_path << std::endl;
}

// Helper function to apply a filter to a signal
std::vector<double> apply_filter(const std::vector<double>& signal, int window_size = 5) {
    std::vector<double> filtered_signal(signal.size(), 0.0);
    for (size_t i = 0; i < signal.size(); ++i) {
        double sum = 0.0;
        int count = 0;
        for (int j = -window_size / 2; j <= window_size / 2; ++j) {
            if (i + j >= 0 && i + j < signal.size()) {
                sum += signal[i + j];
                ++count;
            }
        }
        filtered_signal[i] = sum / count;
    }
    return filtered_signal;
}

// Function to process signals
void process_signal(const std::string& signal_path) {
    // Load the signal data
    std::ifstream file(signal_path);
    if (!file.is_open()) {
        std::cerr << "Could not open the file: " << signal_path << std::endl;
        return;
    }

    std::vector<double> signal_data;
    std::string line;
    while (std::getline(file, line)) {
        signal_data.push_back(std::stod(line));
    }
    file.close();

    // Perform signal processing operations
    // Example: Apply a filter
    std::vector<double> filtered_signal = apply_filter(signal_data);

    // Save the processed signal
    std::string save_path = output_dir + "/" + std::filesystem::path(signal_path).filename().string();
    std::ofstream outfile(save_path);
    for (const auto& value : filtered_signal) {
        outfile << value << std::endl;
    }
    outfile.close();
    std::cout << "Processed signal: " << signal_path << std::endl;
}

int main() {
    // Create the output directory if it doesn't exist
    std::filesystem::create_directories(output_dir);

    // Process images
    for (const auto& entry : std::filesystem::directory_iterator(data_dir)) {
        if (entry.path().extension() == ".jpg" || entry.path().extension() == ".png") {
            process_image(entry.path().string());
        }
    }

    // Process signals
    for (const auto& entry : std::filesystem::directory_iterator(data_dir)) {
        if (entry.path().extension() == ".csv") {
            process_signal(entry.path().string());
        }
    }

    std::cout << "Processing complete." << std::endl;
    return 0;
}

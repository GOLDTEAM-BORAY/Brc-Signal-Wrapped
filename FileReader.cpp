#include <fstream>
#include <vector>
#include <string>
#include <sstream>

// �������������ļ��ж�ȡÿ�е�double���֣�����double���飬��ͨ��int*���س���
double* ReadDoublesFromFile(const std::string& filename, int startPoint, int* outLength) {
    std::ifstream infile(filename);
    std::vector<double> numbers;
    std::string line;
    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        double value;
        if (iss >> value) {
            numbers.push_back(value);
        }
    }
    *outLength = static_cast<int>(numbers.size()) - startPoint;
    if (numbers.empty()) {
        return nullptr;
    }
    double* arr = new double[*outLength];
    for (int i = 0; i < *outLength; ++i) {
        arr[i] = numbers[i];
    }
    return arr;
}
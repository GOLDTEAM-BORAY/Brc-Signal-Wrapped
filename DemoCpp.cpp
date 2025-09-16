#include <windows.h>
#include <iostream>
#include <complex>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

#include "Types.h"
#include "BrcSignalKit.h"
#include "FileReader.h"

int main()
{
	const char* licensePath = "C:\\Users\\joyho\\OneDrive\\桌面\\LIC-20250908-19990fe9.lic";
	LoadLicense(licensePath);
	std::cout << "License loaded successfully." << std::endl;

#if 0
	const char* filePath = "path\\to\\signal";
	std::ifstream infile(filePath);
	std::vector<double> dataFromFile;
	std::string line;

	if (!infile)
	{
		std::cerr << "Cannot open: " << filePath << std::endl;
		return 1;
	}

	while (std::getline(infile, line))
	{
		size_t first = line.find_first_not_of(" \t\r\n");
		if (first == std::string::npos) continue;
		if (line[first] == '#') continue;

		std::istringstream iss(line);
		double value;
		if (iss >> value)
		{
			dataFromFile.push_back(value);
		}
	}

	double* arrayFromFile = nullptr;
	size_t arraySize = dataFromFile.size();
	if (!dataFromFile.empty())
	{
		arrayFromFile = new double[arraySize];
		for (size_t i = 0; i < arraySize; ++i)
		{
			arrayFromFile[i] = dataFromFile[i];
		}
	}

	SignalNative signalNative = { arrayFromFile, (int)arraySize, 1.0 / 51200.0, 0 };
	int outLength = 0;
	double* spectrumResult = nullptr;
	int resCode = AveragedSpectrumByIncrement(
		signalNative,
		30.0,
		4096,
		0.15,
		(int)AverageType::Energy,
		(int)WeightType::None,
		(int)WindowType::Hanning,
		true,
		&spectrumResult,
		(int*)&outLength);

	for (size_t i = 0; i < outLength; ++i)
	{
		std::cout << "dataFromFile[" << i << "] = " << spectrumResult[i] << std::endl;
	}

	delete[] arrayFromFile;
#endif

#if 1
	const std::string signalPath = "path\\to\\signal";
	int signalDataLen = 0;
	double* signalData = ReadDoublesFromFile(signalPath, 0, &signalDataLen);
	SignalNative signalNative2 = { signalData, signalDataLen, 1.0 / 51200.0, 0 };

	const std::string rpmPath = "path\\to\\rpm";
	int rpmDataLen = 0;
	double* rpmData = ReadDoublesFromFile(rpmPath, 0, &rpmDataLen);
	RpmNative rpmNative = { rpmData, rpmDataLen };

	double* colormapData = nullptr;
	int orderBins = 0;
	int rpmBins = 0;
	GenerateOrderColormap(signalNative2, rpmNative, 32, 0.25, 25, (int)WindowType::Rectangular, &colormapData, &orderBins, &rpmBins);

	for (size_t i = 0; i < orderBins; ++i)
	{
		for (size_t j = 0; j < rpmBins; ++j)
		{
			std::cout << colormapData[i * rpmBins + j] << " ";
		}
		std::cout << std::endl;
	}

	delete[] rpmData;
	delete[] signalData;
#endif

}

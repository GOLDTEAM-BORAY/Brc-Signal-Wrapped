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
	const char* licensePath = "path\\to\\license";
	LoadLicense(licensePath);
	std::cout << "License loaded successfully." << std::endl;

	// Demo for AveragedSpectrumByIncrement
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

	// Demo for GenerateOrderColormap
#if 0
	const std::string signalPath = "path\\to\\signal";
	int signalDataLen = 0;
	double* signalData = ReadDoublesFromFile(signalPath, 0, &signalDataLen);
	SignalNative signalNative = { signalData, signalDataLen, 1.0 / 51200.0, 0 };

	const std::string rpmPath = "path\\to\\rpm";
	int rpmDataLen = 0;
	double* rpmData = ReadDoublesFromFile(rpmPath, 0, &rpmDataLen);
	RpmNative rpmNative = { rpmData, rpmDataLen };

	double* colormapData = nullptr;
	int orderBins = 0;
	int rpmBins = 0;
	GenerateOrderColormap(signalNative, rpmNative, 32, 0.25, 25, (int)WindowType::Rectangular, &colormapData, &orderBins, &rpmBins);

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

	// Demo for GenerateTimeFrequencyColormapByOverlap
#if 0
	const std::string signalPath = "path\\to\\signal";
	int signalDataLen = 0;
	double* signalData = ReadDoublesFromFile(signalPath, 0, &signalDataLen);
	SignalNative signalNative = { signalData, signalDataLen, 1.0 / 51200.0, 0 };

	double* colormapData = nullptr;
	int timeBins = 0;
	int frequencyBins = 0;
	int ret = GenerateTimeFrequencyColormapByOverlap(
		signalNative, 
		(int)WindowType::Rectangular, 
		4096, /*谱线数*/
		0.5, /*重叠率*/
		0.0, /*开始时间*/
		-1.0, /*结束时间*/
		&colormapData, /*colormap结果*/
		&timeBins, /*时间轴点*/
		&frequencyBins); /*频率轴点*/

	if (ret < 0)
	{
		const char* errMsg = GetLastErrorMessage(ret);
		std::cerr << "Error: " << errMsg << std::endl;
	}

	for (size_t i = 0; i < timeBins; ++i)
	{
		for (size_t j = 0; j < frequencyBins; ++j)
		{
			std::cout << colormapData[i * frequencyBins + j] << " ";
		}
		std::cout << std::endl;
	}

	delete[] signalData;
#endif

	// Demo for GenerateTimeFrequencyColormapByIncrement
#if 0
	const std::string signalPath = "path\\to\\signal";
	int signalDataLen = 0;
	double* signalData = ReadDoublesFromFile(signalPath, 0, &signalDataLen);
	SignalNative signalNative = { signalData, signalDataLen, 1.0 / 51200.0, 0 };

	double* colormapData = nullptr;
	int timeBins = 0;
	int frequencyBins = 0;
	int ret = GenerateTimeFrequencyColormapByIncrement(
		signalNative,
		(int)WindowType::Rectangular,
		4096, /*谱线数*/
		0.15, /*帧移时间*/
		0.0, /*开始时间*/
		-1.0, /*结束时间*/
		&colormapData, /*colormap结果*/
		&timeBins, /*时间轴点*/
		&frequencyBins); /*频率轴点*/

	if (ret < 0)
	{
		const char* errMsg = GetLastErrorMessage(ret);
		std::cerr << "Error: " << errMsg << std::endl;
	}

	for (size_t i = 0; i < timeBins; ++i)
	{
		for (size_t j = 0; j < frequencyBins; ++j)
		{
			std::cout << colormapData[i * frequencyBins + j] << " ";
		}
		std::cout << std::endl;
	}

	delete[] signalData;
#endif

	// Demo for GenerateRpmFrequencyColormap
#if 0
	const std::string signalPath = "path\\to\\signal";
	int signalDataLen = 0;
	double* signalData = ReadDoublesFromFile(signalPath, 0, &signalDataLen);
	SignalNative signalNative = { signalData, signalDataLen, 1.0 / 51200.0, 0 };

	const std::string rpmPath = "path\\to\\signal";
	int rpmDataLen = 0;
	double* rpmData = ReadDoublesFromFile(rpmPath, 0, &rpmDataLen);
	RpmNative rpmNative = { rpmData, rpmDataLen };

	double* colormapData = nullptr;
	int rpmBins = 0;
	int orderBins = 0;
	int ret = GenerateRpmFrequencyColormap(
		signalNative, 
		rpmNative, 
		(int)WindowType::Rectangular, 
		4096,
		0.0, 
		-1.0, 
		25, 
		&colormapData, 
		&rpmBins, 
		&orderBins);

	if (ret < 0)
	{
		const char* errMsg = GetLastErrorMessage(ret);
		std::cerr << "Error: " << errMsg << std::endl;
	}

	for (size_t i = 0; i < rpmBins; ++i)
	{
		for (size_t j = 0; j < orderBins; ++j)
		{
			std::cout << colormapData[i * orderBins + j] << " ";
		}
		std::cout << std::endl;
	}
#endif

	// Demo for OverallSoundPressureLevelSpectral
#if 0
	const std::string signalPath = "path\\to\\signal";
	int signalDataLen = 0;
	double* signalData = ReadDoublesFromFile(signalPath, 0, &signalDataLen);
	SignalNative signalNative = { signalData, signalDataLen, 1.0 / 51200.0, 0 };

	double* levelData = nullptr;
	int timeBins = 0;
	int ret = OverallSoundPressureLevelSpectral(
		signalNative,
		30.0,
		4096, 
		0.15, 
		(int)WindowType::Hanning, 
		(int)WeightType::None, 
		&levelData, 
		&timeBins);

	if (ret < 0)
	{
		const char* errMsg = GetLastErrorMessage(ret);
		std::cerr << "Error: " << errMsg << std::endl;
	}

	for (size_t i = 0; i < timeBins; ++i)
	{
		std::cout << levelData[i] << std::endl;
	}
#endif
}

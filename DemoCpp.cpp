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
	system("cls");
	std::cout << "License loaded successfully." << std::endl;

	// Demo for AveragedSpectrumByIncrement
#if 0
	const char* filePath = "D:\\source\\BrcSignalKit\\Brc.Signal.Tests\\Data\\gobao\\src\\sound_signal.txt";
	int signalDataLen = 0;
	double* signalData = ReadDoublesFromFile(filePath, 0, &signalDataLen);

	SignalNative signalNative = { signalData, signalDataLen, 1.0 / 51200.0, 0 };
	int outLength = 0;
	double* spectrumResult = nullptr;
	int resCode = AveragedSpectrumByIncrement(
		signalNative,
		4096,
		0.15,
		(int)FormatType::RMS,
		(int)AverageType::Energy,
		(int)WindowType::Hanning,
		(int)WeightType::A,
		&spectrumResult,
		(int*)&outLength);

	if (resCode != 1)
	{
		const char* errMsg = GetLastErrorMessage(resCode);
		std::cerr << "Error: " << errMsg << std::endl;
	}

	for (size_t i = 0; i < outLength; ++i)
	{
		std::cout << spectrumResult[i] << std::endl;
	}

	delete[] signalData;
#endif

	// Demo for OrderSection
#if 0
	const char* filePath = "D:\\source\\BrcSignalKit\\Brc.Signal.Tests\\Data\\gobao\\src\\sound_signal.txt";
	int signalDataLen = 0;
	double* signalData = ReadDoublesFromFile(filePath, 0, &signalDataLen);
	SignalNative signalNative = { signalData, signalDataLen, 1.0 / 51200.0, 0 };

	const std::string rpmPath = "D:\\source\\BrcSignalKit\\Brc.Signal.Tests\\Data\\gobao\\src\\speed.txt";
	int rpmDataLen = 0;
	double* rpmData = ReadDoublesFromFile(rpmPath.c_str(), 0, &rpmDataLen);
	std::vector<double> timeValuesVec(rpmDataLen);
	for (int i = 0; i < rpmDataLen; ++i) {
		timeValuesVec[i] = i * (1.0 / 51200.0);
	}
	double* timeData = timeValuesVec.data();
	RpmNative rpmNative = { rpmData, timeData, rpmDataLen };

	double* orderSectionData = nullptr;
	double* rpmOutData = nullptr;
	int rpmBins = 0;
	int resCode = OrderSection(
		signalNative,
		rpmNative,
		4096,
		14.0,
		0.5,
		25.0,
		1.0, // referenceValue
		(int)WindowType::Hanning,
		(int)WeightType::A,
		(int)ScaleType::Db,
		&orderSectionData,
		&rpmOutData,
		&rpmBins);

	if (resCode != 1)
	{
		const char* errMsg = GetLastErrorMessage(resCode);
		std::cerr << "Error: " << errMsg << std::endl;
	}

	for (size_t i = 0; i < rpmBins; ++i)
	{
		std::cout << "RPM: " << rpmOutData[i] << "\t\tAMP: " << orderSectionData[i] << std::endl;
	}

	delete[] rpmData;
	delete[] signalData;
#endif

	// Demo for GenerateTimeFrequencyColormapByIncrement
#if 0
	const char* filePath = "D:\\source\\BrcSignalKit\\Brc.Signal.Tests\\Data\\gobao\\src\\sound_signal.txt";
	int signalDataLen = 0;
	double* signalData = ReadDoublesFromFile(filePath, 0, &signalDataLen);
	SignalNative signalNative = { signalData, signalDataLen, 1.0 / 51200.0, 0 };

	double* colormapData = nullptr;
	int timeBins = 0;
	int frequencyBins = 0;
	int resCode = GenerateTimeFrequencyColormapByIncrement(
		signalNative,
		4096,
		0.15,
		0.0,
		-1.0,
		1.0, // referenceValue
		(int)FormatType::RMS,
		(int)WindowType::Rectangular,
		(int)WeightType::None,
		(int)ScaleType::Db,
		&colormapData,
		&timeBins,
		&frequencyBins);

	if (resCode != 1)
	{
		const char* errMsg = GetLastErrorMessage(resCode);
		std::cerr << "Error: " << errMsg << std::endl;
	}

	for (size_t i = 0; i < timeBins; ++i)
	{
		for (size_t j = 0; j < frequencyBins; ++j)
		{
			std::cout << colormapData[i * frequencyBins + j] << "\n";
		}
		std::cout << std::endl;
	}

	delete[] signalData;
#endif

	// Demo for GenerateRpmFrequencyColormap
#if 0
	const std::string signalPath = "D:\\source\\BrcSignalKit\\Brc.Signal.Tests\\Data\\gobao\\src\\sound_signal.txt";
	int signalDataLen = 0;
	double* signalData = ReadDoublesFromFile(signalPath.c_str(), 0, &signalDataLen);
	SignalNative signalNative = { signalData, signalDataLen, 1.0 / 51200.0, 0 };

	const std::string rpmPath = "D:\\source\\BrcSignalKit\\Brc.Signal.Tests\\Data\\gobao\\src\\speed.txt";
	int rpmDataLen = 0;
	double* rpmData = ReadDoublesFromFile(rpmPath.c_str(), 0, &rpmDataLen);
	std::vector<double> timeValuesVec(rpmDataLen);
	for (int i = 0; i < rpmDataLen; ++i) {
	    timeValuesVec[i] = i * (1.0 / 51200.0);
	}
	double* timeData = timeValuesVec.data();
	RpmNative rpmNative = { rpmData, timeData, rpmDataLen };

	double* colormapData = nullptr;
	double* rpmOutData = nullptr;
	double* freqOutData = nullptr;

	int rpmBins = 0;
	int freqBins = 0;
	int resCode = GenerateRpmFrequencyColormap(
		signalNative,
		rpmNative,
		4096,
		0.0,
		-1.0,
		25.0,
		1.0, // referenceValue
		(int)FormatType::RMS,
		(int)WindowType::Hanning,
		(int)WeightType::A,
		(int)ScaleType::Db,
		&colormapData,
		&rpmOutData,
		&freqOutData,
		&rpmBins,
		&freqBins);

	if (resCode != 1)
	{
		const char* errMsg = GetLastErrorMessage(resCode);
		std::cerr << "Error: " << errMsg << std::endl;
	}

	for (size_t i = 0; i < rpmBins; ++i)
	{
		std::cout << "RPM: " << rpmOutData[i] << std::endl << std::endl;
		for (size_t j = 0; j < freqBins; ++j)
		{
			std::cout << freqOutData[j] << "\t\t" << colormapData[i * rpmBins + j] << std::endl;
		}
		std::cout << std::endl;
	}
#endif

	// Demo for OverallLevelSpectral
#if 0
	const std::string signalPath = "D:\\source\\BrcSignalKit\\Brc.Signal.Tests\\Data\\gobao\\src\\vibration_signal.txt";
	int signalDataLen = 0;
	double* signalData = ReadDoublesFromFile(signalPath.c_str(), 0, &signalDataLen);
	SignalNative signalNative = { signalData, signalDataLen, 1.0 / 51200.0, 0 };

	double* levelData = nullptr;
	int timeBins = 0;
	int resCode = OverallLevelSpectral(
		signalNative,
		4096,
		0.15,
		1.0, // referenceValue
		(int)WindowType::Hanning,
		(int)WeightType::None,
		(int)ScaleType::Db,
		&levelData,
		&timeBins);

	if (resCode != 1)
	{
		const char* errMsg = GetLastErrorMessage(resCode);
		std::cerr << "Error: " << errMsg << std::endl;
	}

	for (size_t i = 0; i < timeBins; ++i)
	{
		std::cout << levelData[i] << std::endl;
	}
#endif

	// Demo for AveragedOctaveBandLevels
#if 0
	const std::string signalPath = "D:\\source\\BrcSignalKit\\Brc.Signal.Tests\\Data\\gobao\\src\\sound_signal.txt";
	int signalDataLen = 0;
	double* signalData = ReadDoublesFromFile(signalPath.c_str(), 0, &signalDataLen);
	SignalNative signalNative = { signalData, signalDataLen, 1.0 / 51200.0, 0 };

	double* levelData = nullptr;
	double* centerFreqs = nullptr;
	double* lowerFreqs = nullptr;
	double* upperFreqs = nullptr;
	int levelBins = 0;
	int resCode = AveragedOctaveBandLevels(signalNative,
		4096,
		0.15,
		12,
		26000,
		2e-5, // referenceValue
		(int)FormatType::RMS,
		(int)OctaveType::ThirdOctave,
		(int)AverageType::Energy,
		(int)WindowType::Hanning,
		(int)WeightType::A,
		(int)ScaleType::Db,
		&levelData,
		&centerFreqs,
		&lowerFreqs,
		&upperFreqs,
		&levelBins);

	if (resCode != 1)
	{
		const char* errMsg = GetLastErrorMessage(resCode);
		std::cerr << "Error: " << errMsg << std::endl;
	}

	for (size_t i = 0; i < levelBins; ++i)
	{
		std::cout << centerFreqs[i] << "\t\t" << levelData[i] << std::endl;
	}

	delete[] signalData;
#endif

	// Demo for PulseToRpm
#if 0
	const std::string signalPath = "D:/source/BrcSignalKit/Brc.Signal.Tests/Data/gobao/src/pulse_signal.txt";
	int signalDataLen = 0;
	double* signalData = ReadDoublesFromFile(signalPath.c_str(), 0, &signalDataLen);
	SignalNative signalNative = { signalData, signalDataLen, 1.0 / 51200.0, 0 };

	EdgeDetectorNative edgeDetectorNative = { 10, 0.5, 0 };
	RpmCalculationOptionsNative rpmCalculationOptionsNative = { 2, 10, 1, true, -1.0, -1.0, 0.1 };
	RpmNative rpmNative;

	int resCode = PulseToRpm(signalNative, edgeDetectorNative, rpmCalculationOptionsNative, &rpmNative);
	if (resCode != 1)
	{
		const char* errMsg = GetLastErrorMessage(resCode);
		std::cerr << "Error: " << errMsg << std::endl;
	}
	for (size_t i = 0; i < rpmNative.Length; ++i)
	{
		std::cout << "Time: " << rpmNative.TimeValues[i] << "\t\tRPM: " << rpmNative.RpmValues[i] << std::endl;
	}
	delete[] signalData;
#endif

	// Demo for RMS
#if 0
	const std::string signalPath = "D:\\source\\BrcSignalKit\\Brc.Signal.Tests\\Data\\gobao\\src\\sound_signal.txt";
	int signalDataLen = 0;
	double* signalData = ReadDoublesFromFile(signalPath.c_str(), 0, &signalDataLen);
	SignalNative signalNative = { signalData, signalDataLen, 1.0 / 51200.0, 0 };

	double outValue = 0.0;
	int resCode = GetRms(signalNative, (int)WeightType::A, &outValue);

	if (resCode != 1)
	{
		const char* errMsg = GetLastErrorMessage(resCode);
		std::cerr << "Error: " << errMsg << std::endl;
	}
	else
	{
		std::cout << "RMS Value: " << outValue << std::endl;
	}
#endif
}

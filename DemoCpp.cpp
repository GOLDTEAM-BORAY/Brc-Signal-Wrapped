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
		30.0,
		4096,
		0.15,
		(int)FormatType::RMS,
		(int)AverageType::Energy,
		(int)WeightType::A,
		(int)WindowType::Hanning,
		true,
		&spectrumResult,
		(int*)&outLength);

	if (resCode < 0)
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

	// Demo for GenerateOrderColormap
#if 0
	const char* filePath = "D:\\source\\BrcSignalKit\\Brc.Signal.Tests\\Data\\gobao\\src\\sound_signal.txt";
	int signalDataLen = 0;
	double* signalData = ReadDoublesFromFile(filePath, 0, &signalDataLen);
	SignalNative signalNative = { signalData, signalDataLen, 1.0 / 51200.0, 0 };

	const std::string rpmPath = "path\\to\\rpm";
	int rpmDataLen = 0;
	double* rpmData = ReadDoublesFromFile(rpmPath, 0, &rpmDataLen);
	RpmNative rpmNative = { rpmData, rpmDataLen };

	double* colormapData = nullptr;
	int orderBins = 0;
	int rpmBins = 0;
	GenerateOrderRpmColormap(signalNative, rpmNative, 32, 0.25, 25, (int)FormatType::RMS, (int)WindowType::Rectangular, (int)ScaleType::Db, & colormapData, &orderBins, &rpmBins);

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
	const char* filePath = "D:\\source\\BrcSignalKit\\Brc.Signal.Tests\\Data\\order\\time_freq\\src\\signal.txt";
	int signalDataLen = 0;
	double* signalData = ReadDoublesFromFile(filePath, 0, &signalDataLen);
	SignalNative signalNative = { signalData, signalDataLen, 1.0 / 51200.0, 0 };

	double* colormapData = nullptr;
	int timeBins = 0;
	int frequencyBins = 0;
	int ret = GenerateTimeFrequencyColormapByOverlap(
		signalNative, 
		(int)FormatType::Peak,
		(int)WindowType::Rectangular,
		(int)WeightType::None,
		(int)ScaleType::Linear,
		2560, /*谱线数*/
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

	for (size_t i = 20; i < timeBins; ++i)
	{
		for (size_t j = 0; j < frequencyBins; ++j)
		{
			std::cout << colormapData[i * frequencyBins + j] << "\n";
		}
		std::cout << std::endl;
	}

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
	int ret = GenerateTimeFrequencyColormapByIncrement(
		signalNative,
		(int)SignalType::Acoustic,
		(int)FormatType::RMS,
		(int)WindowType::Rectangular,
		(int)WeightType::None,
		(int)ScaleType::Db,
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
	double* signalData = ReadDoublesFromFile(signalPath, 0, &signalDataLen);
	SignalNative signalNative = { signalData, signalDataLen, 1.0 / 51200.0, 0 };

	const std::string rpmPath = "D:\\source\\BrcSignalKit\\Brc.Signal.Tests\\Data\\gobao\\src\\speed.txt";
	int rpmDataLen = 0;
	double* rpmData = ReadDoublesFromFile(rpmPath, 0, &rpmDataLen);

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
	int ret = GenerateRpmFrequencyColormap(
		signalNative, 
		rpmNative, 
		(int)SignalType::Acoustic,
		(int)FormatType::RMS,
		(int)WindowType::Hanning, 
		(int)WeightType::A,
		(int)ScaleType::Db,
		4096,
		0.0, 
		-1.0, 
		25, 
		&colormapData, 
		&rpmOutData,
		&freqOutData,
		&rpmBins, 
		&freqBins);

	if (ret < 0)
	{
		const char* errMsg = GetLastErrorMessage(ret);
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

	// Demo for OverallSoundPressureLevelSpectral
#if 0
	const std::string signalPath = "D:\\source\\BrcSignalKit\\Brc.Signal.Tests\\Data\\gobao\\src\\vibration_signal.txt";
	int signalDataLen = 0;
	double* signalData = ReadDoublesFromFile(signalPath, 0, &signalDataLen);
	SignalNative signalNative = { signalData, signalDataLen, 1.0 / 51200.0, 0 };

	double* levelData = nullptr;
	int timeBins = 0;
	int ret = OverallLevelSpectral(
		signalNative,
		SignalType::Vibration,
		40,
		4096, 
		0.15, 
		(int)WindowType::Hanning, 
		(int)WeightType::None, 
		(int)ScaleType::Db,
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

	// Demo for AveragedOctaveBandLevels
#if 0
	const std::string signalPath = "D:\\source\\BrcSignalKit\\Brc.Signal.Tests\\Data\\gobao\\src\\sound_signal.txt";
	int signalDataLen = 0;
	double* signalData = ReadDoublesFromFile(signalPath, 0, &signalDataLen);
	SignalNative signalNative = { signalData, signalDataLen, 1.0 / 51200.0, 0 };

	double* levelData = nullptr;
	double* centerFreqs = nullptr;
	double* lowerFreqs = nullptr;
	double* upperFreqs = nullptr;
	int levelBins = 0;
	int ret = AveragedOctaveBandLevels(signalNative,
		40.0,
		40966,
		0.15,
		(int)FormatType::RMS,
		(int)OctaveType::ThirdOctave,
		(int)AverageType::Energy,
		(int)WindowType::Hanning,
		(int)ScaleType::Db,
		(int)WeightType::A,
		12,
		26000,
		&levelData,
		&centerFreqs,
		&lowerFreqs,
		&upperFreqs,
		&levelBins);


	if (ret < 0)
	{
		const char* errMsg = GetLastErrorMessage(ret);
		std::cerr << "Error: " << errMsg << std::endl;
	}

	for (size_t i = 0; i < levelBins; ++i)
	{
		std::cout << centerFreqs[i] << "\t\t" << levelData[i] << std::endl;
	}

	delete[] signalData;
#endif

	// Demo for OrderSection
#if 0
	const std::string signalPath = "D:/source/BrcSignalKit/Brc.Signal.Tests/Data/gobao/src/acoustic_signal.txt";
	int signalDataLen = 0;
	double* signalData = ReadDoublesFromFile(signalPath, 0, &signalDataLen);
	SignalNative signalNative = { signalData, signalDataLen, 1.0 / 51200.0, 0 };
	SignalSlice(signalNative, 15.0, 30.0, &signalNative);

	const std::string rpmPath = "D:/source/BrcSignalKit/Brc.Signal.Tests/Data/gobao/src/speed.txt";
	int rpmDataLen = 0;
	double* rpmData = ReadDoublesFromFile(rpmPath, 0, &rpmDataLen);
	std::vector<double> timeValuesVec(rpmDataLen);
	for (int i = 0; i < rpmDataLen; ++i) {
		timeValuesVec[i] = i * (1.0 / 51200.0);
	}
	double* timeData = timeValuesVec.data();
	RpmNative rpmNative = { rpmData, timeData, rpmDataLen };
	RpmSlice(rpmNative, 15.0, 30.0, &rpmNative);

	double* orderSectionData = nullptr;
	double* rpmOutData = nullptr;
	int rpmBins = 0;

	int ret = OrderSection(signalNative,
		rpmNative,
		(int)SignalType::Acoustic,
		(int)WindowType::Hanning,
		(int)WeightType::A,
		(int)ScaleType::Db,
		4096,
		14.0,
		0.5,
		25.0,
		&orderSectionData,
		&rpmOutData,
		&rpmBins);

	if (ret < 0)
	{
		const char* errMsg = GetLastErrorMessage(ret);
		std::cerr << "Error: " << errMsg << std::endl;
	}

	for (size_t i = 0; i < rpmBins; ++i)
	{
		std::cout << "RPM: " << rpmOutData[i] << "\t\tAMP: " << orderSectionData[i] << std::endl;
	}
#endif

	// Demo for PulseToRpm
#if 0
	const std::string signalPath = "D:/source/BrcSignalKit/Brc.Signal.Tests/Data/gobao/src/pulse_signal.txt";
	int signalDataLen = 0;
	double* signalData = ReadDoublesFromFile(signalPath, 0, &signalDataLen);
	SignalNative signalNative = { signalData, signalDataLen, 1.0 / 51200.0, 0 };

	EdgeDetectorNative edgeDetectorNative = { 10, 0.5, 0 };
	RpmCalculationOptionsNative rpmCalculationOptionsNative = { 2, 10, 1, true, -1.0, -1.0, 0.1 };
	RpmNative rpmNative;

	int ret = PulseToRpm(signalNative, edgeDetectorNative, rpmCalculationOptionsNative, &rpmNative);
	if (ret < 0)
	{
		const char* errMsg = GetLastErrorMessage(ret);
		std::cerr << "Error: " << errMsg << std::endl;
	}
	for (size_t i = 0; i < rpmNative.Length; ++i)
	{
		std::cout << "Time: " << rpmNative.TimeValues[i] << "\t\tRPM: " << rpmNative.RpmValues[i] << std::endl;
	}
	delete[] signalData;
#endif
}

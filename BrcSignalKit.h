#pragma once
#include "Types.h"
#include "FileReader.h"

#ifdef __cplusplus
extern "C" {
#endif
	/// <summary>
	/// 1-1. 声压总级
	/// </summary>
	/// <param name="signalNative">输入的信号数据结构体。</param>
	/// <param name="spectrumLines">谱线数，决定频谱分辨率。</param>
	/// <param name="increment">分析步进，单位为秒。</param>
	/// <param name="referenceValue">参考值，仅用于db输出时的参考值。</param>
	/// <param name="windowType">窗函数类型 0-矩形窗 1-Hanning窗</param>
	/// <param name="weightType">加权类型 0-A计权 1-B计权 2-C计权</param>
	/// <param name="scaleType">缩放类型 0-线性输出 1-DB输出</param>
	/// <param name="levelData">输出参数，指向计算得到的声压级数据的指针。</param>
	/// <param name="timeBins">输出参数，指向时间分量的指针。</param>
	/// <returns>返回1表示成功，其他值表示错误代码。</returns>
	int OverallLevelSpectral(SignalNative signalNative, int spectrumLines, double increment, double referenceValue, int windowType, int weightType, int scaleType, double** levelData, int* timeBins);

	/// <summary>
	/// 1-2. 声压总级-跟踪转速
	/// </summary>
	/// <param name="signalNative">输入的信号数据结构体。</param>
	/// <param name="rpmNative">输入的信号数据结构体。</param>
	/// <param name="spectrumLines">谱线数，决定频谱分辨率。</param>
	/// <param name="lowerRpmThreshold">转速下限，=0时取转速信号的最小转速</param>
	/// <param name="upperRpmThreshold">转速上线，=-1时取转速信号的最大转速</param>
	/// <param name="rpmStep">转速步长</param>
	/// <param name="referenceValue">DB参考值</param>
	/// <param name="windowType">窗函数类型 0-矩形窗 1-Hanning窗</param>
	/// <param name="weightType">加权类型 0-A计权 1-B计权 2-C计权</param>
	/// <param name="scaleType">缩放类型 0-线性输出 1-DB输出<</param>
	/// <param name="rpmTriggerType">转速触发类型。0-Up触发 1-Imm. Up触发</param>
	/// <param name="levelData">输出参数，指向计算得到的声压级数据的指针。</param>
	/// <param name="rpmBins">输出参数，指向转速分量的指针。</param>
	/// <returns>返回1表示成功，其他值表示错误代码。</returns>
	int OverallLevelSpectralTacho(SignalNative signalNative, RpmNative rpmNative, int spectrumLines, double lowerRpmThreshold, double upperRpmThreshold, double rpmStep, double referenceValue, int windowType, int weightType, int scaleType, int rpmTriggerType, double** levelData, double** rpmData, int* rpmBins);

	/// <summary>
	/// 2. 阶次震动和噪声
	/// </summary>
	/// <param name="signalNative">输入的信号数据结构体。</param>
	/// <param name="rpmNative">输入的转速数据结构体。</param>
	/// <param name="spectrmmLines">谱线数，决定阶次分辨率。</param>
	/// <param name="targetOrder">目标阶次。</param>
	/// <param name="orderBandwidth">阶次带宽。</param>
	/// <param name="lowerRpmThreshold">转速下限。</param>
	/// <param name="upperRpmThreshold">转速上限。</param>
	/// <param name="rpmStep">转速步进，单位为rpm。</param>
	/// <param name="referenceValue">参考值，仅用于db输出时的参考值。</param>
	/// <param name="formatType">输出格式类型。 0-RMS 1-Peak 2-Peak to peak</param>
	/// <param name="windowType">窗函数类型 0-矩形窗 1-Hanning窗</param>
	/// <param name="weightType">加权类型 0-A计权 1-B计权 2-C计权</param>
	/// <param name="scaleType">缩放类型 0-线性输出 1-DB输出</param>
	/// <param name="rpmTriggerType">转速触发类型。0-Up触发 1-Imm. Up触发</param>
	/// <param name="outOrderSection">输出参数，指向计算得到的阶次区段数据的指针。</param>
	/// <param name="outRpmPoints">输出参数，指向对应转速点的指针。</param>
	/// <param name="rpmBins">输出参数，指向转速分箱数量的指针。</param>
	/// <returns>返回1表示成功，其他值表示错误代码。</returns>
	int OrderSection(SignalNative signalNative, RpmNative rpmNative, int spectrmmLines, double targetOrder, double orderBandwidth, double lowerRpmThreshold, double upperRpmThreshold, double rpmStep, double referenceValue, int formatType, int windowType, int weightType, int scaleType, int rpmTriggerType, double** outOrderSection, double** outRpmPoints, int* rpmBins);

	/// <summary>
	/// 3. 振动和噪声RMS
	/// </summary>
	/// <param name="signalNative">输入的信号数据结构体。</param>
	/// <param name="weightType">加权类型，0-A计权 1-B计权 2-C计权。</param>
	/// <param name="outValue">输出参数，指向计算得到的RMS值的指针。</param>
	/// <returns>返回1表示成功，其他值表示错误代码。</returns>
	int GetRms(SignalNative signalNative, int weightType, double* outValue);

	/// <summary>
	/// 4. 振动最大值
	/// </summary>
	/// <param name="signalNative">输入的信号数据结构体。</param>
	/// <param name="outValue">输出参数，指向计算得到的最大值的指针。</param>
	/// <returns>返回1表示成功，其他值表示错误代码。</returns>
	int GetMax(SignalNative signalNative, double* outValue);

	/// <summary>
	/// 5. 倍频程分析（Octave Band Analysis）
	/// </summary>
	/// <param name="signalNative">输入的信号数据结构体。</param>
	/// <param name="spectrumLines">谱线数，决定频带分辨率。</param>
	/// <param name="increment">分析步进，单位为秒。</param>
	/// <param name="lowerFreq">分析的最低频率。</param>
	/// <param name="upperFreq">分析的最高频率。</param>
	/// <param name="referenceValue">参考值，仅用于db输出时的参考值。</param>
	/// <param name="formatType">输出格式类型。 0-RMS 1-Peak 2-Peak to peak</param>
	/// <param name="octaveType">倍频程类型</param>
	/// <param name="averageType">平均类型。</param>
	/// <param name="windowType">窗函数类型。</param>
	/// <param name="weightType">加权类型</param>
	/// <param name="scaleType">缩放类型</param>
	/// <param name="levelData">输出参数，指向计算得到的倍频程能量数据的指针。</param>
	/// <param name="centerFreqs">输出参数，指向中心频率数组的指针。</param>
	/// <param name="lowerFreqs">输出参数，指向每个频带下限频率数组的指针。</param>
	/// <param name="upperFreqs">输出参数，指向每个频带上限频率数组的指针。</param>
	/// <param name="levelBins">输出参数，指向频带数量的指针。</param>
	/// <returns>返回1表示成功，其他值表示错误代码。</returns>
	int AveragedOctaveBandLevels(SignalNative signalNative, int spectrumLines, double increment, double lowerFreq, double upperFreq, double referenceValue, int foramtType, int octaveType, int averageType, int windowType, int weightType, int scaleType, double** levelData, double** centerFreqs, double** lowerFreqs, double** upperFreqs, int* levelBins);

	/// <summary>
	/// 6-1. 阶次谱
	/// </summary>
	/// <param name="signalNative">输入的信号数据结构体。</param>
	/// <param name="rpmNative">输入的转速数据结构体。</param>
	/// <param name="maxOrder">阶次的最大值。</param>
	/// <param name="orderResolution">阶次分辨率。</param>
	/// <param name="oversamplingFactor">过采样因子。</param>
	/// <param name="lowerRpmThreshold">转速下限。</param>
	/// <param name="upperRpmThreshold">转速上限。</param>
	/// <param name="rpmStep">转速步进，单位为rpm。</param>
	/// <param name="referenceValue">参考值，仅用于db输出时的参考值。</param>
	/// <param name="formatType">输出格式类型。</param>
	/// <param name="windowType">窗函数类型。</param>
	/// <param name="weightType">加权类型。</param>
	/// <param name="scaleType">缩放类型。</param>
	/// <param name="spectrumData">输出参数，指向阶次谱数据的指针。</param>
	/// <param name="orderAxis">输出参数，指向阶次轴数据的指针。</param>
	/// <param name="orderBins">输出参数，指向阶次分箱数量的指针。</param>
	/// <returns>返回1表示成功，其他值表示错误代码。</returns>
	int OrderSpectrum(SignalNative signalNative, RpmNative rpmNative, double maxOrder, double orderResolution, double oversamplingFactor, double lowerRpmThreshold, double upperRpmThreshold, double rpmStep, double referenceValue, int formatType, int windowType, int weightType, int scaleType, double** spectrumData, double** orderAxis, int* orderBins);

	/// <summary>
	/// 6-2. 平均阶次谱-转速跟踪
	/// </summary>
	/// <param name="signalNative">输入的信号数据结构体，包含信号采样、长度、采样间隔等。</param>
	/// <param name="rpmNative">输入的转速数据结构体，包含转速值、时间点、数据点数等。</param>
	/// <param name="spectrumLines">谱线数，决定每个分析窗的频谱分辨率。</param>
	/// <param name="maxOrder">阶次最大值，决定阶次谱的分析范围。</param>
	/// <param name="orderResolution">阶次分辨率，阶次轴的步进。</param>
	/// <param name="lowerRpmThreshold">转速下限，低于该值的数据不参与分析。</param>
	/// <param name="upperRpmThreshold">转速上限，高于该值的数据不参与分析，-1.0表示最大转速。</param>
	/// <param name="rpmStep">转速步进，单位为rpm。</param>
	/// <param name="referenceValue">参考值，仅用于dB输出时的参考值（如声压级常用2e-5 Pa）。</param>
	/// <param name="formatType">输出格式类型：0-RMS，1-Peak，2-Peak to Peak。</param>
	/// <param name="windowType">窗函数类型：0-矩形窗，1-Hanning窗。</param>
	/// <param name="weightType">加权类型：0-无加权，1-A计权，2-B计权，3-C计权。</param>
	/// <param name="scaleType">缩放类型：0-线性输出，1-dB输出。</param>
	/// <param name="rpmTriggerType">转速触发类型。0-Up触发，1-Imm. Up触发。</param>
	/// <param name="spectrumData">输出参数，指向平均阶次谱数据的指针，需释放。</param>
	/// <param name="orderAxis">输出参数，指向阶次坐标数组的指针，需释放。</param>
	/// <param name="orderBins">输出参数，指向阶次数量的指针。</param>
	/// <returns>返回1表示成功，其他值表示错误代码。</returns>
	int AvgOrderSpectrumTacho(SignalNative signalNative, RpmNative rpmNative, int spectrumLines, double maxOrder, double orderResolution, double lowerRpmThreshold, double upperRpmThreshold, double rpmStep, double referenceValue, int formatType, int windowType, int weightType, int scaleType, int rpmTriggerType, double** spectrumData, double** orderAxis, int* orderBins);

	/// <summary>
	/// 6-3. 平均阶次谱-时间跟踪
	/// </summary>
	/// <param name="signalNative">输入的信号数据结构体，包含信号采样、长度、采样间隔等。</param>
	/// <param name="rpmNative">输入的转速数据结构体，包含转速值、时间点、数据点数等。</param>
	/// <param name="spectrumLines">谱线数，决定每个分析窗的频谱分辨率。</param>
	/// <param name="increment">帧移时间</param>
	/// <param name="maxOrder">阶次最大值，决定阶次谱的分析范围。</param>
	/// <param name="orderResolution">阶次分辨率，阶次轴的步进。</param>
	/// <param name="referenceValue">参考值，仅用于dB输出时的参考值（如声压级常用2e-5 Pa）。</param>
	/// <param name="formatType">输出格式类型：0-RMS，1-Peak，2-Peak to Peak。</param>
	/// <param name="windowType">窗函数类型：0-矩形窗，1-Hanning窗。</param>
	/// <param name="weightType">加权类型：0-无加权，1-A计权，2-B计权，3-C计权。</param>
	/// <param name="scaleType">缩放类型：0-线性输出，1-dB输出。</param>
	/// <param name="spectrumData">输出参数，指向平均阶次谱数据的指针，需释放。</param>
	/// <param name="orderAxis">输出参数，指向阶次坐标数组的指针，需释放。</param>
	/// <param name="orderBins">输出参数，指向阶次数量的指针。</param>
	/// <returns></returns>
	int AvgOrderSpectrumTime(SignalNative signalNative, RpmNative rpmNative, int spectrumLines, double increment, double maxOrder, double orderResolution, double referenceValue, int formatType, int windowType, int weightType, int scaleType, double** spectrumData, double** orderAxis, int* orderBins);

	/// <summary>
	/// 7. 振动和噪音平均谱
	/// </summary>
	/// <param name="signalNative">输入的信号数据结构体。</param>
	/// <param name="spectrumLines">谱线数，决定频谱分辨率。</param>
	/// <param name="increment">分析步进，单位为秒。</param>
	/// <param name="formatType">输出格式类型。 0-RMS 1-Peak 2-Peak to peak</param>
	/// <param name="averageType">平均类型。</param>
	/// <param name="weightType">加权类型。</param>
	/// <param name="windowType">窗函数类型。</param>
	/// <param name="outSpectrum">输出参数，指向计算得到的平均谱数据的指针。</param>
	/// <param name="outLength">输出参数，指向平均谱长度的指针。</param>
	/// <returns>返回1表示成功，其他值表示错误代码。</returns>
	int AveragedSpectrumByIncrement(SignalNative signalNative, int spectrumLines, double increment, int formatType, int averageType, int windowType, int weightType, double** outSpectrum, int* outLength);

	/// <summary>
	/// 8. 包络谱
	/// </summary>
	/// <param name="signalNative">输入的信号数据结构体。</param>
	/// <param name="outEnvelope">输出参数，指向计算得到的包络谱数据的指针。</param>
	/// <param name="outLength">输出参数，指向包络谱长度的指针。</param>
	/// <returns>返回1表示成功，其他值表示错误代码。</returns>
	int GetEnvelope(SignalNative signalNative, double** outEnvelope, int* outLength);

	/// <summary>
	/// 9. 色谱图（时间-频率）
	/// </summary>
	/// <param name="signalNative">输入的信号数据结构体。</param>
	/// <param name="spectrumLines">谱线数，决定频谱分辨率。</param>
	/// <param name="increment">分析步进，单位为秒。</param>
	/// <param name="startTime">分析起始时间，单位为秒。</param>
	/// <param name="endTime">分析结束时间，单位为秒，-1.0表示到信号末尾。</param>
	/// <param name="referenceValue">参考值，仅用于db输出时的参考值。</param>
	/// <param name="formatType">输出格式类型。 0-RMS 1-Peak 2-Peak to peak</param>
	/// <param name="windowType">窗函数类型。</param>
	/// <param name="weightType">加权类型。</param>
	/// <param name="scaleType">缩放类型。</param>
	/// <param name="colormapData">输出参数，指向色谱图数据的指针。</param>
	/// <param name="timeBins">输出参数，指向时间分箱数量的指针。</param>
	/// <param name="frequencyBins">输出参数，指向频率分箱数量的指针。</param>
	/// <returns>返回1表示成功，其他值表示错误代码。</returns>
	int GenerateTimeFrequencyColormapByIncrement(SignalNative signalNative, int spectrumLines, double increment, double startTime, double endTime, double referenceValue, int formatType, int windowType, int weightType, int scaleType, double** colormapData, int* timeBins, int* frequencyBins);

	/// <summary>
	/// 10. 色谱图（转速-频率）
	/// </summary>
	/// <param name="signalNative">输入的信号数据结构体。</param>
	/// <param name="rpmNative">输入的转速数据结构体。</param>
	/// <param name="spectrumLines">谱线数，决定频谱分辨率。</param>
	/// <param name="lowerRpmThreshold">转速下限。</param>
	/// <param name="upperRpmThreshold">转速上限，-1.0表示最大转速。</param>
	/// <param name="rpmStep">转速步进，单位为rpm。</param>
	/// <param name="referenceValue">参考值，仅用于db输出时的参考值。</param>
	/// <param name="formatType">输出格式类型。</param>
	/// <param name="windowType">窗函数类型。</param>
	/// <param name="weightType">加权类型。</param>
	/// <param name="scaleType">缩放类型。</param>
	/// <param name="rpmTriggerType">转速触发类型。0-Up触发 1-Imm. Up触发</param>
	/// <param name="colormapData">输出参数，指向色谱图数据的指针。</param>
	/// <param name="rpmData">输出参数，指向转速轴数据的指针。</param>
	/// <param name="freqData">输出参数，指向频率轴数据的指针。</param>
	/// <param name="rpmBins">输出参数，指向转速分箱数量的指针。</param>
	/// <param name="frequencyBins">输出参数，指向频率分箱数量的指针。</param>
	/// <returns>返回1表示成功，其他值表示错误代码。</returns>
	int GenerateRpmFrequencyColormap(SignalNative signalNative, RpmNative rpmNative, int spectrumLines, double lowerRpmThreshold, double upperRpmThreshold, double rpmStep, double referenceValue, int formatType, int windowType, int weightType, int scaleType, int rpmTriggerType, double** colormapData, double** rpmData, double** freqData, int* rpmBins, int* frequencyBins);

	/// <summary>
	/// 11. 色谱图（转速-阶次）
	/// </summary>
	/// <param name="signalNative">输入的信号数据结构体。</param>
	/// <param name="rpmNative">输入的转速数据结构体。</param>
	/// <param name="maxOrder">阶次的最大值。</param>
	/// <param name="orderResolution">阶次分辨率。</param>
	/// <param name="oversamplingFactor">过采样因子。</param>
	/// <param name="lowerRpmThreshold">转速下限。</param>
	/// <param name="upperRpmThreshold">转速上限。</param>
	/// <param name="rpmStep">转速步进，单位为rpm。</param>
	/// <param name="referenceValue">参考值，仅用于db输出时的参考值。</param>
	/// <param name="formatType">输出格式类型。</param>
	/// <param name="windowType">窗函数类型。</param>
	/// <param name="weightType">加权类型。</param>
	/// <param name="scaleType">缩放类型。</param>
	/// <param name="colormapData">输出参数，指向色谱图数据的指针。</param>
	/// <param name="rpmAxis">输出参数，指向转速轴数据的指针。</param>
	/// <param name="orderAxis">输出参数，指向阶次轴数据的指针。</param>
	/// <param name="rpmBins">输出参数，指向转速分箱数量的指针。</param>
	/// <param name="orderBins">输出参数，指向阶次分箱数量的指针。</param>
	/// <returns>返回1表示成功，其他值表示错误代码。</returns>
	int GenerateRpmOrderColormap(SignalNative signalNative, RpmNative rpmNative, double maxOrder, double orderResolution, double oversamplingFactor, double lowerRpmThreshold, double upperRpmThreshold, double rpmStep, double referenceValue, int formatType, int windowType, int weightType, int scaleType, double** colormapData, double** rpmAxis, double** orderAxis, int* rpmBins, int* orderBins);

	/// <summary>
	/// 12. 振动Crest值
	/// </summary>
	/// <param name="signalNative">输入的信号数据结构体。</param>
	/// <param name="outValue">输出参数，指向Crest值的指针。</param>
	/// <returns>返回1表示成功，其他值表示错误代码。</returns>
	int GetCrestFactor(SignalNative signalNative, double* outValue);

	/// <summary>
	/// 13-1. 创建IIR高通滤波器
	/// </summary>
	/// <param name="sampleRate">信号采样率</param>
	/// <param name="cutoffFrequency">下限截至频率</param>
	/// <param name="filterOrder">滤波器阶数</param>
	/// <param name="outFilterHandle">滤波器句柄</param>
	/// <returns></returns>
	int CreateIirHighpassFilter(double sampleRate, double cutoffFrequency, int filterOrder, void** outFilterHandle);

	/// <summary>
	/// 13-2. 创建IIR低通滤波器
	/// </summary>
	/// <param name="sampleRate"></param>
	/// <param name="cutoffFrequency"></param>
	/// <param name="filterOrder"></param>
	/// <param name="outFilterHandle"></param>
	/// <returns></returns>
	int CreateIirLowpassFilter(double sampleRate, double cutoffFrequency, int filterOrder, void** outFilterHandle);

	/// <summary>
	/// 13-3. 创建IIR带通滤波器
	/// </summary>
	/// <param name="sampleRate"></param>
	/// <param name="lowCutoffFrequency"></param>
	/// <param name="highCutoffFrequency"></param>
	/// <param name="filterOrder"></param>
	/// <param name="outFilterHandle"></param>
	/// <returns></returns>
	int CreateIirBandpassFilter(double sampleRate, double lowCutoffFrequency, double highCutoffFrequency, int filterOrder, void** outFilterHandle);

	/// <summary>
	/// 13-4. 创建FIR高通滤波器
	/// </summary>
	/// <param name="sampleRate">信号采样率</param>
	/// <param name="stopbandFreq">阻带频率</param>
	/// <param name="passbandFreq">通带频率</param>
	/// <param name="taps">滤波器抽头数</param>
	/// <param name="outFilterHandle">滤波器句柄</param>
	/// <returns></returns>
	int CreateFirHighpassFilter(double sampleRate, double stopbandFreq, double passbandFreq, int taps, void** outFilterHandle);

	/// <summary>
	/// 13-5. 创建FIR低通滤波器
	/// </summary>
	/// <param name="sampleRate"></param>
	/// <param name="passbandFreq"></param>
	/// <param name="stopbandFreq"></param>
	/// <param name="taps"></param>
	/// <param name="outFilterHandle"></param>
	/// <returns></returns>
	int CreateFirLowpassFilter(double sampleRate, double passbandFreq, double stopbandFreq, int taps, void** outFilterHandle);

	/// <summary>
	/// 13-6. 创建FIR带通滤波器
	/// </summary>
	/// <param name="sampleRate"></param>
	/// <param name="lowCutoffFrequency"></param>
	/// <param name="highCutoffFrequency"></param>
	/// <param name="taps"></param>
	/// <param name="outFilterHandle"></param>
	/// <returns></returns>
	int CreateFirBandpassFilter(double sampleRate, double lowCutoffFrequency, double highCutoffFrequency, int taps, void** outFilterHandle);

	/// <summary>
	/// 13-7. 应用滤波器
	/// </summary>
	/// <param name="handle">滤波器句柄</param>
	/// <param name="samples">信号点数组</param>
	/// <param name="length">数组长度</param>
	/// <param name="filtered">返回数组</param>
	/// <returns></returns>
	int ApplyFilter(void* handle, double* samples, int length, int samplerate, double** filtered);

	/// <summary>
	/// 13-8. 释放滤波器
	/// </summary>
	/// <param name="handle">滤波器句柄</param>
	/// <returns></returns>
	int FreeFilter(void* handle);

	/// <summary>
	/// 14. 重采样信号
	/// </summary>
	/// <param name="signalNative"></param>
	/// <param name="destSampleRate"></param>
	/// <param name="outSamples"></param>
	/// <param name="outLength"></param>
	/// <returns></returns>
	int ResampleSignal(SignalNative signalNative, double destSampleRate, double bandRatio, double** outSamples, int* outLength);

	/// <summary>
	/// 15. 时频阶次
	/// </summary>
	/// <param name="signalNative"></param>
	/// <param name="rpmNative"></param>
	/// <param name="amplitudeLines"></param>
	/// <param name="valueLength"></param>
	/// <param name="orderAxis"></param>
	/// <param name="orderAxisLen"></param>
	/// <param name="lineCnt"></param>
	/// <param name="formatType"></param>
	/// <param name="weightType"></param>
	/// <param name="scaleType"></param>
	/// <param name="spectralLines"></param>
	/// <param name="increment"></param>
	/// <param name="referenceValue"></param>
	/// <returns></returns>
	int TimeFrequencyDerivedOrder(SignalNative signalNative, RpmNative rpmNative, double** flatAmplitudeValues, int* valueLength, double** orderAxis, int* orderAxisLen, int* lineCnt, int formatType, int windowType, int weightType, int scaleType, int spectralLines, double increment, double referenceValue);

	/// <summary>
	/// 截取信号的指定时间段。
	/// </summary>
	/// <param name="signalNative">输入的信号数据结构体。</param>
	/// <param name="startTime">起始时间，单位为秒。</param>
	/// <param name="endTime">结束时间，单位为秒。</param>
	/// <param name="outSignal">输出参数，指向截取后信号的结构体指针。</param>
	/// <returns>返回1表示成功，其他值表示错误代码。</returns>
	int SignalSlice(SignalNative signalNative, double startTime, double endTime, SignalNative* outSignal);

	/// <summary>
	/// 截取转速的指定时间段。
	/// </summary>
	/// <param name="rpmNative">输入的转速数据结构体。</param>
	/// <param name="startTime">起始时间，单位为秒。</param>
	/// <param name="endTime">结束时间，单位为秒。</param>
	/// <param name="outRpm">输出参数，指向截取后转速的结构体指针。</param>
	/// <returns>返回1表示成功，其他值表示错误代码。</returns>
	int RpmSlice(RpmNative rpmNative, double startTime, double endTime, RpmNative* outRpm);

	/// <summary>
	/// 脉冲信号转转速
	/// </summary>
	/// <param name="signalNative">脉冲信号源</param>
	/// <param name="edgeDetectorNative">边缘检测选项</param>
	/// <param name="rpmCalculationOptionsNative">转速计算选项</param>
	/// <param name="outRpm">转速输出</param>
	/// <returns>返回1表示成功，其他值表示错误代码。</returns>
	int PulseToRpm(SignalNative signalNative, EdgeDetectorNative edgeDetectorNative, RpmCalculationOptionsNative rpmCalculationOptionsNative, RpmNative* outRpm);

	/// <summary>
	/// 加载许可证字符串并验证其有效性。
	/// </summary>
	/// <param name="license">指向许可证字符串的指针。</param>
	/// <returns>如果许可证加载和验证成功，则返回1；否则返回0。</returns>
	int LoadLicense(const char* license);

	/// <summary>
	/// 获取最后一次错误的错误消息。
	/// </summary>
	/// <param name="errorCode">错误码。</param>
	/// <returns>返回错误消息字符串。</returns>
	const char* GetLastErrorMessage(int errorCode);

	/// <summary>
	/// 释放由指针 ptr 指向的内存资源。
	/// </summary>
	/// <param name="ptr">指向需要释放的内存块的指针。</param>
	/// <returns>如果释放成功，返回 0；否则返回非零值表示错误。</returns>
	int Free(void* ptr);

#ifdef __cplusplus
}
#endif#endif
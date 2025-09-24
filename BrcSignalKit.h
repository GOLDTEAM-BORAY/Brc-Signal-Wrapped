#pragma once

#ifdef __cplusplus
extern "C" {
#endif
	/// <summary>
	/// 平均谱算法
	/// </summary>
	/// <param name="signalNative">信号结构体描述</param>
	/// <param name="duration">计算信号时间长度</param>
	/// <param name="spectrumLines">谱线数</param>
	/// <param name="increment">帧移时间</param>
	/// <param name="formatType">格式类型 0-RMS 1-Peak 2-PeakToPeak</param>
	/// <param name="averageType">平均类型 0-Energy(能量平均) 1-Mean(算数平均) 2-Max(最大值平均)</param>
	/// <param name="weightType">加权类型 0-无 1-A计权 2-B计权 3-C计权</param>
	/// <param name="windowType">窗函数类型 0-矩形窗 1-汉宁窗</param>
	/// <param name="normalize">是否归一化</param>
	/// <param name="outLength">信号数组长度</param>
	/// <returns>信号数组</returns>
	int AveragedSpectrumByIncrement(SignalNative signalNative, double duration, int spectrumLines, double increment, int formatType, int averageType, int weightType, int windowType, bool normalize, double** outSpectrum, int* outLength);

	/// <summary>
	/// 计算阶次色谱图
	/// </summary>
	/// <param name="signalNative">信号结构体描述</param>
	/// <param name="rpmNative">转速</param>
	/// <param name="maxOrder">最大阶次</param>
	/// <param name="orderResolution">阶次分辨率</param>
	/// <param name="rpmStep">转速步长</param>
	/// <param name="formatType">格式类型 0-RMS 1-Peak 2-PeakToPeak</param>
	/// <param name="windowType">窗函数类型 0-矩形窗 1-汉宁窗</param>
	/// <param name="scaleType">频率轴类型 0-线性 1-对数</param>
	/// <param name="colormapData">返回阶次数据</param>
	/// <param name="orderBins">阶次轴分段数</param>
	/// <param name="rpmBins">转速轴分段数</param>
	/// <returns></returns>
	int GenerateOrderRpmColormap(SignalNative signalNative, RpmNative rpmNative, double maxOrder, double orderResolution, int rpmStep, int formatType, int windowType, int scaleType, double** colormapData, int* orderBins, int* rpmBins);

	/// <summary>
	/// 计算时间频率色谱图
	/// </summary>
	/// <param name="signalNative">信号结构体描述</param>
	/// <param name="signalType">信号类型 0-声学信号 1-振动信号</param>
	/// <param name="formatType">格式类型 0-RMS 1-Peak 2-PeakToPeak</param>
	/// <param name="windowType">窗函数类型 0-矩形窗 1-汉宁窗</param>
	/// <param name="weightType">加权类型 0-无 1-A计权 2-B计权 3-C计权</param>
	/// <param name="scaleType">频率轴类型 0-线性 1-对数</param>
	/// <param name="spectrumLines">谱线数</param>
	/// <param name="overlap">重叠率</param>
	/// <param name="startTime">开始时间</param>
	/// <param name="endTime">结束时间。 -1.0代表信号的结束时间</param>
	/// <param name="colormapData">色谱图返回数据</param>
	/// <param name="timeBins">时间轴分段数</param>
	/// <param name="frequencyBins">频率轴分段数</param>
	/// <returns></returns>
	int GenerateTimeFrequencyColormapByOverlap(SignalNative signalNative, int signalType, int formatType, int windowType, int weightType, int scaleType, int spectrumLines, double overlap, double startTime, double endTime, double** colormapData, int* timeBins, int* frequencyBins);

	/// <summary>
	/// 计算时间频率色谱图
	/// </summary>
	/// <param name="signalNative">信号结构体描述</param>
	/// <param name="signalType">信号类型 0-声学信号 1-振动信号</param>
	/// <param name="formatType">格式类型 0-RMS 1-Peak 2-PeakToPeak</param>
	/// <param name="windowType">窗函数类型 0-矩形窗 1-汉宁窗</param>
	/// <param name="weightType">加权类型 0-无 1-A计权 2-B计权 3-C计权</param>
	/// <param name="scaleType">频率轴类型 0-线性 1-对数</param>
	/// <param name="spectrumLines">谱线数</param>
	/// <param name="increment">帧移时间</param>
	/// <param name="startTime">开始时间</param>
	/// <param name="endTime">结束时间。 -1.0代表信号的结束时间</param>
	/// <param name="colormapData">色谱图返回数据</param>
	/// <param name="timeBins">时间轴分段数</param>
	/// <param name="frequencyBins">频率轴分段数</param>
	/// <returns></returns>
	int GenerateTimeFrequencyColormapByIncrement(SignalNative signalNative, int signalType, int formatType, int windowType, int weightType, int scaleType, int spectrumLines, double increment, double startTime, double endTime, double** colormapData, int* timeBins, int* frequencyBins);

	/// <summary>
	/// 计算转速频率色谱图
	/// </summary>
	/// <param name="signalNative">信号结构体描述</param>
	/// <param name="rpmNative">转速结构体描述</param>
	/// <param name="formatType">格式类型 0-RMS 1-Peak 2-PeakToPeak</param>
	/// <param name="windowType">窗函数类型 0-矩形窗 1-汉宁窗</param>
	/// <param name="scaleType">频率轴类型 0-线性 1-对数</param>
	/// <param name="spectrumLines">谱线数</param>
	/// <param name="lowerRpmThreshold">转速轴起始转速</param>
	/// <param name="upperRpmThreshold">转速轴终止转速。-1.0代表信号的最大转速</param>
	/// <param name="rpmStep">转速步长</param>
	/// <param name="colormapData">色谱图返回数据</param>
	/// <param name="rpmBins">转速轴分段数</param>
	/// <param name="frequencyBins">频率轴分段数</param>
	/// <returns></returns>
	int GenerateRpmFrequencyColormap(SignalNative signalNative, RpmNative rpmNative, int signalType, int formatType, int windowType, int weightType, int scaleType, int spectrumLines, double lowerRpmThreshold, double upperRpmThreshold, double rpmStep, double** colormapData, double** rpmData, double** freqData, int* rpmBins, int* frequencyBins);

	/// <summary>
	/// 计算OA曲线
	/// </summary>
	/// <param name="signalNative">信号结构体描述</param>
	/// <param name="signalType">信号类型 0-声学信号 1-振动信号</param>
	/// <param name="duration">计算信号时间长度</param>
	/// <param name="spectrumLines">谱线数</param>
	/// <param name="increment">帧移时间</param>
	/// <param name="windowType">窗函数类型 0-矩形窗 1-汉宁窗</param>
	/// <param name="weightType">加权类型 0-无 1-A计权 2-B计权 3-C计权</param>
	/// <param name="levelData">返回OA数据</param>
	/// <param name="timeBins">时间轴分段数</param>
	/// <returns></returns>
	int OverallLevelSpectral(SignalNative signalNative, int signalType, double duration, int spectrumLines, double increment, int windowType, int weightType, int scaleType, double** levelData, int* timeBins);

	/// <summary>
	/// 计算平均谱倍频程
	/// </summary>
	/// <param name="signalNative">信号结构体描述</param>
	/// <param name="duration">计算信号时间长度</param>
	/// <param name="spectrumLines">谱线数</param>
	/// <param name="increment">帧移时间</param>
	/// <param name="foramtType">格式类型 0-RMS 1-Peak 2-PeakToPeak</param>
	/// <param name="octaveType">倍频程类型：0-1倍 1-1/3倍频程 2-1/6倍频程 3-1/12倍频程 4-1/24倍频程</param>
	/// <param name="averageType">平均方法 0-Energy(能量平均) 1-Mean(算数平均) 2-Max(最大值平均)</param>
	/// <param name="windowType">窗函数</param>
	/// <param name="scaleType">Y轴类型 0-线性 1-对数</param>
	/// <param name="weightType">计权类型</param>
	/// <param name="lowerFreq">输出的中心频率下限</param>
	/// <param name="upperFreq">输出的中心频率上限</param>
	/// <param name="levelData">返回 倍频程数据</param>
	/// <param name="centerFreqs">返回 中心频率点序列</param>
	/// <param name="lowerFreqs">返回 频带起始频率点序列</param>
	/// <param name="upperFreqs">返回 频带终止频率点序列</param>
	/// <param name="levelBins">频带分段数</param>
	/// <returns></returns>
	int AveragedOctaveBandLevels(SignalNative signalNative, double duration, int spectrumLines, double increment, int foramtType, int octaveType, int averageType, int windowType, int scaleType, int weightType, double lowerFreq, double upperFreq, double** levelData, double** centerFreqs, double** lowerFreqs, double** upperFreqs, int* levelBins);

	/// <summary>
	/// 阶次切片
	/// </summary>
	/// <param name="signalNative">信号结构体描述</param>
	/// <param name="rpmNative">转速结构体描述</param>
	/// <param name="signalType">信号类型 0-声学信号 1-振动信号</param>
	/// <param name="windowType">窗函数类型 0-矩形窗 1-汉宁窗</param>
	/// <param name="weightType">加权类型 0-无 1-A计权 2-B计权 3-C计权</param>
	/// <param name="scaleType">Y轴类型 0-线性 1-对数</param>
	/// <param name="specturmLines">谱线数</param>
	/// <param name="targetOrder">目标切片阶次</param>
	/// <param name="orderBandwidth">切片带宽</param>
	/// <param name="rpmStep">转速轴分段步长</param>
	/// <param name="outOrderSection">阶次切片结果</param>
	/// <param name="outRpmPoints">转速轴</param>
	/// <param name="rpmBins">转速轴线数</param>
	/// <returns></returns>
	int OrderSection(SignalNative signalNative, RpmNative rpmNative, int signalType, int windowType, int weightType, int scaleType, int specturmLines, double targetOrder, double orderBandwidth, double rpmStep, double** outOrderSection, double** outRpmPoints, int* rpmBins);
	
	/// <summary>
	/// 
	/// </summary>
	/// <param name="signalNative"></param>
	/// <param name="startTime"></param>
	/// <param name="endTime"></param>
	/// <param name="outSignal"></param>
	/// <returns></returns>
	int SignalSlice(SignalNative signalNative, double startTime, double endTime, SignalNative* outSignal);

	/// <summary>
	/// 
	/// </summary>
	/// <param name="rpmNative"></param>
	/// <param name="startTime"></param>
	/// <param name="endTime"></param>
	/// <param name="outRpm"></param>
	/// <returns></returns>
	int RpmSlice(RpmNative rpmNative, double startTime, double endTime, RpmNative* outRpm);

	/// <summary>
	/// 脉冲信号转转速
	/// </summary>
	/// <param name="signalNative">脉冲信号源</param>
	/// <param name="edgeDetectorNative">边缘检测选项</param>
	/// <param name="rpmCalculationOptionsNative">转速计算选项</param>
	/// <param name="outRpm">转速输出</param>
	/// <returns></returns>
	int PulseToRpm(SignalNative signalNative, EdgeDetectorNative edgeDetectorNative, RpmCalculationOptionsNative rpmCalculationOptionsNative, RpmNative* outRpm);

	/// <summary>
	/// 加载许可证字符串并验证其有效性。
	/// </summary>
	/// <param name="license">指向许可证字符串的指针。</param>
	/// <returns>如果许可证加载和验证成功，则返回 true；否则返回 false。</returns>
	int LoadLicense(const char* license);

	/// <summary>
	/// 获取最后一次错误的错误消息。
	/// </summary>
	/// <returns></returns>
	const char* GetLastErrorMessage(int errorCode);

#ifdef __cplusplus
}
#endif
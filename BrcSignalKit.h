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
	/// <param name="averageType">平均类型 0-Energy(能量平均) 1-Mean(算数平均) 2-Max(最大值平均)</param>
	/// <param name="weightType">加权类型 0-无 1-A计权 2-B计权 3-C计权</param>
	/// <param name="windowType">窗函数类型 0-矩形窗 1-汉宁窗</param>
	/// <param name="normalize">是否归一化</param>
	/// <param name="outLength">信号数组长度</param>
	/// <returns>信号数组</returns>
	int AveragedSpectrumByIncrement(SignalNative signalNative, double duration, int spectrumLines, double increment, int averageType, int weightType, int windowType, bool normalize, double** outSpectrum, int* outLength);

	/// <summary>
	/// 计算阶次色谱图
	/// </summary>
	/// <param name="signalNative">信号结构体描述</param>
	/// <param name="rpmNative">转速</param>
	/// <param name="maxOrder">最大阶次</param>
	/// <param name="orderResolution">阶次分辨率</param>
	/// <param name="rpmStep">转速步长</param>
	/// <param name="windowType">窗函数类型 0-矩形窗 1-汉宁窗</param>
	/// <param name="colormapData">返回阶次数据</param>
	/// <param name="orderBins">阶次轴分段数</param>
	/// <param name="rpmBins">转速轴分段数</param>
	/// <returns></returns>
	int GenerateOrderColormap(SignalNative signalNative, RpmNative rpmNative, double maxOrder, double orderResolution, int rpmStep, int windowType, double** colormapData, int* orderBins, int* rpmBins);

	/// <summary>
	/// 计算时间频率色谱图
	/// </summary>
	/// <param name="signalNative">信号结构体描述</param>
	/// <param name="windowType">窗函数类型 0-矩形窗 1-汉宁窗</param>
	/// <param name="spectrumLines">谱线数</param>
	/// <param name="overlap">重叠率</param>
	/// <param name="startTime">开始时间</param>
	/// <param name="endTime">结束时间。 -1.0代表信号的结束时间</param>
	/// <param name="colormapData">色谱图返回数据</param>
	/// <param name="timeBins">时间轴分段数</param>
	/// <param name="frequencyBins">频率轴分段数</param>
	/// <returns></returns>
	int GenerateTimeFrequencyColormap(SignalNative signalNative, int windowType, int spectrumLines, double overlap, double startTime, double endTime, double** colormapData, int* timeBins, int* frequencyBins);

	/// <summary>
	/// 计算转速频率色谱图
	/// </summary>
	/// <param name="signalNative">信号结构体描述</param>
	/// <param name="rpmNative">转速结构体描述</param>
	/// <param name="windowType">窗函数类型 0-矩形窗 1-汉宁窗</param>
	/// <param name="spectrumLines">谱线数</param>
	/// <param name="overlap">重叠率</param>
	/// <param name="lowerRpmThreshold">转速轴起始转速</param>
	/// <param name="upperRpmThreshold">转速轴终止转速。-1.0代表信号的最大转速</param>
	/// <param name="colormapData">色谱图返回数据</param>
	/// <param name="rpmBins">转速轴分段数</param>
	/// <param name="frequencyBins">频率轴分段数</param>
	/// <returns></returns>
	int GenerateRpmFrequencyColormap(SignalNative signalNative, RpmNative rpmNative, int windowType, int spectrumLines, double overlap, double lowerRpmThreshold, double upperRpmThreshold, double** colormapData, int* rpmBins, int* frequencyBins);
	
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
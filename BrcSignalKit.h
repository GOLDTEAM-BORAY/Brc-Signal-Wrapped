#pragma once

#ifdef __cplusplus
extern "C" {
#endif
	/// <summary>
	/// ƽ�����㷨
	/// </summary>
	/// <param name="signalNative">�źŽṹ������</param>
	/// <param name="duration">�����ź�ʱ�䳤��</param>
	/// <param name="spectrumLines">������</param>
	/// <param name="increment">֡��ʱ��</param>
	/// <param name="averageType">ƽ������ 0-Energy(����ƽ��) 1-Mean(����ƽ��) 2-Max(���ֵƽ��)</param>
	/// <param name="weightType">��Ȩ���� 0-�� 1-A��Ȩ 2-B��Ȩ 3-C��Ȩ</param>
	/// <param name="windowType">���������� 0-���δ� 1-������</param>
	/// <param name="normalize">�Ƿ��һ��</param>
	/// <param name="outLength">�ź����鳤��</param>
	/// <returns>�ź�����</returns>
	int AveragedSpectrumByIncrement(SignalNative signalNative, double duration, int spectrumLines, double increment, int averageType, int weightType, int windowType, bool normalize, double** outSpectrum, int* outLength);

	/// <summary>
	/// ����״�ɫ��ͼ
	/// </summary>
	/// <param name="signalNative">�źŽṹ������</param>
	/// <param name="rpmNative">ת��</param>
	/// <param name="maxOrder">���״�</param>
	/// <param name="orderResolution">�״ηֱ���</param>
	/// <param name="rpmStep">ת�ٲ���</param>
	/// <param name="windowType">�Ӵ�����</param>
	/// <param name="colormapData">���ؽ״�����</param>
	/// <param name="orderBins">�״���ֶ���</param>
	/// <param name="rpmBins">ת����ֶ���</param>
	/// <returns></returns>
	int GenerateOrderColormap(SignalNative signalNative, RpmNative rpmNative, double maxOrder, double orderResolution, int rpmStep, int windowType, double** colormapData, int* orderBins, int* rpmBins);

	/// <summary>
	/// ����ʱ��Ƶ��ɫ��ͼ
	/// </summary>
	/// <param name="signalNative"></param>
	/// <param name="rpmNative"></param>
	/// <param name="windowType"></param>
	/// <param name="spectrumLines"></param>
	/// <param name="overlap"></param>
	/// <param name="startTime"></param>
	/// <param name="endTime"></param>
	/// <param name="colormapData"></param>
	/// <param name="timeBins"></param>
	/// <param name="frequencyBins"></param>
	/// <returns></returns>
	int GenerateTimeFrequencyColormap(SignalNative signalNative, RpmNative rpmNative, int windowType, int spectrumLines, double overlap, double startTime, double endTime, double** colormapData, int* timeBins, int* frequencyBins);

	/// <summary>
	/// ����ת��Ƶ��ɫ��ͼ
	/// </summary>
	/// <param name="signalNative"></param>
	/// <param name="rpmNative"></param>
	/// <param name="windowType"></param>
	/// <param name="spectrumLines"></param>
	/// <param name="overlap"></param>
	/// <param name="lowerRpmThreshold"></param>
	/// <param name="upperRpmThreshold"></param>
	/// <param name="colormapData"></param>
	/// <param name="rpmBins"></param>
	/// <param name="frequencyBins"></param>
	/// <returns></returns>
	int GenerateRpmFrequencyColormap(SignalNative signalNative, RpmNative rpmNative, int windowType, int spectrumLines, double overlap, double lowerRpmThreshold, double upperRpmThreshold, double** colormapData, int* rpmBins, int* frequencyBins);
	
	/// <summary>
	/// �������֤�ַ�������֤����Ч�ԡ�
	/// </summary>
	/// <param name="license">ָ�����֤�ַ�����ָ�롣</param>
	/// <returns>������֤���غ���֤�ɹ����򷵻� true�����򷵻� false��</returns>
	int LoadLicense(const char* license);

#ifdef __cplusplus
}
#endif
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
	/// <param name="windowType">���������� 0-���δ� 1-������</param>
	/// <param name="colormapData">���ؽ״�����</param>
	/// <param name="orderBins">�״���ֶ���</param>
	/// <param name="rpmBins">ת����ֶ���</param>
	/// <returns></returns>
	int GenerateOrderColormap(SignalNative signalNative, RpmNative rpmNative, double maxOrder, double orderResolution, int rpmStep, int windowType, double** colormapData, int* orderBins, int* rpmBins);

	/// <summary>
	/// ����ʱ��Ƶ��ɫ��ͼ
	/// </summary>
	/// <param name="signalNative">�źŽṹ������</param>
	/// <param name="windowType">���������� 0-���δ� 1-������</param>
	/// <param name="spectrumLines">������</param>
	/// <param name="overlap">�ص���</param>
	/// <param name="startTime">��ʼʱ��</param>
	/// <param name="endTime">����ʱ�䡣 -1.0�����źŵĽ���ʱ��</param>
	/// <param name="colormapData">ɫ��ͼ��������</param>
	/// <param name="timeBins">ʱ����ֶ���</param>
	/// <param name="frequencyBins">Ƶ����ֶ���</param>
	/// <returns></returns>
	int GenerateTimeFrequencyColormapByOverlap(SignalNative signalNative, int windowType, int spectrumLines, double overlap, double startTime, double endTime, double** colormapData, int* timeBins, int* frequencyBins);

	/// <summary>
	/// ����ʱ��Ƶ��ɫ��ͼ
	/// </summary>
	/// <param name="signalNative">�źŽṹ������</param>
	/// <param name="windowType">���������� 0-���δ� 1-������</param>
	/// <param name="spectrumLines">������</param>
	/// <param name="increment">֡��ʱ��</param>
	/// <param name="startTime">��ʼʱ��</param>
	/// <param name="endTime">����ʱ�䡣 -1.0�����źŵĽ���ʱ��</param>
	/// <param name="colormapData">ɫ��ͼ��������</param>
	/// <param name="timeBins">ʱ����ֶ���</param>
	/// <param name="frequencyBins">Ƶ����ֶ���</param>
	/// <returns></returns>
	int GenerateTimeFrequencyColormapByIncrement(SignalNative signalNative, int windowType, int spectrumLines, double increment, double startTime, double endTime, double** colormapData, int* timeBins, int* frequencyBins);

	/// <summary>
	/// ����ת��Ƶ��ɫ��ͼ
	/// </summary>
	/// <param name="signalNative">�źŽṹ������</param>
	/// <param name="rpmNative">ת�ٽṹ������</param>
	/// <param name="windowType">���������� 0-���δ� 1-������</param>
	/// <param name="spectrumLines">������</param>
	/// <param name="lowerRpmThreshold">ת������ʼת��</param>
	/// <param name="upperRpmThreshold">ת������ֹת�١�-1.0�����źŵ����ת��</param>
	/// <param name="rpmStep">ת�ٲ���</param>
	/// <param name="colormapData">ɫ��ͼ��������</param>
	/// <param name="rpmBins">ת����ֶ���</param>
	/// <param name="frequencyBins">Ƶ����ֶ���</param>
	/// <returns></returns>
	int GenerateRpmFrequencyColormap(SignalNative signalNative, RpmNative rpmNative, int windowType, int spectrumLines, double lowerRpmThreshold, double upperRpmThreshold, double rpmStep, double** colormapData, int* rpmBins, int* frequencyBins);

	/// <summary>
	/// ����OA����
	/// </summary>
	/// <param name="signalNative">�źŽṹ������</param>
	/// <param name="duration">�����ź�ʱ�䳤��</param>
	/// <param name="spectrumLines">������</param>
	/// <param name="increment">֡��ʱ��</param>
	/// <param name="windowType">���������� 0-���δ� 1-������</param>
	/// <param name="weightType">��Ȩ���� 0-�� 1-A��Ȩ 2-B��Ȩ 3-C��Ȩ</param>
	/// <param name="levelData">����OA����</param>
	/// <param name="timeBins">ʱ����ֶ���</param>
	/// <returns></returns>
	int OverallSoundPressureLevelSpectral(SignalNative signalNative, double duration, int spectrumLines, double increment, int windowType, int weightType, double** levelData, int* timeBins);
	
	/// <summary>
	/// �������֤�ַ�������֤����Ч�ԡ�
	/// </summary>
	/// <param name="license">ָ�����֤�ַ�����ָ�롣</param>
	/// <returns>������֤���غ���֤�ɹ����򷵻� true�����򷵻� false��</returns>
	int LoadLicense(const char* license);

	/// <summary>
	/// ��ȡ���һ�δ���Ĵ�����Ϣ��
	/// </summary>
	/// <returns></returns>
	const char* GetLastErrorMessage(int errorCode);

#ifdef __cplusplus
}
#endif
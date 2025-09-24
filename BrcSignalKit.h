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
	/// <param name="formatType">��ʽ���� 0-RMS 1-Peak 2-PeakToPeak</param>
	/// <param name="averageType">ƽ������ 0-Energy(����ƽ��) 1-Mean(����ƽ��) 2-Max(���ֵƽ��)</param>
	/// <param name="weightType">��Ȩ���� 0-�� 1-A��Ȩ 2-B��Ȩ 3-C��Ȩ</param>
	/// <param name="windowType">���������� 0-���δ� 1-������</param>
	/// <param name="normalize">�Ƿ��һ��</param>
	/// <param name="outLength">�ź����鳤��</param>
	/// <returns>�ź�����</returns>
	int AveragedSpectrumByIncrement(SignalNative signalNative, double duration, int spectrumLines, double increment, int formatType, int averageType, int weightType, int windowType, bool normalize, double** outSpectrum, int* outLength);

	/// <summary>
	/// ����״�ɫ��ͼ
	/// </summary>
	/// <param name="signalNative">�źŽṹ������</param>
	/// <param name="rpmNative">ת��</param>
	/// <param name="maxOrder">���״�</param>
	/// <param name="orderResolution">�״ηֱ���</param>
	/// <param name="rpmStep">ת�ٲ���</param>
	/// <param name="formatType">��ʽ���� 0-RMS 1-Peak 2-PeakToPeak</param>
	/// <param name="windowType">���������� 0-���δ� 1-������</param>
	/// <param name="scaleType">Ƶ�������� 0-���� 1-����</param>
	/// <param name="colormapData">���ؽ״�����</param>
	/// <param name="orderBins">�״���ֶ���</param>
	/// <param name="rpmBins">ת����ֶ���</param>
	/// <returns></returns>
	int GenerateOrderRpmColormap(SignalNative signalNative, RpmNative rpmNative, double maxOrder, double orderResolution, int rpmStep, int formatType, int windowType, int scaleType, double** colormapData, int* orderBins, int* rpmBins);

	/// <summary>
	/// ����ʱ��Ƶ��ɫ��ͼ
	/// </summary>
	/// <param name="signalNative">�źŽṹ������</param>
	/// <param name="signalType">�ź����� 0-��ѧ�ź� 1-���ź�</param>
	/// <param name="formatType">��ʽ���� 0-RMS 1-Peak 2-PeakToPeak</param>
	/// <param name="windowType">���������� 0-���δ� 1-������</param>
	/// <param name="weightType">��Ȩ���� 0-�� 1-A��Ȩ 2-B��Ȩ 3-C��Ȩ</param>
	/// <param name="scaleType">Ƶ�������� 0-���� 1-����</param>
	/// <param name="spectrumLines">������</param>
	/// <param name="overlap">�ص���</param>
	/// <param name="startTime">��ʼʱ��</param>
	/// <param name="endTime">����ʱ�䡣 -1.0�����źŵĽ���ʱ��</param>
	/// <param name="colormapData">ɫ��ͼ��������</param>
	/// <param name="timeBins">ʱ����ֶ���</param>
	/// <param name="frequencyBins">Ƶ����ֶ���</param>
	/// <returns></returns>
	int GenerateTimeFrequencyColormapByOverlap(SignalNative signalNative, int signalType, int formatType, int windowType, int weightType, int scaleType, int spectrumLines, double overlap, double startTime, double endTime, double** colormapData, int* timeBins, int* frequencyBins);

	/// <summary>
	/// ����ʱ��Ƶ��ɫ��ͼ
	/// </summary>
	/// <param name="signalNative">�źŽṹ������</param>
	/// <param name="signalType">�ź����� 0-��ѧ�ź� 1-���ź�</param>
	/// <param name="formatType">��ʽ���� 0-RMS 1-Peak 2-PeakToPeak</param>
	/// <param name="windowType">���������� 0-���δ� 1-������</param>
	/// <param name="weightType">��Ȩ���� 0-�� 1-A��Ȩ 2-B��Ȩ 3-C��Ȩ</param>
	/// <param name="scaleType">Ƶ�������� 0-���� 1-����</param>
	/// <param name="spectrumLines">������</param>
	/// <param name="increment">֡��ʱ��</param>
	/// <param name="startTime">��ʼʱ��</param>
	/// <param name="endTime">����ʱ�䡣 -1.0�����źŵĽ���ʱ��</param>
	/// <param name="colormapData">ɫ��ͼ��������</param>
	/// <param name="timeBins">ʱ����ֶ���</param>
	/// <param name="frequencyBins">Ƶ����ֶ���</param>
	/// <returns></returns>
	int GenerateTimeFrequencyColormapByIncrement(SignalNative signalNative, int signalType, int formatType, int windowType, int weightType, int scaleType, int spectrumLines, double increment, double startTime, double endTime, double** colormapData, int* timeBins, int* frequencyBins);

	/// <summary>
	/// ����ת��Ƶ��ɫ��ͼ
	/// </summary>
	/// <param name="signalNative">�źŽṹ������</param>
	/// <param name="rpmNative">ת�ٽṹ������</param>
	/// <param name="formatType">��ʽ���� 0-RMS 1-Peak 2-PeakToPeak</param>
	/// <param name="windowType">���������� 0-���δ� 1-������</param>
	/// <param name="scaleType">Ƶ�������� 0-���� 1-����</param>
	/// <param name="spectrumLines">������</param>
	/// <param name="lowerRpmThreshold">ת������ʼת��</param>
	/// <param name="upperRpmThreshold">ת������ֹת�١�-1.0�����źŵ����ת��</param>
	/// <param name="rpmStep">ת�ٲ���</param>
	/// <param name="colormapData">ɫ��ͼ��������</param>
	/// <param name="rpmBins">ת����ֶ���</param>
	/// <param name="frequencyBins">Ƶ����ֶ���</param>
	/// <returns></returns>
	int GenerateRpmFrequencyColormap(SignalNative signalNative, RpmNative rpmNative, int signalType, int formatType, int windowType, int weightType, int scaleType, int spectrumLines, double lowerRpmThreshold, double upperRpmThreshold, double rpmStep, double** colormapData, double** rpmData, double** freqData, int* rpmBins, int* frequencyBins);

	/// <summary>
	/// ����OA����
	/// </summary>
	/// <param name="signalNative">�źŽṹ������</param>
	/// <param name="signalType">�ź����� 0-��ѧ�ź� 1-���ź�</param>
	/// <param name="duration">�����ź�ʱ�䳤��</param>
	/// <param name="spectrumLines">������</param>
	/// <param name="increment">֡��ʱ��</param>
	/// <param name="windowType">���������� 0-���δ� 1-������</param>
	/// <param name="weightType">��Ȩ���� 0-�� 1-A��Ȩ 2-B��Ȩ 3-C��Ȩ</param>
	/// <param name="levelData">����OA����</param>
	/// <param name="timeBins">ʱ����ֶ���</param>
	/// <returns></returns>
	int OverallLevelSpectral(SignalNative signalNative, int signalType, double duration, int spectrumLines, double increment, int windowType, int weightType, int scaleType, double** levelData, int* timeBins);

	/// <summary>
	/// ����ƽ���ױ�Ƶ��
	/// </summary>
	/// <param name="signalNative">�źŽṹ������</param>
	/// <param name="duration">�����ź�ʱ�䳤��</param>
	/// <param name="spectrumLines">������</param>
	/// <param name="increment">֡��ʱ��</param>
	/// <param name="foramtType">��ʽ���� 0-RMS 1-Peak 2-PeakToPeak</param>
	/// <param name="octaveType">��Ƶ�����ͣ�0-1�� 1-1/3��Ƶ�� 2-1/6��Ƶ�� 3-1/12��Ƶ�� 4-1/24��Ƶ��</param>
	/// <param name="averageType">ƽ������ 0-Energy(����ƽ��) 1-Mean(����ƽ��) 2-Max(���ֵƽ��)</param>
	/// <param name="windowType">������</param>
	/// <param name="scaleType">Y������ 0-���� 1-����</param>
	/// <param name="weightType">��Ȩ����</param>
	/// <param name="lowerFreq">���������Ƶ������</param>
	/// <param name="upperFreq">���������Ƶ������</param>
	/// <param name="levelData">���� ��Ƶ������</param>
	/// <param name="centerFreqs">���� ����Ƶ�ʵ�����</param>
	/// <param name="lowerFreqs">���� Ƶ����ʼƵ�ʵ�����</param>
	/// <param name="upperFreqs">���� Ƶ����ֹƵ�ʵ�����</param>
	/// <param name="levelBins">Ƶ���ֶ���</param>
	/// <returns></returns>
	int AveragedOctaveBandLevels(SignalNative signalNative, double duration, int spectrumLines, double increment, int foramtType, int octaveType, int averageType, int windowType, int scaleType, int weightType, double lowerFreq, double upperFreq, double** levelData, double** centerFreqs, double** lowerFreqs, double** upperFreqs, int* levelBins);

	/// <summary>
	/// �״���Ƭ
	/// </summary>
	/// <param name="signalNative">�źŽṹ������</param>
	/// <param name="rpmNative">ת�ٽṹ������</param>
	/// <param name="signalType">�ź����� 0-��ѧ�ź� 1-���ź�</param>
	/// <param name="windowType">���������� 0-���δ� 1-������</param>
	/// <param name="weightType">��Ȩ���� 0-�� 1-A��Ȩ 2-B��Ȩ 3-C��Ȩ</param>
	/// <param name="scaleType">Y������ 0-���� 1-����</param>
	/// <param name="specturmLines">������</param>
	/// <param name="targetOrder">Ŀ����Ƭ�״�</param>
	/// <param name="orderBandwidth">��Ƭ����</param>
	/// <param name="rpmStep">ת����ֶβ���</param>
	/// <param name="outOrderSection">�״���Ƭ���</param>
	/// <param name="outRpmPoints">ת����</param>
	/// <param name="rpmBins">ת��������</param>
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
	/// �����ź�תת��
	/// </summary>
	/// <param name="signalNative">�����ź�Դ</param>
	/// <param name="edgeDetectorNative">��Ե���ѡ��</param>
	/// <param name="rpmCalculationOptionsNative">ת�ټ���ѡ��</param>
	/// <param name="outRpm">ת�����</param>
	/// <returns></returns>
	int PulseToRpm(SignalNative signalNative, EdgeDetectorNative edgeDetectorNative, RpmCalculationOptionsNative rpmCalculationOptionsNative, RpmNative* outRpm);

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
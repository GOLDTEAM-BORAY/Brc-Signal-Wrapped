#pragma once
#include "Types.h"
#include "FileReader.h"

#ifdef __cplusplus
extern "C" {
#endif
	/// <summary>
	/// 1-1. ��ѹ�ܼ�
	/// </summary>
	/// <param name="signalNative">������ź����ݽṹ�塣</param>
	/// <param name="spectrumLines">������������Ƶ�׷ֱ��ʡ�</param>
	/// <param name="increment">������������λΪ�롣</param>
	/// <param name="referenceValue">�ο�ֵ��������db���ʱ�Ĳο�ֵ��</param>
	/// <param name="windowType">���������� 0-���δ� 1-Hanning��</param>
	/// <param name="weightType">��Ȩ���� 0-A��Ȩ 1-B��Ȩ 2-C��Ȩ</param>
	/// <param name="scaleType">�������� 0-������� 1-DB���</param>
	/// <param name="levelData">���������ָ�����õ�����ѹ�����ݵ�ָ�롣</param>
	/// <param name="timeBins">���������ָ��ʱ�������ָ�롣</param>
	/// <returns>����1��ʾ�ɹ�������ֵ��ʾ������롣</returns>
	int OverallLevelSpectral(SignalNative signalNative, int spectrumLines, double increment, double referenceValue, int windowType, int weightType, int scaleType, double** levelData, int* timeBins);

	/// <summary>
	/// 1-2. ��ѹ�ܼ�-����ת��
	/// </summary>
	/// <param name="signalNative">������ź����ݽṹ�塣</param>
	/// <param name="rpmNative">������ź����ݽṹ�塣</param>
	/// <param name="spectrumLines">������������Ƶ�׷ֱ��ʡ�</param>
	/// <param name="lowerRpmThreshold">ת�����ޣ�=0ʱȡת���źŵ���Сת��</param>
	/// <param name="upperRpmThreshold">ת�����ߣ�=-1ʱȡת���źŵ����ת��</param>
	/// <param name="rpmStep">ת�ٲ���</param>
	/// <param name="referenceValue">DB�ο�ֵ</param>
	/// <param name="windowType">���������� 0-���δ� 1-Hanning��</param>
	/// <param name="weightType">��Ȩ���� 0-A��Ȩ 1-B��Ȩ 2-C��Ȩ</param>
	/// <param name="scaleType">�������� 0-������� 1-DB���<</param>
	/// <param name="levelData">���������ָ�����õ�����ѹ�����ݵ�ָ�롣</param>
	/// <param name="rpmBins">���������ָ��ת�ٷ�����ָ�롣</param>
	/// <returns>����1��ʾ�ɹ�������ֵ��ʾ������롣</returns>
	int OverallLevelSpectralTacho(SignalNative signalNative, RpmNative rpmNative, int spectrumLines, double lowerRpmThreshold, double upperRpmThreshold, double rpmStep, double referenceValue, int windowType, int weightType, int scaleType, double** levelData, double** rpmData, int* rpmBins);

	/// <summary>
	/// 2. �״��𶯺�����
	/// </summary>
	/// <param name="signalNative">������ź����ݽṹ�塣</param>
	/// <param name="rpmNative">�����ת�����ݽṹ�塣</param>
	/// <param name="specturmLines">�������������״ηֱ��ʡ�</param>
	/// <param name="targetOrder">Ŀ��״Ρ�</param>
	/// <param name="orderBandwidth">�״δ���</param>
	/// <param name="lowerRpmThreshold">ת�����ޡ�</param>
	/// <param name="upperRpmThreshold">ת�����ޡ�</param>
	/// <param name="rpmStep">ת�ٲ�������λΪrpm��</param>
	/// <param name="referenceValue">�ο�ֵ��������db���ʱ�Ĳο�ֵ��</param>
	/// <param name="formatType">�����ʽ���͡� 0-RMS 1-Peak 2-Peak to peak</param>
	/// <param name="windowType">���������� 0-���δ� 1-Hanning��</param>
	/// <param name="weightType">��Ȩ���� 0-A��Ȩ 1-B��Ȩ 2-C��Ȩ</param>
	/// <param name="scaleType">�������� 0-������� 1-DB���</param>
	/// <param name="outOrderSection">���������ָ�����õ��Ľ״��������ݵ�ָ�롣</param>
	/// <param name="outRpmPoints">���������ָ���Ӧת�ٵ��ָ�롣</param>
	/// <param name="rpmBins">���������ָ��ת�ٷ���������ָ�롣</param>
	/// <returns>����1��ʾ�ɹ�������ֵ��ʾ������롣</returns>
	int OrderSection(SignalNative signalNative, RpmNative rpmNative, int specturmLines, double targetOrder, double orderBandwidth, double lowerRpmThreshold, double upperRpmThreshold, double rpmStep, double referenceValue, int formatType, int windowType, int weightType, int scaleType, double** outOrderSection, double** outRpmPoints, int* rpmBins);

	/// <summary>
	/// 3. �񶯺�����RMS
	/// </summary>
	/// <param name="signalNative">������ź����ݽṹ�塣</param>
	/// <param name="weightType">��Ȩ���ͣ�0-A��Ȩ 1-B��Ȩ 2-C��Ȩ��</param>
	/// <param name="outValue">���������ָ�����õ���RMSֵ��ָ�롣</param>
	/// <returns>����1��ʾ�ɹ�������ֵ��ʾ������롣</returns>
	int GetRms(SignalNative signalNative, int weightType, double* outValue);

	/// <summary>
	/// 4. �����ֵ
	/// </summary>
	/// <param name="signalNative">������ź����ݽṹ�塣</param>
	/// <param name="outValue">���������ָ�����õ������ֵ��ָ�롣</param>
	/// <returns>����1��ʾ�ɹ�������ֵ��ʾ������롣</returns>
	int GetMax(SignalNative signalNative, double* outValue);

	/// <summary>
	/// 5. ��Ƶ�̷�����Octave Band Analysis��
	/// </summary>
	/// <param name="signalNative">������ź����ݽṹ�塣</param>
	/// <param name="spectrumLines">������������Ƶ���ֱ��ʡ�</param>
	/// <param name="increment">������������λΪ�롣</param>
	/// <param name="lowerFreq">���������Ƶ�ʡ�</param>
	/// <param name="upperFreq">���������Ƶ�ʡ�</param>
	/// <param name="referenceValue">�ο�ֵ��������db���ʱ�Ĳο�ֵ��</param>
	/// <param name="formatType">�����ʽ���͡� 0-RMS 1-Peak 2-Peak to peak</param>
	/// <param name="octaveType">��Ƶ������</param>
	/// <param name="averageType">ƽ�����͡�</param>
	/// <param name="windowType">���������͡�</param>
	/// <param name="weightType">��Ȩ����</param>
	/// <param name="scaleType">��������</param>
	/// <param name="levelData">���������ָ�����õ��ı�Ƶ���������ݵ�ָ�롣</param>
	/// <param name="centerFreqs">���������ָ������Ƶ�������ָ�롣</param>
	/// <param name="lowerFreqs">���������ָ��ÿ��Ƶ������Ƶ�������ָ�롣</param>
	/// <param name="upperFreqs">���������ָ��ÿ��Ƶ������Ƶ�������ָ�롣</param>
	/// <param name="levelBins">���������ָ��Ƶ��������ָ�롣</param>
	/// <returns>����1��ʾ�ɹ�������ֵ��ʾ������롣</returns>
	int AveragedOctaveBandLevels(SignalNative signalNative, int spectrumLines, double increment, double lowerFreq, double upperFreq, double referenceValue, int foramtType, int octaveType, int averageType, int windowType, int weightType, int scaleType, double** levelData, double** centerFreqs, double** lowerFreqs, double** upperFreqs, int* levelBins);

	/// <summary>
	/// 6-1. �״���
	/// </summary>
	/// <param name="signalNative">������ź����ݽṹ�塣</param>
	/// <param name="rpmNative">�����ת�����ݽṹ�塣</param>
	/// <param name="maxOrder">�״ε����ֵ��</param>
	/// <param name="orderResolution">�״ηֱ��ʡ�</param>
	/// <param name="oversamplingFactor">���������ӡ�</param>
	/// <param name="lowerRpmThreshold">ת�����ޡ�</param>
	/// <param name="upperRpmThreshold">ת�����ޡ�</param>
	/// <param name="rpmStep">ת�ٲ�������λΪrpm��</param>
	/// <param name="referenceValue">�ο�ֵ��������db���ʱ�Ĳο�ֵ��</param>
	/// <param name="formatType">�����ʽ���͡�</param>
	/// <param name="windowType">���������͡�</param>
	/// <param name="weightType">��Ȩ���͡�</param>
	/// <param name="scaleType">�������͡�</param>
	/// <param name="spectrumData">���������ָ��״������ݵ�ָ�롣</param>
	/// <param name="orderAxis">���������ָ��״������ݵ�ָ�롣</param>
	/// <param name="orderBins">���������ָ��״η���������ָ�롣</param>
	/// <returns>����1��ʾ�ɹ�������ֵ��ʾ������롣</returns>
	int OrderSpectrum(SignalNative signalNative, RpmNative rpmNative, double maxOrder, double orderResolution, double oversamplingFactor, double lowerRpmThreshold, double upperRpmThreshold, double rpmStep, double referenceValue, int formatType, int windowType, int weightType, int scaleType, double** spectrumData, double** orderAxis, int* orderBins);

	/// <summary>
	/// 6-2. ƽ���״���-ת�ٸ���
	/// </summary>
	/// <param name="signalNative"></param>
	/// <param name="rpmNative"></param>
	/// <param name="maxOrder"></param>
	/// <param name="orderResolution"></param>
	/// <param name="oversamplingFactor"></param>
	/// <param name="lowerRpmThreshold"></param>
	/// <param name="upperRpmThreshold"></param>
	/// <param name="rpmStep"></param>
	/// <param name="referenceValue"></param>
	/// <param name="formatType"></param>
	/// <param name="windowType"></param>
	/// <param name="weightType"></param>
	/// <param name="scaleType"></param>
	/// <param name="spectrumData"></param>
	/// <param name="orderAxis"></param>
	/// <param name="orderBins"></param>
	/// <returns></returns>
	int AvgOrderSpectrumTacho(SignalNative signalNative, RpmNative rpmNative, int spectrumLines, double maxOrder, double orderResolution, double lowerRpmThreshold, double upperRpmThreshold, double rpmStep, double referenceValue, int formatType, int windowType, int weightType, int scaleType, double** spectrumData, double** orderAxis, int* orderBins);

	/// <summary>
	/// 6-3. ƽ���״���-ʱ����Ƭ
	/// </summary>
	/// <param name="signalNative"></param>
	/// <param name="rpmNative"></param>
	/// <param name="spectrumList"></param>
	/// <param name="increment"></param>
	/// <param name="maxOrder"></param>
	/// <param name="orderResolution"></param>
	/// <param name="referenceValue"></param>
	/// <param name="formatType"></param>
	/// <param name="windowType"></param>
	/// <param name="weightType"></param>
	/// <param name="scaleType"></param>
	/// <param name="spectrumData"></param>
	/// <param name="orderAxis"></param>
	/// <param name="orderBins"></param>
	/// <returns></returns>
	int AvgOrderSpectrumTime(SignalNative signalNative, RpmNative rpmNative, int spectrumLines, double increment, double maxOrder, double orderResolution, double referenceValue, int formatType, int windowType, int weightType, int scaleType, double** spectrumData, double** orderAxis, int* orderBins);

	/// <summary>
	/// 7. �񶯺�����ƽ����
	/// </summary>
	/// <param name="signalNative">������ź����ݽṹ�塣</param>
	/// <param name="spectrumLines">������������Ƶ�׷ֱ��ʡ�</param>
	/// <param name="increment">������������λΪ�롣</param>
	/// <param name="formatType">�����ʽ���͡� 0-RMS 1-Peak 2-Peak to peak</param>
	/// <param name="averageType">ƽ�����͡�</param>
	/// <param name="weightType">��Ȩ���͡�</param>
	/// <param name="windowType">���������͡�</param>
	/// <param name="outSpectrum">���������ָ�����õ���ƽ�������ݵ�ָ�롣</param>
	/// <param name="outLength">���������ָ��ƽ���׳��ȵ�ָ�롣</param>
	/// <returns>����1��ʾ�ɹ�������ֵ��ʾ������롣</returns>
	int AveragedSpectrumByIncrement(SignalNative signalNative, int spectrumLines, double increment, int formatType, int averageType, int windowType, int weightType, double** outSpectrum, int* outLength);

	/// <summary>
	/// 8. ������
	/// </summary>
	/// <param name="signalNative">������ź����ݽṹ�塣</param>
	/// <param name="outEnvelope">���������ָ�����õ��İ��������ݵ�ָ�롣</param>
	/// <param name="outLength">���������ָ������׳��ȵ�ָ�롣</param>
	/// <returns>����1��ʾ�ɹ�������ֵ��ʾ������롣</returns>
	int GetEnvelope(SignalNative signalNative, double** outEnvelope, int* outLength);

	/// <summary>
	/// 9. ɫ��ͼ��ʱ��-Ƶ�ʣ�
	/// </summary>
	/// <param name="signalNative">������ź����ݽṹ�塣</param>
	/// <param name="spectrumLines">������������Ƶ�׷ֱ��ʡ�</param>
	/// <param name="increment">������������λΪ�롣</param>
	/// <param name="startTime">������ʼʱ�䣬��λΪ�롣</param>
	/// <param name="endTime">��������ʱ�䣬��λΪ�룬-1.0��ʾ���ź�ĩβ��</param>
	/// <param name="referenceValue">�ο�ֵ��������db���ʱ�Ĳο�ֵ��</param>
	/// <param name="formatType">�����ʽ���͡� 0-RMS 1-Peak 2-Peak to peak</param>
	/// <param name="windowType">���������͡�</param>
	/// <param name="weightType">��Ȩ���͡�</param>
	/// <param name="scaleType">�������͡�</param>
	/// <param name="colormapData">���������ָ��ɫ��ͼ���ݵ�ָ�롣</param>
	/// <param name="timeBins">���������ָ��ʱ�����������ָ�롣</param>
	/// <param name="frequencyBins">���������ָ��Ƶ�ʷ���������ָ�롣</param>
	/// <returns>����1��ʾ�ɹ�������ֵ��ʾ������롣</returns>
	int GenerateTimeFrequencyColormapByIncrement(SignalNative signalNative, int spectrumLines, double increment, double startTime, double endTime, double referenceValue, int formatType, int windowType, int weightType, int scaleType, double** colormapData, int* timeBins, int* frequencyBins);

	/// <summary>
	/// 10. ɫ��ͼ��ת��-Ƶ�ʣ�
	/// </summary>
	/// <param name="signalNative">������ź����ݽṹ�塣</param>
	/// <param name="rpmNative">�����ת�����ݽṹ�塣</param>
	/// <param name="spectrumLines">������������Ƶ�׷ֱ��ʡ�</param>
	/// <param name="lowerRpmThreshold">ת�����ޡ�</param>
	/// <param name="upperRpmThreshold">ת�����ޣ�-1.0��ʾ���ת�١�</param>
	/// <param name="rpmStep">ת�ٲ�������λΪrpm��</param>
	/// <param name="referenceValue">�ο�ֵ��������db���ʱ�Ĳο�ֵ��</param>
	/// <param name="formatType">�����ʽ���͡�</param>
	/// <param name="windowType">���������͡�</param>
	/// <param name="weightType">��Ȩ���͡�</param>
	/// <param name="scaleType">�������͡�</param>
	/// <param name="colormapData">���������ָ��ɫ��ͼ���ݵ�ָ�롣</param>
	/// <param name="rpmData">���������ָ��ת�������ݵ�ָ�롣</param>
	/// <param name="freqData">���������ָ��Ƶ�������ݵ�ָ�롣</param>
	/// <param name="rpmBins">���������ָ��ת�ٷ���������ָ�롣</param>
	/// <param name="frequencyBins">���������ָ��Ƶ�ʷ���������ָ�롣</param>
	/// <returns>����1��ʾ�ɹ�������ֵ��ʾ������롣</returns>
	int GenerateRpmFrequencyColormap(SignalNative signalNative, RpmNative rpmNative, int spectrumLines, double lowerRpmThreshold, double upperRpmThreshold, double rpmStep, double referenceValue, int formatType, int windowType, int weightType, int scaleType, double** colormapData, double** rpmData, double** freqData, int* rpmBins, int* frequencyBins);

	/// <summary>
	/// 11. ɫ��ͼ��ת��-�״Σ�
	/// </summary>
	/// <param name="signalNative">������ź����ݽṹ�塣</param>
	/// <param name="rpmNative">�����ת�����ݽṹ�塣</param>
	/// <param name="maxOrder">�״ε����ֵ��</param>
	/// <param name="orderResolution">�״ηֱ��ʡ�</param>
	/// <param name="oversamplingFactor">���������ӡ�</param>
	/// <param name="lowerRpmThreshold">ת�����ޡ�</param>
	/// <param name="upperRpmThreshold">ת�����ޡ�</param>
	/// <param name="rpmStep">ת�ٲ�������λΪrpm��</param>
	/// <param name="referenceValue">�ο�ֵ��������db���ʱ�Ĳο�ֵ��</param>
	/// <param name="formatType">�����ʽ���͡�</param>
	/// <param name="windowType">���������͡�</param>
	/// <param name="weightType">��Ȩ���͡�</param>
	/// <param name="scaleType">�������͡�</param>
	/// <param name="colormapData">���������ָ��ɫ��ͼ���ݵ�ָ�롣</param>
	/// <param name="rpmAxis">���������ָ��ת�������ݵ�ָ�롣</param>
	/// <param name="orderAxis">���������ָ��״������ݵ�ָ�롣</param>
	/// <param name="rpmBins">���������ָ��ת�ٷ���������ָ�롣</param>
	/// <param name="orderBins">���������ָ��״η���������ָ�롣</param>
	/// <returns>����1��ʾ�ɹ�������ֵ��ʾ������롣</returns>
	int GenerateRpmOrderColormap(SignalNative signalNative, RpmNative rpmNative, double maxOrder, double orderResolution, double oversamplingFactor, double lowerRpmThreshold, double upperRpmThreshold, double rpmStep, double referenceValue, int formatType, int windowType, int weightType, int scaleType, double** colormapData, double** rpmAxis, double** orderAxis, int* rpmBins, int* orderBins);

	/// <summary>
	/// 12. ��Crestֵ
	/// </summary>
	/// <param name="signalNative">������ź����ݽṹ�塣</param>
	/// <param name="outValue">���������ָ��Crestֵ��ָ�롣</param>
	/// <returns>����1��ʾ�ɹ�������ֵ��ʾ������롣</returns>
	int GetCrestFactor(SignalNative signalNative, double* outValue);

	/// <summary>
	/// ��ȡ�źŵ�ָ��ʱ��Ρ�
	/// </summary>
	/// <param name="signalNative">������ź����ݽṹ�塣</param>
	/// <param name="startTime">��ʼʱ�䣬��λΪ�롣</param>
	/// <param name="endTime">����ʱ�䣬��λΪ�롣</param>
	/// <param name="outSignal">���������ָ���ȡ���źŵĽṹ��ָ�롣</param>
	/// <returns>����1��ʾ�ɹ�������ֵ��ʾ������롣</returns>
	int SignalSlice(SignalNative signalNative, double startTime, double endTime, SignalNative* outSignal);

	/// <summary>
	/// ��ȡת�ٵ�ָ��ʱ��Ρ�
	/// </summary>
	/// <param name="rpmNative">�����ת�����ݽṹ�塣</param>
	/// <param name="startTime">��ʼʱ�䣬��λΪ�롣</param>
	/// <param name="endTime">����ʱ�䣬��λΪ�롣</param>
	/// <param name="outRpm">���������ָ���ȡ��ת�ٵĽṹ��ָ�롣</param>
	/// <returns>����1��ʾ�ɹ�������ֵ��ʾ������롣</returns>
	int RpmSlice(RpmNative rpmNative, double startTime, double endTime, RpmNative* outRpm);

	/// <summary>
	/// �����ź�תת��
	/// </summary>
	/// <param name="signalNative">�����ź�Դ</param>
	/// <param name="edgeDetectorNative">��Ե���ѡ��</param>
	/// <param name="rpmCalculationOptionsNative">ת�ټ���ѡ��</param>
	/// <param name="outRpm">ת�����</param>
	/// <returns>����1��ʾ�ɹ�������ֵ��ʾ������롣</returns>
	int PulseToRpm(SignalNative signalNative, EdgeDetectorNative edgeDetectorNative, RpmCalculationOptionsNative rpmCalculationOptionsNative, RpmNative* outRpm);

	/// <summary>
	/// �������֤�ַ�������֤����Ч�ԡ�
	/// </summary>
	/// <param name="license">ָ�����֤�ַ�����ָ�롣</param>
	/// <returns>������֤���غ���֤�ɹ����򷵻�1�����򷵻�0��</returns>
	int LoadLicense(const char* license);

	/// <summary>
	/// ��ȡ���һ�δ���Ĵ�����Ϣ��
	/// </summary>
	/// <param name="errorCode">�����롣</param>
	/// <returns>���ش�����Ϣ�ַ�����</returns>
	const char* GetLastErrorMessage(int errorCode);

	/// <summary>
	/// �ͷ���ָ�� ptr ָ����ڴ���Դ��
	/// </summary>
	/// <param name="ptr">ָ����Ҫ�ͷŵ��ڴ���ָ�롣</param>
	/// <returns>����ͷųɹ������� 0�����򷵻ط���ֵ��ʾ����</returns>
	int Free(void* ptr);

#ifdef __cplusplus
}
#endif#endif
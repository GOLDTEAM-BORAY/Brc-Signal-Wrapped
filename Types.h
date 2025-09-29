#pragma once
#include <cstdint>
#ifdef __cplusplus
extern "C" {
#endif

	/**
	 * �������ͽṹ�壬��ʾһ��������ʵ�����鲿����
	 */
	typedef struct {
		double Real;         ///< ʵ��
		double Imaginary;    ///< �鲿
	} ComplexNative;

	/**
	 * �ź����ݽṹ�壬����һ��ʱ���źš�
	 */
	typedef struct {
		double* Samples;     ///< ָ���źŲ���ֵ�����ָ��
		int Length;          ///< ��������
		double DeltaTime;    ///< ����������룩������1/������
		int64_t UnixTime;    ///< �ź���ʼʱ���Unixʱ��������룩
	} SignalNative;

	/**
	 * ת�����ݽṹ�壬����һ��ת����ʱ��仯�����С�
	 */
	typedef struct {
		double* RpmValues;   ///< ָ��ת��ֵ�����ָ��
		double* TimeValues;  ///< ָ���Ӧʱ��������ָ��
		int Length;          ///< ���ݵ���
	} RpmNative;

	/**
	 * ��Ե�������ṹ�壬���������ź�תת�١�
	 */
	typedef struct {
		int MinInterval;     ///< ��С��������������㣩�����ڹ��˹��ڽӽ��Ĺ���㣬Ĭ��10
		double offset;       ///< ���������ѹƫ������Ĭ��0.0
		int edgeType;        ///< ���ı�Ե���ͣ�0-������ 1-�½��� 2-���߶���⣬Ĭ��0
	} EdgeDetectorNative;

	/**
	 * ת�ټ�������ṹ�塣
	 */
	typedef struct {
		int PulsesPerRevolution;    ///< ÿתһȦ�������������ݼ���豸����
		int PlusesPerMeasurement;   ///< ���ڼ���ÿ��RPMֵ����������Ĭ��100
		int SkipEdges;              ///< ÿ�����ٸ����ؼ���һ��RPM��Ĭ��100
		bool IsResample;            ///< �Ƿ�����ز�����Ĭ��false
		double ResampleStartTime;   ///< �ز�������ʼʱ�䣨�룩��Ĭ��-1.0��ʹ�õ�һ��ʱ���
		double ResampleEndTime;     ///< �ز����Ľ���ʱ�䣨�룩��Ĭ��-1.0��ʹ�����һ��ʱ���
		double ResampleInterval;    ///< �ز�����ʱ�������룩��Ĭ��1.0
	} RpmCalculationOptionsNative;

	/**
	 * ƽ������ö�١�
	 * Energy: ����ƽ��
	 * Mean: ����ƽ��
	 * Max: ���ֵƽ��
	 */
	typedef enum {
		Energy = 0,
		Mean = 1,
		Max = 2
	} AverageType;

	/**
	 * ��Ȩ����ö�١�
	 * None: �޼�Ȩ
	 * A: A��Ȩ
	 * B: B��Ȩ
	 * C: C��Ȩ
	 */
	typedef enum {
		None = 0,
		A = 1,
		B = 2,
		C = 3
	} WeightType;

	/**
	 * ����������ö�١�
	 * Rectangular: ���δ�
	 * Hanning: ������
	 */
	typedef enum {
		Rectangular = 0,
		Hanning = 1,
	} WindowType;

	/**
	 * ������������ö�١�
	 * Linear: ����
	 * Db: �ֱ�
	 */
	typedef enum {
		Linear = 0,
		Db = 1
	} ScaleType;

	/**
	 * ��ֵ��ʽ����ö�١�
	 * RMS: ������
	 * Peak: ��ֵ
	 * PeakToPeak: ���ֵ
	 */
	typedef enum {
		RMS = 0,
		Peak = 1,
		PeakToPeak = 2
	} FormatType;

	/**
	 * �ź�����ö�١�
	 * Acoustic: ��ѧ�ź�
	 * Vibration: ���ź�
	 */
	typedef enum {
		Acoustic = 0,
		Vibration = 1
	} SignalType;

	/**
	 * ��Ƶ������ö�١�
	 * Octave: 1��Ƶ��
	 * ThirdOctave: 1/3��Ƶ��
	 * SixthOctave: 1/6��Ƶ��
	 * TwelfthOctave: 1/12��Ƶ��
	 * TwentyFourthOctave: 1/24��Ƶ��
	 */
	typedef enum {
		Octave,
		ThirdOctave,
		SixthOctave,
		TwelfthOctave,
		TwentyFourthOctave,
	} OctaveType;

	/**
	 * ��������ö�١�
	 * Rising: ������
	 * Falling: �½���
	 * Both: �����غ��½���
	 */
	typedef enum {
		Rising = 0,
		Falling = 1,
		Both = 2
	};

#ifdef __cplusplus
}
#endif
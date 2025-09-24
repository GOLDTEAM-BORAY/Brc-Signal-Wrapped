#pragma once
#include <cstdint>
#ifdef __cplusplus
extern "C" {
#endif

	typedef struct {
		double Real;
		double Imaginary;
	} ComplexNative;

	typedef struct {
		double* Samples;
		int Length;
		double DeltaTime;
		int64_t UnixTime;
	} SignalNative;;

	typedef struct {
		double* RpmValues;
		double* TimeValues;
		int Length;
	} RpmNative;

	typedef struct {
		int MinInterval;	// ��С������������ڹ��˹��ڽӽ��Ĺ���㣬Ĭ��ֵ 10;
		double offset;		// ���������ѹƫ������Ĭ��ֵ 0.0;
		int edgeType;		// ���ı�Ե���ͣ�0-������ 1-�½��� 2-���߶���⣬Ĭ��ֵ 0;
	} EdgeDetectorNative;

	typedef struct {
		int PulsesPerRevolution;	// ÿתһȦ�������������ݼ���豸����;
		int PlusesPerMeasurement;	// ���ڼ���ÿ��RPMֵ����������Ĭ��ֵ 100;
		int SkipEdges;				// ÿ�����ٸ����ؼ���һ��RPM��Ĭ��ֵ 100;
		bool IsResample;			// �Ƿ�����ز�����Ĭ��ֵ false;
		double ResampleStartTime;	// �ز�������ʼʱ�䣨�룩��Ĭ��ֵ -1.0��ʹ�õ�һ��ʱ���;
		double ResampleEndTime;		// �ز����Ľ���ʱ�䣨�룩��Ĭ��ֵ -1.0��ʹ�����һ��ʱ���;
		double ResampleInterval;	// �ز�����ʱ�������룩��Ĭ�� 1.0;
	} RpmCalculationOptionsNative;

	typedef enum {
		Energy = 0,
		Mean = 1,
		Max = 2
	} AverageType;

	typedef enum {
		None = 0,
		A = 1,
		B = 2,
		C = 3
	} WeightType;

	typedef enum {
		Rectangular = 0,
		Hanning = 1,
	} WindowType;

	typedef enum {
		FreqTime = 0,
		OrderTime = 1,
		FreqRpm = 2,
		OrderRpm = 3
	} ColormapType;

	typedef enum {
		Linear = 0,
		Db = 1
	} ScaleType;

	typedef enum {
		RMS = 0,
		Peak = 1,
		PeakToPeak = 2
	} FormatType;

	typedef enum {
		Acoustic = 0,
		Vibration = 1
	} SignalType;

	typedef enum {
		Octave,
		ThirdOctave,
		SixthOctave,
		TwelfthOctave,
		TwentyFourthOctave,
	} OctaveType;

	typedef enum {
		Rising = 0,
		Falling = 1,
		Both = 2
	};

#ifdef __cplusplus
}
#endif
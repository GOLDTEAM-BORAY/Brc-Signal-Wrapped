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
		int MinInterval;	// 最小过零点间隔，用于过滤过于接近的过零点，默认值 10;
		double offset;		// 检测的脉冲电压偏移量，默认值 0.0;
		int edgeType;		// 检测的边缘类型，0-上升沿 1-下降沿 2-两者都检测，默认值 0;
	} EdgeDetectorNative;

	typedef struct {
		int PulsesPerRevolution;	// 每转一圈的脉冲数，根据检测设备配置;
		int PlusesPerMeasurement;	// 用于计算每个RPM值的周期数，默认值 100;
		int SkipEdges;				// 每隔多少个边沿计算一次RPM，默认值 100;
		bool IsResample;			// 是否进行重采样，默认值 false;
		double ResampleStartTime;	// 重采样的起始时间（秒），默认值 -1.0，使用第一个时间点;
		double ResampleEndTime;		// 重采样的结束时间（秒），默认值 -1.0，使用最后一个时间点;
		double ResampleInterval;	// 重采样的时间间隔（秒），默认 1.0;
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
#pragma once
#include <cstdint>
#ifdef __cplusplus
extern "C" {
#endif

	/**
	 * 复数类型结构体，表示一个复数（实部和虚部）。
	 */
	typedef struct {
		double Real;         ///< 实部
		double Imaginary;    ///< 虚部
	} ComplexNative;

	/**
	 * 信号数据结构体，描述一段时域信号。
	 */
	typedef struct {
		double* Samples;     ///< 指向信号采样值数组的指针
		int Length;          ///< 采样点数
		double DeltaTime;    ///< 采样间隔（秒），等于1/采样率
		int64_t UnixTime;    ///< 信号起始时间的Unix时间戳（毫秒）
	} SignalNative;

	/**
	 * 转速数据结构体，描述一段转速随时间变化的序列。
	 */
	typedef struct {
		double* RpmValues;   ///< 指向转速值数组的指针
		double* TimeValues;  ///< 指向对应时间点数组的指针
		int Length;          ///< 数据点数
	} RpmNative;

	/**
	 * 边缘检测参数结构体，用于脉冲信号转转速。
	 */
	typedef struct {
		int MinInterval;     ///< 最小过零点间隔（采样点），用于过滤过于接近的过零点，默认10
		double offset;       ///< 检测的脉冲电压偏移量，默认0.0
		int edgeType;        ///< 检测的边缘类型，0-上升沿 1-下降沿 2-两者都检测，默认0
	} EdgeDetectorNative;

	/**
	 * 转速计算参数结构体。
	 */
	typedef struct {
		int PulsesPerRevolution;    ///< 每转一圈的脉冲数，根据检测设备配置
		int PlusesPerMeasurement;   ///< 用于计算每个RPM值的周期数，默认100
		int SkipEdges;              ///< 每隔多少个边沿计算一次RPM，默认100
		bool IsResample;            ///< 是否进行重采样，默认false
		double ResampleStartTime;   ///< 重采样的起始时间（秒），默认-1.0，使用第一个时间点
		double ResampleEndTime;     ///< 重采样的结束时间（秒），默认-1.0，使用最后一个时间点
		double ResampleInterval;    ///< 重采样的时间间隔（秒），默认1.0
	} RpmCalculationOptionsNative;

	/**
	 * 平均类型枚举。
	 * Energy: 能量平均
	 * Mean: 算数平均
	 * Max: 最大值平均
	 */
	typedef enum {
		Energy = 0,
		Mean = 1,
		Max = 2
	} AverageType;

	/**
	 * 加权类型枚举。
	 * None: 无加权
	 * A: A计权
	 * B: B计权
	 * C: C计权
	 */
	typedef enum {
		None = 0,
		A = 1,
		B = 2,
		C = 3
	} WeightType;

	/**
	 * 窗函数类型枚举。
	 * Rectangular: 矩形窗
	 * Hanning: 汉宁窗
	 */
	typedef enum {
		Rectangular = 0,
		Hanning = 1,
	} WindowType;

	/**
	 * 纵轴缩放类型枚举。
	 * Linear: 线性
	 * Db: 分贝
	 */
	typedef enum {
		Linear = 0,
		Db = 1
	} ScaleType;

	/**
	 * 幅值格式类型枚举。
	 * RMS: 均方根
	 * Peak: 峰值
	 * PeakToPeak: 峰峰值
	 */
	typedef enum {
		RMS = 0,
		Peak = 1,
		PeakToPeak = 2
	} FormatType;

	/**
	 * 信号类型枚举。
	 * Acoustic: 声学信号
	 * Vibration: 振动信号
	 */
	typedef enum {
		Acoustic = 0,
		Vibration = 1
	} SignalType;

	/**
	 * 倍频程类型枚举。
	 * Octave: 1倍频程
	 * ThirdOctave: 1/3倍频程
	 * SixthOctave: 1/6倍频程
	 * TwelfthOctave: 1/12倍频程
	 * TwentyFourthOctave: 1/24倍频程
	 */
	typedef enum {
		Octave,
		ThirdOctave,
		SixthOctave,
		TwelfthOctave,
		TwentyFourthOctave,
	} OctaveType;

	/**
	 * 边沿类型枚举。
	 * Rising: 上升沿
	 * Falling: 下降沿
	 * Both: 上升沿和下降沿
	 */
	typedef enum {
		Rising = 0,
		Falling = 1,
		Both = 2
	};

#ifdef __cplusplus
}
#endif
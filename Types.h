#pragma once

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
		int Length;
	} RpmNative;

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

#ifdef __cplusplus
}
#endif
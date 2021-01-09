#include "..\LibMathWrapper\LibMath.h"
#pragma once
namespace Core {
	template<typename T>
	class LibMath
	{
	public:
		LibMath();
		T add(T, T);
		T sub(T, T);
		T mul(T, T);
		T div(T, T);
		T abs(T);

	};

	template<typename T>
	LibMath<T>::LibMath() {
	}

	template<typename T>
	inline T LibMath<T>::add(T V1 , T V2)
	{
		return V1 + V2;
	}

	template<typename T>
	inline T LibMath<T>::sub(T V1, T V2)
	{
		return V1 - V2;
	}

	template<typename T>
	inline T LibMath<T>::mul(T V1, T V2)
	{
		return V1*V2;
	}

	template<typename T>
	inline T LibMath<T>::div(T V1, T V2)
	{
		return V1/V2;
	}

	template<typename T>
	inline T LibMath<T>::abs(T V1)
	{
		return std::abs(V1);
	}
}
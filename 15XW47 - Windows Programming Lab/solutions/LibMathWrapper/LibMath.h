#pragma once
#include "../LibMath/Core.h"
#include "ManagedObject.h"
using namespace System;
namespace CLI {
	template<typename T>
	public ref class LibMath : public ManagedObject<Core::LibMath<T>>
	{
	public:
		LibMath();
		template<typename T>
		T add(T, T);
		/*
		T sub(T, T);312
		T mul(T, T);
		T div(T, T);
		T abs(T, T);
		//int add(int V1, int V2);
		*/
	};

	template<typename T>
	T LibMath<T>::add(T V1, T V2) {
		Console::WriteLine((String)m_Instance->add(V1, V2));
	}
	/*
	template<int>
	int LibMath<int>::add(int V1, int V2) {
		Console::WriteLine((String)m_Instance->add(V1, V2));
	}
	/*
	template<typename T>
	T LibMath<T>::sub(T, T) {
		Console::WriteLine((String)m_Instance->add(T, T));
	}

	template<typename T>
	T LibMath<T>::mul(T, T) {
		Console::WriteLine((String)m_Instance->mul(T, T));
	}

	template<typename T>
	T LibMath<T>::div(T, T) {
		Console::WriteLine((String)m_Instance->div(T, T));
	}

	template<typename T>
	T LibMath<T>::abs(T, T) {
		Console::WriteLine((String)m_Instance->abs(T, T));
	}
	*/
}

#pragma once
#include "NvFlexObjects.h"

using namespace System;
using namespace NvFlexObjects;

namespace NvFlexDotNet {

	public ref class Vector3
	{
		NvFlexObjects::Vector3* _handle;
	public:

		property float X {
			float get() { return _handle->X; }
			void set(float x) {	_handle->X = x;	}
		}
		property float Y {
			float get() { return _handle->Y; }
			void set(float y) {	_handle->Y = y;	}
		}

		property float Z {
			float get() { return _handle->Z; }
			void set(float z) {	_handle->Z = z;	}
		}

		Vector3() {
			_handle = new NvFlexObjects::Vector3();
		}

		Vector3(float X, float Y, float Z) {
			_handle = new NvFlexObjects::Vector3(X, Y, Z);
		}

		Vector3(double X, double Y, double Z) {
			_handle = new NvFlexObjects::Vector3(X, Y, Z);
		}

		Vector3(Vector3^ other) {
			_handle = new NvFlexObjects::Vector3(other->X, other->Y, other->Z);
		}

		Vector3% operator = (const Vector3% other) { return *this; }

		!Vector3(){
			delete _handle;
		}

		static Vector3^ operator + (Vector3^ lhs, const Vector3^ rhs) {
			auto vec = gcnew Vector3(lhs);
			vec->_handle->operator+(*(rhs->_handle));
			return vec;
		}		

		static Vector3^ operator - (Vector3^ lhs, const Vector3^ rhs) {
			auto vec = gcnew Vector3(lhs);
			vec->_handle->operator-(*(rhs->_handle));
			return vec;
		}		

		///<summary>
		///Always use this to add another vector to the current one. Do NOT use the += operator. Only this Add() function retains memory addresses properly. Using the += operator leads to changed memory addresses.
		///</summary>
		///<param name="other">The vector to add to the current one.</param>
		void Add(Vector3^ other) {
			_handle->operator+(*(other->_handle));
		}

		///<summary>
		///Always use this to subtract another vector from the current one. Do NOT use the -= operator. Only this Subtract() function retains memory addresses properly. Using the -= operator leads to changed memory addresses.
		///</summary>
		///<param name="other">The vector to subtract from the current one.</param>
		void Subtract(Vector3^ other) {
			_handle->operator-(*(other->_handle));
		}
	};
}

#pragma once

template<typename T>
inline void Safe_Delete(T* _Obj)
{
	delete _Obj;
	_Obj = nullptr;
}
#ifndef __ITER_HPP__
#define __ITER_HPP__

template <typename ArrType> 
void iter(ArrType *arr, int size, void func(ArrType const&))
{
	for (int i = 0; i < size; i++)
	{
		func(arr[i]);
	}
}

#endif
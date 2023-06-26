#ifndef __ITER_HPP__
#define __ITER_HPP__

template <typename ArrType, typename ReturnType> 
void iter(ArrType *arr, int size, ReturnType func(ArrType &))
{
	for (int i = 0; i < size; i++)
	{
		func(arr[i]);
	}
}

#endif
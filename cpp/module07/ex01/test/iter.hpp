#ifndef __ITER_HPP__
#define __ITER_HPP__

// cant figure out how to make it pass iter without specifying the templete arguments w/o
// hard coding void as return val
template <typename ArrType, template <class> typename FuncType> 
void iter(ArrType *arr, int size, FuncType<ArrType> func)
{
	for (int i = 0; i < size; i++)
	{
		func(arr[i]);
	}
}

#endif
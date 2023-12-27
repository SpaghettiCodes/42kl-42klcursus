#ifndef __WHATEVER_HPP__
#define __WHATEVER_HPP__

// Templates must be defined in the header files.
// lord forgive my messy header file
template <typename type_1> void swap(type_1 &a, type_1 &b)
{
	type_1 temp;

	temp = b;
	b = a;
	a = temp;
}

template <typename type_1> type_1 min(type_1 &a, type_1 &b)
{
	if (b <= a)
		return b;
	return a;
}

template <typename type_1> type_1 max(type_1 &a, type_1 &b)
{
	if (b >= a)
		return b;
	return a;
}

#endif
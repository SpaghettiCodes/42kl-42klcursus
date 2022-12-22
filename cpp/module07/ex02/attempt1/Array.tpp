#ifndef __ARRAY_TPP__
#define __ARRAY_TPP__

// this attempt tried to make it so that copying from a different type would work

// this attempt failed (obviously) because even if we managed to copy over the value, we cant
// change the pointer type which is pointing towards the array

template <typename Type>
Array<Type>::Array() : stuff_size(0), stuff(NULL)
{
}

template <typename Type>
Array<Type>::Array(Array<Type> &ori) : stuff(NULL)
{
	(*this) = ori;
}

template <typename Type> 
template <typename Type2>
Array<Type> &Array<Type>::operator=(Array<Type2> const &ori)
{
	if (this->stuff)
		delete []this->stuff;
	this->stuff_size = ori.size();
	this->stuff = copy_over <Type2> (ori);

	return (*this);
}

template <typename Type>
template <typename Type2>
Type2 *Array<Type>::copy_over(Array<Type2> const &ori)
{
	if (!ori.size())
		return (NULL);

	Type2 *ret;

	// deep copy
	ret = new Type2[ori.size()];
	for (unsigned int i = 0; i < ori.size(); i++)
		ret[i] = ori[i];
	return (ret);
}

template <typename Type>
Array<Type>::~Array()
{
	if (stuff)
		delete []stuff;
}

template <typename Type>
Type &Array<Type>::operator[](int const index)
{
	if (index >= 0 && index < (int) stuff_size)
		return (stuff[index]);
	throw (Array::OutOfBounds());
}

template <typename Type>
Type const &Array<Type>::operator[](int const index) const
{
	if (index >= 0 && index < (int) stuff_size)
		return (stuff[index]);
	throw (Array::OutOfBounds());
}

template <typename Type>
Array<Type>::Array(unsigned int size) : stuff_size(size)
{
	stuff = new Type[size];
}

template <typename Type>
unsigned int Array<Type>::size() const
{
	return (stuff_size);
}

#endif
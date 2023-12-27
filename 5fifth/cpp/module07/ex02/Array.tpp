#ifndef __ARRAY_TPP__
#define __ARRAY_TPP__

template <typename Type>
Array<Type>::Array() : stuff_size(0), stuff(NULL)
{
}

template <typename Type>
Array<Type>::Array(Array<Type> const &ori) : stuff(NULL)
{
	(*this) = ori;
}

template <typename Type>
Array<Type> &Array<Type>::operator=(Array<Type> const &ori)
{
	if (&ori == this)
		return (*this);

	if (this->stuff)
		delete []this->stuff;
	this->stuff_size = ori.stuff_size;
	this->stuff = copy_over(ori.stuff, ori.stuff_size);

	return (*this);
}

template <typename Type>
Type *Array<Type>::copy_over(Type *ori, int ori_size)
{
	if (!ori_size)
		return (NULL);
		
	Type *ret;

	// deep copy
	ret = new Type[stuff_size]();
	for (int i = 0; i < ori_size; i++)
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
	stuff = new Type[size]();
}

template <typename Type>
unsigned int Array<Type>::size() const
{
	return (stuff_size);
}

#endif
#include "ClojuerII.h"

template<class T>
Type ConstrctType<T>(T& V) {
	Type T = { T };
	T.Value = V;

	return T;
}

template<size_t N>
Types ConstructTypes<N>(Type& Ty[N]) {
	Types Type = { N };
	Type.T = Ty;

	return Type;
}
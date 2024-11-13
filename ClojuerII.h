#pragma once
struct Type {
	//type Type = NULL;
	typedef void* Type;
	//type T = Type;
	Type Value;
};
struct Types {
	const Size = 1;
	Type T[Size] = { 0, };
};
struct Clojuer {
	Type R;
	Types Arg;

	Type(*F)(Types&) = NULL;
};

template<class T> Type ConstrctType<T>(T& V);
template<size_t N> Types ConstructTypes<N>(Type& Ty[N]);

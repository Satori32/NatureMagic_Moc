#include <stdio.h>

#include "FixedBitSet.h"
#include "ClojuerII.h"

struct NatureWord {
	FixedBitSet Word;
};

template<class T,size_t N>
NatureWord ConstructNatureWord<T, N>() {
	NatureWord N;

	N.Word = ConstructFixedBitSet<T, N>();

	return N;
}

template<class R>
R Read(NatureWord& In, ClojuerII& C) {
	//do it.
	return false;
}
template<class T>
bool Write(NatureWord& In,T& B,ClojuerII& C) {
	 //do it.
	return false;
}
bool Clear(NatureWord& In) {
	//do it.
	return false;
}

struct Worder {
	FixedBitSet Word;
	ClojuerII Magic;
};
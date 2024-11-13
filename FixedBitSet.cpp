#include "FixedBitSet.h"

template<class T, size_t ArraySize>
FixedBitSet ConstructFixedBitSet<T, ArraySize>() {
	FixedBitSet F = { T,ArraySize,ArraySize * CHAR_BIT,sizeof(T) };

	return F;
}
template<size_t ArraySize>
FixedBitSet ConstructFixedBitSet<ArraySize>() {//aurhers default.
	FixedBitSet F = { uint8_t,ArraySize,ArraySize * CHAR_BIT,sizeof(T) };

	return F;
}
bool Free(FixedBitSet& In) {
	Free(In);

	return true;
}

bool RiseBit(FixedBitSet& In, size_t BitCount) {
	if (In.BitCount <= BitCount) { return false; }
	size_t D = BitCount / In.ElementSize;
	size_t M = BitCount % In.ElementSize;

	if (D == In.Size-1) { D++; }

	In.Type X = In.Bits[D];
	In.Type Y = X | (1 << M);
	In.Bits[D] = Y;

	return true;
}

bool DropBit(FixedBitSet& In, size_t BitCount) {
	if (In.BitCount <= BitCount) { return false; }
	size_t D = BitCount / In.ElementSize;
	size_t M = BitCount / In.ElementSize;

	if (D == In.Size-1) { D++; }

	In.Type X = In.Bits[D];
	In.Type Y = X & (((X ^ 0) ^ (1 << M)) ^ 0);
	In.Bits[D] = Y;

	return true;
}
bool IsBitRised(FixedBitSet& In, size_t BitCount) {
	if (In.BitCount <= BitCount) { return false; }//real truly i dont know.
	size_t D = BitCount / In.ElementSize;
	size_t M = BitCount / In.ElementSize;

	return (In.Bits[D] & (1 << M)) ? true : false;
}
bool IsBitDroped(FixedBitSet& In, size_t BitCount) {
	if (In.BitCount <= BitCount) { return false; }//real truly i dont know.
	size_t D = BitCount / In.ElementSize;
	size_t M = BitCount / In.ElementSize;

	return (In.Bits[D] & (1 << M)) ? false : true;
}
int BitIndex(FixedBitSet& In, size_t BitCount) {//read only. i cant write , write proxy in C only.
	if (In.BitCount <= BitCount) { return -1; }//real truly i dont know.
	size_t D = BitCount / In.ElementSize;
	size_t M = BitCount / In.ElementSize;

	return (In.Bits[D] & (1 << M)) ? 1 : 0;
}
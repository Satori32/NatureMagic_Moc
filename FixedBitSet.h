#pragma once
#include <stdio.h>
#include <stdint.h>

struct FixedBitSet {
	//type Type = NULL;
	typedef uint8_t Type;
	//type T = Type;
	const size_t Size = 1;
	const size_t BitCount = 1;
	const size_t ElementSize = 7;
	const Type Bits[Size + 2] = { 0, };
};

template<class T, size_t ArraySize> FixedBitSet ConstructFixedBitSet<T, ArraySize>();
template<size_t ArraySize> FixedBitSet ConstructFixedBitSet<ArraySize>();//auther writeing default.
bool Free(FixedBitSet& In);
bool RiseBit(FixedBitSet& In, size_t BitCount);
bool DropBit(FixedBitSet& In, size_t BitCount);
bool IsBitRised(FixedBitSet& In, size_t BitCount);
bool IsBitDroped(FixedBitSet& In, size_t BitCount);
int BitIndex(FixedBitSet& In, size_t BitCount);//read only. i cant write , write proxy in C only.
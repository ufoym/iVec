// This class is optional, and only used if SAVE_WEIGHT_IMAGE or SAVE_SCORE_IMAGE are defined

#ifndef BITMAP_WRITER_H
#define BITMAP_WRITER_H

#include "general.h"

namespace Livewire
{
	/// <summary>Debug utility to save a matrix as a grayscale image</summary>
	/// <param name="data">The data to save</param>
	/// <param name="w">The width of the data</param>
	/// <param name="h">The height of the data</param>
	/// <param name="name">The name of the data</param>
	void WriteBitmap(const uint *data, uint w, uint h, const char *name);

	/// <summary>Debug utility to save a matrix as a grayscale image</summary>
	/// <param name="data">The data to save</param>
	/// <param name="w">The width of the data</param>
	/// <param name="h">The height of the data</param>
	/// <param name="name">The name of the data</param>
	void WriteBitmap(const byte *data, uint w, uint h, const char *name);
}

#endif

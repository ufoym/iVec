// Inspired by a min-heap priority queue by Alexey Kurakin (http://www.codeproject.com/KB/threads/PriorityQueueGeneric.aspx)

#ifndef POINT_PRIORITY_QUEUE_H
#define POINT_PRIORITY_QUEUE_H

#include "general.h"

namespace Livewire
{
	class PointPriorityQueue
	{
		/* Necessary public functions:
		 *  void Enqueue(uint x, uint y, uint I, uint score)		O(log(n))
		 *  bool Dequeue(uint& x, uint& y, uint& I, uint& score)	O(log(n))
		 *	bool Contains(uint x, uint y) const						O(log(n))	Only for LivewireCalculator
		 *  bool DescreaseScore(uint x, uint y, uint score)			O(log(n))	Only for LivewireCalculator
		 *	void UpdateAllScores(CalcScore f, const void *param)	O(n)		Only for WeightCalculator
		 *  void Clear()											O(n)
		 * All other public functions can be removed
		 */

	public:
		struct Entry;

	private:
		const uint _width, _height;
		vector<Entry*> _heap;
		SparseMatrix<size_t*> _map;

	public:
		PointPriorityQueue(uint w, uint h);
		~PointPriorityQueue();

		void Enqueue(uint x, uint y, uint I, uint score);
//		void Enqueue(uint x, uint y, uint score);
//		void Enqueue(uint I, uint score);

		bool Dequeue(uint& x, uint& y, uint& I, uint& score);
//		bool Peek(uint& x, uint& y, uint& I, uint& score) const;

//		bool IsEmpty() const;
//		size_t Size() const;

		void Clear();

		bool Contains(uint x, uint y) const;
//		bool UpdateScore(uint x, uint y, uint score);
		bool DescreaseScore(uint x, uint y, uint score);
//		bool IncreaseScore(uint x, uint y, uint score);

//		bool Contains(uint I) const;
//		bool UpdateScore(uint I, uint score);
//		bool DescreaseScore(uint I, uint score);
//		bool IncreaseScore(uint I, uint score);

		typedef uint (*CalcScore)(uint x, uint y, uint I, const void *param);
		void UpdateAllScores(CalcScore f, const void *param);

	private:
		void ExchangeElements(size_t a, size_t b);

		void Insert(uint x, uint y, uint I, uint score);
		void HeapifyFromEndToBeginning(size_t pos);

		void DeleteRoot();
		void HeapifyFromBeginningToEnd(size_t pos);
	};
}

#endif

// Implementation of general functions and classes

#include "general.h"

#include <map>

using namespace Livewire;

typedef std::map<size_t, vector<void*> > bp_avail_map;
static bp_avail_map bp_avail;

void *BlockPool::Get(size_t size)
{
	void *block;
	size = NextPowerOfTwo(size);
	bp_avail_map::iterator i = bp_avail.find(size);
	if (i == bp_avail.end() || i->second.size() == 0)
		*(size_t*)(block = malloc(size + sizeof(size_t))) = size;
	else
		block = i->second.pop_back();
	return (byte*)block + sizeof(size_t);
}
void *BlockPool::Resize(void *block, size_t size)
{
	block = ((byte*)block) - sizeof(size_t);
	size = NextPowerOfTwo(size);
	if (*((size_t*)block) != size)
		*((size_t*)(block = realloc(block, size + sizeof(size_t)))) = size;
	return ((byte*)block) + sizeof(size_t);
}
void BlockPool::Return(void *block)
{
	block = (byte*)block - sizeof(size_t);
	bp_avail[ (*(size_t*)block) ].push_back(block);
}
void BlockPool::Clear()
{
	for (bp_avail_map::iterator i = bp_avail.begin(); i != bp_avail.end(); ++i)
	{
		size_t len = i->second.size();
		for (size_t j = 0; j < len; ++j)
			free(i->second[j]);
		i->second.reset();
	}
	bp_avail.clear();
}

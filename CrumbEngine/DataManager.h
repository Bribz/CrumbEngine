#ifndef DATA_MANAGER_H
#define DATA_MANAGER_H

#include "CrumbTypes.h"

class DataManager
{
public:
	DataManager(long* blockSize);
	~DataManager();

	//Factory GetObjectFactory();
	void* GetObject(int id);

	static void* INIT_MEMORY_BLOCK_SIZE(long* size)
	{
		*size = (long)(sizeof(CrumbMaterial) * 1);
		void* pDM = new char[*size];
		return pDM;
	};


private:
	long data_byte_count;
	char* pMemBlock;

	void AllocateMemoryBlock();
	void PreloadFlyweights();
	void PreloadAssetFactories();
	void DeallocateMemoryBlock();

};

#endif // !DATA_MANAGER_H
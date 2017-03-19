#include "DataManager.h"

DataManager::DataManager(long* pBlockSize)
{
	data_byte_count = *pBlockSize;
	AllocateMemoryBlock();
}


DataManager::~DataManager()
{
	DeallocateMemoryBlock();
}

//TODO: Change this later for custom heap allocation
void DataManager::AllocateMemoryBlock()
{
	//Determine Memory Count
	if (data_byte_count == 0)
	{
		printf("[ Fatal Error ] : Unassigned Memory Count!");
	}

	pMemBlock = new char[data_byte_count];

	//TODO: Auto Load Data
	//PreloadFlyweights
	PreloadFlyweights();

	//PreloadAssetFactories

}

void DataManager::PreloadFlyweights()
{
	CrumbMaterial* TempMat = new(pMemBlock) CrumbMaterial("Temp");
}

void DataManager::PreloadAssetFactories()
{
	//TODO: Implement Method
}

void* DataManager::GetObject(int id)
{
	char* pReturn = pMemBlock;
	pReturn += sizeof(CrumbMaterial) * id;
	return (void*)pReturn;
}

void DataManager::DeallocateMemoryBlock()
{
	//Unload Memory Block, delete pointers;
	CrumbMaterial* pTmpPtr = (CrumbMaterial*)pMemBlock;
	pTmpPtr->~CrumbMaterial();

	delete pMemBlock;
}

#pragma once
/*
* 
*/
#ifndef _STORAGEVO_H_
#define _STORAGEVO_H_
#include "../../GlobalInclude.h"
#include "../../dto/storage/StorageDTO.h"
#include "list"


#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ���幩Ӧ���˻����б�
 */
class StorageTableJsonVO : public JsonVO<List<StorageTableDTO::Wrapper>> 
{
	DTO_INIT(StorageTableJsonVO, JsonVO<List<StorageTableDTO::Wrapper>>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE_DTO_
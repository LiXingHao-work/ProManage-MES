#pragma once
/*
* 
*/
#ifndef _STORAGEDTO_
#define _STORAGEDTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��Ӧ���˻����б�����ģ��
 */
class StorageTableDTO : public oatpp::DTO
{
	DTO_INIT(StorageTableDTO, DTO);
	//�˻������
	API_DTO_FIELD(UInt64, returnId�� ZH_WORDS_GETTER("storage.fields.rtid"), true, 1);
	//�˻�������
	API_DTO_FIELD(String, returnName, ZH_WORDS_GETTER("storage.fields.rtname"), true, "01star");
	//״̬
	API_DTO_FIELD(Int32, status, ZH_WORDS_GETTER("storage.fields.status"), true, 0);
};

class StorageDetailDTO : public StorageTableDTO
{
	DTO_INIT(StorageDetailDTO, StorageTableDTO);
	//�˻�����
	API_DTO_FIELD(string, date, ZH_WORDS_GETTER("storage.fields.rtdate"), true, "2022-11-15");
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_
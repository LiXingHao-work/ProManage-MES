#pragma once

#ifndef _STORAGEQUERY_H_
#define _STORAGEQUERY_H_

#include "../../GlobalInclude.h"
// #include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �ֿ�����ѯ����
 */
class StorageQuery : public oatpp::DTO
{
	// �����ʼ��
	DTO_INIT(StorageQuery, DTO);
	// �˻�������
	API_DTO_FIELD_DEFAULT(String, returnName, ZH_WORDS_GETTER("storage.fields.rtname"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_USERQUERY_H_
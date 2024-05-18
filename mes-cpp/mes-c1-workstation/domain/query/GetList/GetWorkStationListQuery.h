#pragma once

#ifndef _GETWORKSTATIONLIST_QUERY_H_
#define _GETWORKSTATIONLIST_QUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ҳ��ȡ����վ�б�
 */
class GetWorkStationListQuery : public PageQuery
{
	DTO_INIT(GetWorkStationListQuery, PageQuery);
	//����վ����
	API_DTO_FIELD_DEFAULT(String, workstationCode, ZH_WORDS_GETTER("getlist.fields.workstationCode"));
	//����վ����
	API_DTO_FIELD_DEFAULT(String, workstationName, ZH_WORDS_GETTER("getlist.fields.workstationName"));
	//���ڳ�������
	API_DTO_FIELD_DEFAULT(String, workshopName, ZH_WORDS_GETTER("getlist.fields.workshopName"));
	//��������(��������)
	API_DTO_FIELD_DEFAULT(String, processName, ZH_WORDS_GETTER("getlist.fields.processName"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_
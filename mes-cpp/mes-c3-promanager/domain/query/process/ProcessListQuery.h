#pragma once
#ifndef _PROCESSLIST_QUERY_
#define _PROCESSLIST_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ҳ��ѯ�����б�
 */
class ProcessListQuery : public PageQuery
{
	DTO_INIT(ProcessListQuery, PageQuery);
	// ����·�߱��
	DTO_FIELD(String, routeCode);
	DTO_FIELD_INFO(routeCode) {
		info->description = ZH_WORDS_GETTER("process.field.routecode");
	}
	// ����·������
	DTO_FIELD(String, routeName);
	DTO_FIELD_INFO(routeName) {
		info->description = ZH_WORDS_GETTER("process.field.name");
	}
	// �Ƿ�����
	DTO_FIELD(String, enableFlag);
	DTO_FIELD_INFO(enableFlag) {
		info->description = ZH_WORDS_GETTER("process.field.flag");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_

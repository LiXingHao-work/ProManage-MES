#pragma once
#ifndef _PROCESSINSPECTION_QUERY_
#define _PROCESSINSPECTION_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ����ҳ��ѯ����
 */
class ProcessinSpectionQuery : public PageQuery {
	DTO_INIT(ProcessinSpectionQuery, PageQuery);
	
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_PROCESSINSPECTION_QUERY_

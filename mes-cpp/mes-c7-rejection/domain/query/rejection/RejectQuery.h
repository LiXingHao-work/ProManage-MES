#pragma once
#ifndef _REJECT_QUERY_
#define _REJECT_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"


#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ���Ϸ�ҳ��ѯ��������
 */
class RejectQuery : public PageQuery
{
	DTO_INIT(RejectQuery, PageQuery);


	// ���ϵ����
	API_DTO_FIELD_DEFAULT(String, rt_code, ZH_WORDS_GETTER("reject.fields.rt_code"));
	// ��������
	API_DTO_FIELD_DEFAULT(String, workorder_id, ZH_WORDS_GETTER("reject.fields.workorder_id"));
	//�ֿ�����
	API_DTO_FIELD_DEFAULT(String, warehouse_name, ZH_WORDS_GETTER("dept.fields.warehouse_name"));
	
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_
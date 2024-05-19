#ifndef _MACHINERY_PLAN_QUERY_
#define _MACHINERY_PLAN_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)	

/*
* ���/�����ƻ��б�������ҳ��ѯ����
*/
class MachineryPlanQuery : public PageQuery
{
	DTO_INIT(MachineryPlanQuery, PageQuery);

	// �ƻ����
	DTO_FIELD(String, plan_code);
	DTO_FIELD_INFO(plan_code) {
		info->description = ZH_WORDS_GETTER("machinery-plan.field.plan-code");
	}

	// �ƻ�����
	DTO_FIELD(String, plan_name);
	DTO_FIELD_INFO(plan_name) {
		info->description = ZH_WORDS_GETTER("machinery-plan.field.plan-name");
	}

	// �ƻ�����
	DTO_FIELD(String, plan_type);
	DTO_FIELD_INFO(plan_type) {
		info->description = ZH_WORDS_GETTER("machinery-plan.field.plan-type");
	}

	// ״̬
	DTO_FIELD(String, status);
	DTO_FIELD_INFO(status) {
		info->description = ZH_WORDS_GETTER("machinery-plan.field.status");
	}
};

/*
* ��ȡ��챣���ƻ�����
*/
class MachineryPlanDetailsQuery : public oatpp::DTO
{
	DTO_INIT(MachineryPlanDetailsQuery, DTO);

	// �ƻ�ID
	DTO_FIELD(UInt64, plan_id);
	DTO_FIELD_INFO(plan_id) {
		info->description = ZH_WORDS_GETTER("machinery-plan.field.plan-id");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_MACHINERY_PLAN_QUERY_
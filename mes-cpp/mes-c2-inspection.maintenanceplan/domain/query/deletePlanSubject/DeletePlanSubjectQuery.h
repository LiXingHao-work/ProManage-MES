#pragma once
/*
*
*/
#ifndef _DELETEPLANSUBJECTQUERY__H_
#define _DELETEPLANSUBJECTQUERY__H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/*
* ��ȡ��챣���ƻ�����
*/
class DeletePlanQuery : public oatpp::DTO
{
	DTO_INIT(DeletePlanQuery, DTO);

	// �ƻ�ID
	DTO_FIELD(Int64, plan_id);
	DTO_FIELD_INFO(plan_id) {
		info->description = ZH_WORDS_GETTER("machinery-plan.field.plan-id");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // 

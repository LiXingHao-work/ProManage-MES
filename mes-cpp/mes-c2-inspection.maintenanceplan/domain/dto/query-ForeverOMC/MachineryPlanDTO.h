#ifndef _MACHINERY_PLAN_DTO_
#define _MACHINERY_PLAN_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* ���/�����ƻ��б������
*/
class MachineryPlanDTO : public oatpp::DTO
{
	DTO_INIT(MachineryPlanDTO, DTO);

	// �ƻ�ID
	DTO_FIELD(UInt64, plan_id);
	DTO_FIELD_INFO(plan_id) {
		info->description = ZH_WORDS_GETTER("machinery-plan.field.plan-id");
	}

	// �ƻ�����
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

	// ��ʼ����
	DTO_FIELD(String, start_date);
	DTO_FIELD_INFO(start_date) {
		info->description = ZH_WORDS_GETTER("machinery-plan.field.start-date");
	}

	// ��������
	DTO_FIELD(String, end_date);
	DTO_FIELD_INFO(end_date) {
		info->description = ZH_WORDS_GETTER("machinery-plan.field.end-date");
	}

	// Ƶ��
	DTO_FIELD(String, cycle_type);
	DTO_FIELD_INFO(cycle_type) {
		info->description = ZH_WORDS_GETTER("machinery-plan.field.cycle-type");
	}

	// ����
	DTO_FIELD(String, cycle_count);
	DTO_FIELD_INFO(cycle_count) {
		info->description = ZH_WORDS_GETTER("machinery-plan.field.cycle-count");
	}

	// ״̬
	DTO_FIELD(String, status);
	DTO_FIELD_INFO(status) {
		info->description = ZH_WORDS_GETTER("machinery-plan.field.status");
	}
};

/**
* ���/�����ƻ��б��ҳ�������
*/
class MachineryPlanPageDTO : public PageDTO<MachineryPlanDTO::Wrapper>
{
	DTO_INIT(MachineryPlanPageDTO, PageDTO<MachineryPlanDTO::Wrapper>);
};

class MachineryPlanDetailsDTO : public MachineryPlanDTO
{
	DTO_INIT(MachineryPlanDetailsDTO, MachineryPlanDTO);

	// ��ע
	DTO_FIELD(String, remark);
	DTO_FIELD_INFO(remark) {
		info->description = ZH_WORDS_GETTER("machinery-plan.field.remark");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_MACHINERY_PLAN_DTO_
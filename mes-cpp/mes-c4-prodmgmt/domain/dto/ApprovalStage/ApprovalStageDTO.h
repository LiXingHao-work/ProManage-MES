#pragma once
#ifndef _GETPRODUCTIONREPORTLIST_DTO_
#define _GETPRODUCTIONREPORTLIST_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �������ɹ����������
 */
class ApprovalStageDTO : public oatpp::DTO
{
	DTO_INIT(ApprovalStageDTO, DTO);
	//��¼id/�����������;record_id;bigint
	DTO_FIELD(UInt64, record_id);
	DTO_FIELD_INFO(record_id) {
		info->description = ZH_WORDS_GETTER("Approval.post.id");
	}
	//��������;feedback_type;varchar
	DTO_FIELD(String, feedback_type);
	DTO_FIELD_INFO(feedback_type) {
		info->description = ZH_WORDS_GETTER("Approval.post.remark");
	}
};
#include OATPP_CODEGEN_END(DTO)
#endif 
#include "stdafx.h"
#include "ApprovalStageService.h"
#include "../../dao/ApprovalStage/ApprovalStageDAO.h"

bool ApprovalStageService::updateData(const ApprovalStageDTO::Wrapper& dto)
{
	// ��װDO����
	ApprovalStageDO data;
	// 	data.setId(dto->id.getValue(0));
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, feedback_type, feedback_type, record_id, record_id)
		// ִ�������޸�
	ApprovalStageDAO dao;
	return dao.update(data) == 1;
}

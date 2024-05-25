#include "stdafx.h"
#include "ApprovalStageService.h"
#include "../../dao/ApprovalStage/ApprovalStageDAO.h"
// �ύ����
bool ApprovalStageService::submitForApproval(const ApprovalStageDTO::Wrapper& dto)
{
	// ��װDO����
	ApprovalStageDO data;
	// 	data.setId(dto->id.getValue(0));
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, status, status, record_id, record_id)
		// ִ�������޸�
	ApprovalStageDAO dao;
	return dao.SubmitForApproval(data) == 1;
}
//����ͨ��
bool ApprovalStageService::approvalPassed(const ApprovalStageDTO::Wrapper& dto)
{
	// ��װDO����
	ApprovalStageDO data;
	// 	data.setId(dto->id.getValue(0));
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, status, status, record_id, record_id)
		// ִ�������޸�
		ApprovalStageDAO dao;
	return dao.ApprovalPassed(data) == 1;
}
//������ͨ��
bool ApprovalStageService::approvalNotPassed(const ApprovalStageDTO::Wrapper& dto)
{
	// ��װDO����
	ApprovalStageDO data;
	// 	data.setId(dto->id.getValue(0));
	// 	data.setName(dto->name.getValue(""));
	// 	data.setSex(dto->sex.getValue(""));
	// 	data.setAge(dto->age.getValue(1));
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, status, status, record_id, record_id)
		// ִ�������޸�
		ApprovalStageDAO dao;
	return dao.ApprovalNotPassed(data) == 1;
}

#pragma once
#ifndef _APPROVALSTAGE_CONTROLLER_
#define _APPROVALSTAGE_CONTROLLER_
#include "domain/vo/BaseJsonVO.h"
#include "../mes-c4-prodmgmt/domain/vo/ApprovalStage/ApprovalStageVO.h"
#include "../mes-c4-prodmgmt/domain/dto/ApprovalStage/ApprovalStageDTO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ��������
 */
class ApprovalStage : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(ApprovalStage);
	// 3 ����ӿ�
public:
	// 3.1 �����޸Ľӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("Approval.post.name"), modifyApprovalStage, ApprovalStageVO::Wrapper);
	// 3.2 �����޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/sample", modifyApprovalStage, BODY_DTO(ApprovalStageDTO::Wrapper, dto), execModifyApprovalStage(dto));

private:
	// 3.3 ��ʾ�޸�����
	Uint64JsonVO::Wrapper execModifyApprovalStage(const ApprovalStageDTO::Wrapper& dto);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _PROWORKORDER_CONTROLLER_
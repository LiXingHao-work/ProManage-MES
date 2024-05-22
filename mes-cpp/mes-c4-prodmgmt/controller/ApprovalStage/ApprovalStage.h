#pragma once
#ifndef _ADDPRODWORKORDER_CONTROLLER_
#define _ADDPRODWORKORDER_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "../mes-c4-prodmgmt/domain/do/ApprovalStage/ApprovalStageDO.h"
#include "../mes-c4-prodmgmt/domain/dto/ApprovalStage/ApprovalStageDTO.h"
#include "../mes-c4-prodmgmt/domain/vo/ApprovalStage/ApprovalStageVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ��������������
 */
class ApprovalStage : public oatpp::web::server::api::ApiController {// 1 �̳п�����
	// 2 ����������������
	API_ACCESS_DECLARE(ApprovalStage);
	// 3 ����ӿ�
public:

	// 3.1 ���������ӿ�����
	ENDPOINT_INFO(submitForApproval) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("Approval.post.submi"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}

	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/ProdWorkorder", submitForApproval, BODY_DTO(submitForApprovalrDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execsubmitForApproval(dto));
	}

	// 3.3 ��ʾ��������
	Uint64JsonVO::Wrapper execsubmitForApproval(const submitForApprovalDTO::Wrapper& dto);

};
// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _ADDPRODWORKORDER_CONTROLLER_
#pragma once
#ifndef _PROWORKORDER_CONTROLLER_
#define _PROWORKORDER_CONTROLLER_
#include "domain/vo/BaseJsonVO.h"
#include "../mes-c4-prodmgmt/domain/vo/ProdWorkorder/ModifyProWorkorderVO.h"
#include "../mes-c4-prodmgmt/domain/dto/ProdWorkorder/ModifyProWorkorderDTO.h"

#include "../mes-c4-prodmgmt/domain/dto/ProdWorkorder/DeleteProWorkorderDTO.h"
#include "../mes-c4-prodmgmt/domain/vo/ProdWorkorder/DeleteProWorkorderVO.h"

#include "../mes-c4-prodmgmt/domain/dto/ProdWorkorder/ConfirmProWorkorderDTO.h"
#include "../mes-c4-prodmgmt/domain/vo/ProdWorkorder/ConfirmProWorkorderVO.h"

#include "../mes-c4-prodmgmt/domain/dto/ProdWorkorder/CompleteProWorkorderDTO.h"
#include "../mes-c4-prodmgmt/domain/vo/ProdWorkorder/CompleteProWorkorderVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ��������
 */
class ProWorkorderController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(ProWorkorderController);
	// 3 ����ӿ�
public:
	// �����޸Ľӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("ProdWorkorder.put.summary"), modifyProWorkorder, ModifyProWorkorderJsonVO::Wrapper);
	// �����޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/ProdWorkorder/modify", modifyProWorkorder, BODY_DTO(ModifyProWorkorderDTO::Wrapper, dto), execModifyProWorkdorder(dto));


	// ����ɾ���ӿ�����
	ENDPOINT_INFO(removeProWorkorder) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("ProdWorkorder.delete.summary"), DeleteProWorkorderJsonVO::Wrapper);
		// ��������·������˵��
		API_DEF_ADD_PATH_PARAMS(UInt64, "workorderId", ZH_WORDS_GETTER("ProdWorkorder.field.workorderId"), 1, true);
	}
	// ����ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/ProdWorkorder/Delete{workorderId}", removeProWorkorder, PATH(UInt64, workorderId), execRemoveProWorkorder(workorderId));


	// ����ȷ�Ͻӿ�����
	ENDPOINT_INFO( confirmProWorkorder) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("ProdWorkorder.confirm.summary"), ConfirmProWorkorderJsonVO::Wrapper);
		// ��������·������˵��
		API_DEF_ADD_PATH_PARAMS(UInt64, "workorderId", ZH_WORDS_GETTER("ProdWorkorder.field.workorderId"), 1, true);
	}
	// ����ȷ�Ͻӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/ProdWorkorder/Confirm{workorderId}", confirmProWorkorder, PATH(UInt64, workorderId), execConfirmProWorkorder(workorderId));


	// ������ɽӿ�����
	ENDPOINT_INFO(completeProWorkorder) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("ProdWorkorder.complete.summary"), CompleteProWorkorderJsonVO::Wrapper);
		// ��������·������˵��
		API_DEF_ADD_PATH_PARAMS(UInt64, "workorderId", ZH_WORDS_GETTER("ProdWorkorder.field.workorderId"), 1, true);
	}
	// ������ɽӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/ProdWorkorder/Complete{workorderId}", completeProWorkorder, PATH(UInt64, workorderId), execCompleteProWorkorder(workorderId));


private:
	// �޸�����
	ModifyProWorkorderJsonVO::Wrapper execModifyProWorkdorder(const ModifyProWorkorderDTO::Wrapper& dto);

	// ɾ������
	DeleteProWorkorderJsonVO::Wrapper execRemoveProWorkorder(const UInt64& workorderId);

	// ȷ������
	ConfirmProWorkorderJsonVO::Wrapper execConfirmProWorkorder(const UInt64& workorderId);

	// �������
	CompleteProWorkorderJsonVO::Wrapper execCompleteProWorkorder(const UInt64& workorderId);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _PROWORKORDER_CONTROLLER_
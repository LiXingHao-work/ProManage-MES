#pragma once
#ifndef _PROWORKORDER_CONTROLLER_
#define _PROWORKORDER_CONTROLLER_
#include "domain/vo/BaseJsonVO.h"
#include "../mes-c4-prodmgmt/domain/vo/ProdWorkorder/ModifyProWorkorderVO.h"
#include "../mes-c4-prodmgmt/domain/dto/ProdWorkorder/ModifyProWorkorderDTO.h"

#include "../mes-c4-prodmgmt/domain/dto/ProdWorkorder/DeleteProWorkorderDTO.h"
#include "../mes-c4-prodmgmt/domain/vo/ProdWorkorder/DeleteProWorkorderVO.h"


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
	// 3.1 �����޸Ľӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("ProdWorkorder.put.summary"), modifyProWorkorder, ModifyProWorkorderJsonVO::Wrapper);
	// 3.2 �����޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/ProdWorkorder/modify", modifyProWorkorder, BODY_DTO(ModifyProWorkorderDTO::Wrapper, dto), execModifyProWorkdorder(dto));

	// 3.1 ����ɾ���ӿ�����
	ENDPOINT_INFO(removeProWorkorder) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("ProdWorkorder.delete.summary"), DeleteProWorkorderJsonVO::Wrapper);
		// ��������·������˵��
		API_DEF_ADD_PATH_PARAMS(UInt64, "workorderId", ZH_WORDS_GETTER("ProdWorkorder.field.workorderId"), 1, true);
	}
	// 3.2 ����ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/ProdWorkorder/{workorderId}", removeProWorkorder, PATH(UInt64, workorderId), execRemoveProWorkorder(workorderId));


private:
	// 3.3 ��ʾ�޸�����
	Uint64JsonVO::Wrapper execModifyProWorkdorder(const ModifyProWorkorderDTO::Wrapper& dto);

	// 3.3 ��ʾɾ������
	Uint64JsonVO::Wrapper execRemoveProWorkorder(const UInt64& workorderId);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _PROWORKORDER_CONTROLLER_
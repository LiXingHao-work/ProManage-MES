#pragma once
#ifndef _ADDPRODWORKORDER_CONTROLLER_
#define _ADDPRODWORKORDER_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "../mes-c4-prodmgmt/domain/do/ProdWorkorder/AddProdWorkorderDO.h"
#include "../mes-c4-prodmgmt/domain/dto/ProdWorkorder/AddProdWorkorderDTO.h"
#include "../mes-c4-prodmgmt/domain/vo/ProdWorkorder/AddProdWorkorderVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ��������������
 */
class AddProdWorkorderController : public oatpp::web::server::api::ApiController {// 1 �̳п�����
	// 2 ����������������
	API_ACCESS_DECLARE(AddProdWorkorderController);
	// 3 ����ӿ�
public:

	// 3.1 ���������ӿ�����
	ENDPOINT_INFO(addProdWorkorder) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("addprodworkorder.post.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}

	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/ProdWorkorder", addProdWorkorder, BODY_DTO(AddProdWorkorderDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddProdWorkorder(dto));
	}

	// 3.3 ��ʾ��������
	Uint64JsonVO::Wrapper execAddProdWorkorder(const AddProdWorkorderDTO::Wrapper& dto);
};
// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _ADDPRODWORKORDER_CONTROLLER_
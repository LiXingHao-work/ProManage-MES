#pragma once
#ifndef _ADD_CONTROLLER_H_
#define _ADD_CONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "../../domain/vo/add-mj/AddVO.h"


#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * ��Ŀ�ƻ�������
 */
class AddController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(AddController);
public:
	
	// 3.1 ���������ӿ�����
	ENDPOINT_INFO(addTable) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("add-mj.add.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/inspection-maintenanceitems/add-item", addTable, BODY_DTO(AddDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddSample(dto));
	}
private: // ����ӿ�ִ�к���
	// 3.3 ��ʾ��������
	Uint64JsonVO::Wrapper execAddSample(const AddDTO::Wrapper& dto);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_FILECONTROLLER_H_
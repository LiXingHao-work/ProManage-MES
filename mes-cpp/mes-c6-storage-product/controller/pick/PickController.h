#pragma once

#ifndef _PICK_CONTROLLER_
#define _PICK_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/pick/PickQuery.h"
#include "domain/dto/pick/PickDTO.h"
#include "domain/vo/pick/PickVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class PickController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(PickController);
	// 3 ����ӿ�
public:

	// 3.1 ���������ӿ�����
	ENDPOINT_INFO(addPick) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("pick.post.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/pick", addPick, BODY_DTO(PickDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddPick(dto));
	}

private:
	// 3.3 ��ʾ��������
	Uint64JsonVO::Wrapper execAddPick(const PickDTO::Wrapper& dto);
	// 3.3 ��ʾ�޸�����
	//Uint64JsonVO::Wrapper execModifySample(const PickDTO::Wrapper& dto);

};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _PICK_CONTROLLER_
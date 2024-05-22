#pragma once

#ifndef _ADDWORKSTATION_CONTROLLER_H_
#define _ADDWORKSTATION_CONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/GlobalInclude.h"
#include "domain/dto/WorkStation/AddWorkStationDTO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class AddWorkStationController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(AddWorkStationController);
	// 3 ����ӿ�
public:
	// 3.1 ���������ӿ�����
	ENDPOINT_INFO(addWorkStation) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("workstation.add.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/ws/add-ws", addWorkStation, BODY_DTO(AddWorkStationDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddWorkStation(dto));
	}

private:
	// 3.3 ��������վ
	Uint64JsonVO::Wrapper execAddWorkStation(const AddWorkStationDTO::Wrapper& dto);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_
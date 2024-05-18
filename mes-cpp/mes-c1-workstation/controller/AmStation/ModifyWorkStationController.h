#pragma once

#ifndef _MODIFYWORKSTATION_CONTROLLER_H_
#define _MODIFYWORKSTATION_CONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/GlobalInclude.h"
#include "domain/dto/AmStation/AddWorkStationDTO.h"
#include "domain/vo/AmStation/AddWorkStationVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class ModifyWorkStationController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(ModifyWorkStationController);
	// 3 ����ӿ�
public:
	// 3.1 �����޸Ľӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("amstation.modify.summary"), modifyWorkStation, Uint64JsonVO::Wrapper);
	// 3.2 �����޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/AmStation/modify-workstation", modifyWorkStation, BODY_DTO(AddWorkStationDTO::Wrapper, dto), execModifyWorkStation(dto));

private:
	// 3.3 �޸Ĺ���վ
	Uint64JsonVO::Wrapper execModifyWorkStation(const AddWorkStationDTO::Wrapper& dto);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_
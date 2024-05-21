#pragma once
#ifndef _ADDWHSTORAGEORDERCONTROLLER_H_
#define _ADDWHSTORAGEORDERCONTROLLER_H_

#include "../../../domain/vo/ProchAndStorage/MaterialsInfo/AddWhStorageorderVO.h"
#include "../../../domain/dto/ProchAndStorage/MaterialsInfo/AddWhStorageorderDTO.h"
//0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController)   //<- Begin Codegen

class AddWhStorageorderController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(AddWhStorageorderController);
	// 3 ����ӿ�
public:
	//3.1 ���������ӿ�����
	ENDPOINT_INFO(addWhStorageorder) {
		//����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("whstorageorder.add.summary"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(AddWhPageStorageorderVO);
	}
	//3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/ProchAndStorage/MaterialsInfo", addWhStorageorder, BODY_DTO(AddWhPageStorageorderDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		//����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddWhStorageorder(dto));
	}
private://����ӿ�ִ�к���
	//��ʾ��������
	AddWhPageStorageorderVO::Wrapper execAddWhStorageorder(const AddWhPageStorageorderDTO::Wrapper& dto);

};
// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // _ADDWHSTORAGEORDERCONTROLLER_H_
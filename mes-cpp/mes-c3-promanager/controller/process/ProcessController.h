#pragma once
#ifndef _PROCESS_CONTROLLER_
#define _PROCESS_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"


// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ��������-�������̿�����
 */
class ProcessController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(ProcessController);
public:
	// 3.1 �����ѯ�ӿ�����
	
	// 3.2 �����ѯ�ӿڴ���
	
	//�����ӿڶ��塢������


private:
	// 3.3 ��ʾ��ҳ��ѯ����


};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_


#pragma once
#ifndef _SET_CONTROLLER_
#define _SET_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * ��������-��������ģ�������
 */
class SetController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(SetController);
	// 3 ����ӿ�

public:


private:

};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_


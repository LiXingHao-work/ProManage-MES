#pragma once


#ifndef _SETPROADD_DTO_
#define _SETPROADD_DTO_
#include "../../GlobalInclude.h"
/**
* ��ӹ����Լ��޸Ĺ�����DTO
*/
#include OATPP_CODEGEN_BEGIN(DTO)
class SetProAddTableDTO : public oatpp::DTO
{
	DTO_INIT(SetProAddTableDTO, DTO);
	//Ψһ��ʶ
	API_DTO_FIELD_DEFAULT(String, processId, ZH_WORDS_GETTER("set.fields.processid"));
	//�������
	API_DTO_FIELD_DEFAULT(String, processCode, ZH_WORDS_GETTER("set.fields.processcode"));
	//��������
	API_DTO_FIELD_DEFAULT(String, processName, ZH_WORDS_GETTER("set.fields.processname"));
	//�Ƿ�����
	API_DTO_FIELD(String, enableFlag, ZH_WORDS_GETTER("set.fields.enableflag"),true,"Y");
	//����˵��
	API_DTO_FIELD_DEFAULT(String, attention, ZH_WORDS_GETTER("set.fields.attention"));
	//��ע
	API_DTO_FIELD(String, remark, ZH_WORDS_GETTER("set.fields.remark"),true,"");
};
//class SetProAddTablePageDTO : public PageDTO<SetProAddTableDTO::Wrapper>
//{
//	DTO_INIT(SetProAddTablePageDTO, PageDTO<SetProAddTableDTO::Wrapper>);
//};
#include OATPP_CODEGEN_END(DTO)
#endif // _USERDTO_H_
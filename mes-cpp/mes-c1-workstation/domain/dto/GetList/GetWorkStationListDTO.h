#pragma once

#ifndef _GETWORKSTATIONLIST_DTO_H_
#define _GETWORKSTATIONLIST_DTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����վ�б�����ģ��
 */
class GetWorkStationListDTO : public oatpp::DTO
{
	DTO_INIT(GetWorkStationListDTO, DTO);
	// Ψһ��ʶ������վID��
	API_DTO_FIELD_DEFAULT(UInt64, workstationId, ZH_WORDS_GETTER("getlist.fields.workstationId"));
	// ����վ���
	API_DTO_FIELD_DEFAULT(String, workstationCode, ZH_WORDS_GETTER("getlist.fields.workstationCode"));
	//����վ����
	API_DTO_FIELD_DEFAULT(String, workstationName, ZH_WORDS_GETTER("getlist.fields.workstationCode"));
	// ����վ�ص�
	API_DTO_FIELD_DEFAULT(String, workstationAddress, ZH_WORDS_GETTER("getlist.fields.workstationAddress"));
	//���ڳ��������
	API_DTO_FIELD_DEFAULT(String, workshopName, ZH_WORDS_GETTER("getlist.fields.workshopName"));
	//�������򣨹������ƣ�
	API_DTO_FIELD_DEFAULT(String, processName, ZH_WORDS_GETTER("getlist.fields.processName"));
	//�Ƿ����á���Ĭ��ֵ'Y'
	API_DTO_FIELD(String, enableFlag, ZH_WORDS_GETTER("getlist.fields.enableFlag"), true, "Y");
	//��ע
	API_DTO_FIELD(String, remark, ZH_WORDS_GETTER("getlist.fields.remark"),true,"");
};


/**
 * ����һ������վ�б��ҳ�������
 */
class GetWorkStationListPageDTO : public PageDTO<GetWorkStationListDTO::Wrapper>
{
	DTO_INIT(GetWorkStationListPageDTO, PageDTO<GetWorkStationListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // _USERDTO_H_
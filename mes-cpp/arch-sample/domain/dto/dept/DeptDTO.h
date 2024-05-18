#pragma once
#ifndef _DEPTDTO_H_
#define _DEPTDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
//�����б�����ģ��
class DeptTableDTO :public oatpp::DTO
{
	DTO_INIT(DeptTableDTO, DTO);
	//Ψһ��ʶ ����
	API_DTO_FIELD(UInt64, deptId, ZH_WORDS_GETTER("dept.fields.id"), true, 1);
	//��������
	API_DTO_FIELD(String, deptName, ZH_WORDS_GETTER("dept.fields.dname"), true, "01star");
	//��������
	API_DTO_FIELD(Int32, orderName, ZH_WORDS_GETTER("dept.fields.order"), true, 0);
	//״̬
	API_DTO_FIELD(Int32, status, ZH_WORDS_GETTER("dept.fields.dstatus"), true, 0);
	//����ʱ��
	API_DTO_FIELD(String, createTime, ZH_WORDS_GETTER("dept.fields.ctime"), true, "2024-05-17 00:00:00");
	
};
//������������ģ��
class DeptDetailDTO :public DeptTableDTO
{
	DTO_INIT(DeptDetailDTO, DeptTableDTO);
	//������
	API_DTO_FIELD(String, leader, ZH_WORDS_GETTER("dept.fields.leader"), true, "����");
	

};

#include OATPP_CODEGEN_END(DTO)
#endif
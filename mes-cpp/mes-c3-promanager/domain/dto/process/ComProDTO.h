#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/26 23:47:08

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#ifndef _COMPRODTO_H_
#define _COMPRODTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ɹ����б����
 */
class ComProListDTO : public oatpp::DTO
{
	//��ʼ��
	DTO_INIT(ComProListDTO, DTO);
	//�ֶ�	
	//Ψһ��ʶ
	API_DTO_FIELD_DEFAULT(UInt64, process_id, ZH_WORDS_GETTER("pro.fields.proId"));
	//�������
	API_DTO_FIELD_DEFAULT(String, process_code, ZH_WORDS_GETTER("pro.fields.proCode"));
	//��������
	API_DTO_FIELD_DEFAULT(String, process_name, ZH_WORDS_GETTER("pro.fields.proName"));
	//�Ƿ�Ϊ�ؼ�����
	API_DTO_FIELD_DEFAULT(String, key_flag, ZH_WORDS_GETTER("pro.fields.key_flag"),true,"No");
	//��һ������
	API_DTO_FIELD_DEFAULT(String, next_process_name, ZH_WORDS_GETTER("pro.fields.proName"), false, "01star");
	//��һ���Ĺ����ϵ
	API_DTO_FIELD_DEFAULT(String, link_type, ZH_WORDS_GETTER("pro.fields.type"), false, "01star");

};

/*
�޸���ɹ���
*/
class ModifyProDTO : public oatpp::DTO
{
	//��ʼ��
	DTO_INIT(ModifyProDTO, DTO);
	//�ֶ�

	//���
	API_DTO_FIELD_DEFAULT(UInt64, process_id, ZH_WORDS_GETTER("pro.fields.proId"));
	//�������
	API_DTO_FIELD_DEFAULT(String, process_code, ZH_WORDS_GETTER("pro.fields.proCode"));
	//��������
	API_DTO_FIELD_DEFAULT(String, process_name, ZH_WORDS_GETTER("pro.fields.proName"));
	//�Ƿ�Ϊ�ؼ�����
	API_DTO_FIELD_DEFAULT(String, key_flag, ZH_WORDS_GETTER("pro.fields.key_flag"), true, "No");
	//��һ������
	API_DTO_FIELD_DEFAULT(String, next_process_name, ZH_WORDS_GETTER("pro.fields.proName"), false, "01star");
	//��һ���Ĺ����ϵ
	API_DTO_FIELD_DEFAULT(String, link_type, ZH_WORDS_GETTER("pro.fields.type"), false, "01star");

};
/*
������ɹ���
*/
class NewProcessDTO : public ModifyProDTO
{
	//��ʼ��
	DTO_INIT(NewProcessDTO, ModifyProDTO);
	//�ֶ�
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_ROLISTDTO_H_
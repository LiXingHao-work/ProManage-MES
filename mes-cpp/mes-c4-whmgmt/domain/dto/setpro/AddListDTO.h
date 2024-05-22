#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:59:38

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
#ifndef _ADDLIST_DTO_
#define _ADDLIST_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ���������
 */
class AddListDTO : public oatpp::DTO
{
	DTO_INIT(AddListDTO, DTO);

	//���ϵ����
//	API_DTO_FIELD_DEFAULT(String, issuecode, ZH_WORDS_GETTER("addlist.field.issuecode"));
	
	//���ϵ����
	DTO_FIELD(String, issuecode);
	DTO_FIELD_INFO(issuecode) {
		info->description = ZH_WORDS_GETTER("addlist.field.issuecode");
	}
	//���ϵ�����
	API_DTO_FIELD_DEFAULT(String, issuename, ZH_WORDS_GETTER("addlist.field.issuename"));

	//������id
	API_DTO_FIELD_DEFAULT(UInt64, workorderid, ZH_WORDS_GETTER("addlist.field.workorderid"));

	//��id
	API_DTO_FIELD_DEFAULT(UInt64, clientid, ZH_WORDS_GETTER("addlist.field.clientid"));

	//�ͻ�����
	API_DTO_FIELD_DEFAULT(String, clientname, ZH_WORDS_GETTER("addlist.field.clientname"));
	

};


#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_
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
#ifndef _ADD_DTO_H_
#define _ADD_DTO_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��Ŀ�б�
 */
class AddDTO : public oatpp::DTO
{
	DTO_INIT(AddDTO, DTO);
	// ��Ŀ����
	API_DTO_FIELD_DEFAULT(String, subjectCode, ZH_WORDS_GETTER("add-mj.fields.scode"));
	//��Ŀ����
	API_DTO_FIELD_DEFAULT(String, subjectName, ZH_WORDS_GETTER("add-mj.fields.sname"));
	//��Ŀ����
	API_DTO_FIELD_DEFAULT(String, subjectType, ZH_WORDS_GETTER("add-mj.fields.stype"));
	//�Ƿ�����
	API_DTO_FIELD_DEFAULT(String, attr3, ZH_WORDS_GETTER("add-mj.fields.attr3"));
	//��Ŀ����
	API_DTO_FIELD_DEFAULT(String, subjectContent, ZH_WORDS_GETTER("add-mj.fields.scontent"));
	//��׼
	API_DTO_FIELD_DEFAULT(String, subjectStandard, ZH_WORDS_GETTER("add-mj.fields.sstandard"));
};



#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_
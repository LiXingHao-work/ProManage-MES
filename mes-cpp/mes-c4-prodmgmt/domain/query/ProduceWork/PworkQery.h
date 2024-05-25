#pragma once
#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:36:29

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
#ifndef _SAMPLE_QUERY_
#define _SAMPLE_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��ȡ���������ѯ
 */
class PworkQery : public PageQuery
{
	DTO_INIT(PworkQery, PageQuery);
	 
	// ��������
	API_DTO_FIELD_DEFAULT(String, feedback_type, ZH_WORDS_GETTER("ProduceWork.fields.feedback_type"));
	 
	// ����վ����
	API_DTO_FIELD_DEFAULT(String, workstation_name, ZH_WORDS_GETTER("ProduceWork.fields.workstation_name"));

	// �����������
	API_DTO_FIELD_DEFAULT(String, workorder_code, ZH_WORDS_GETTER("ProduceWork.fields.workorder_code"));

	//��Ʒ���ϱ���
	API_DTO_FIELD_DEFAULT(String, item_code, ZH_WORDS_GETTER("ProduceWork.fields.item_code"));

	//��Ʒ��������
	API_DTO_FIELD_DEFAULT(String, item_name, ZH_WORDS_GETTER("ProduceWork.fields.item_name"));

	//������
	API_DTO_FIELD_DEFAULT(String, user_name, ZH_WORDS_GETTER("ProduceWork.fields.user_name"));

	//��¼��
	API_DTO_FIELD_DEFAULT(String, record_user, ZH_WORDS_GETTER("ProduceWork.fields.record_user"));

	//״̬(0���� 1ͣ��)
	API_DTO_FIELD_DEFAULT(String, status  , ZH_WORDS_GETTER("ProduceWork.fields.status"));

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_
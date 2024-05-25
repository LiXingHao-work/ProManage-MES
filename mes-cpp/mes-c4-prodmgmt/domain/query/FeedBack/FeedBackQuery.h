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
 * ʾ����ҳ��ѯ����
 */
class FeedBackQuery : public PageQuery
{
	DTO_INIT(FeedBackQuery, PageQuery);
	// ��������
	API_DTO_FIELD_DEFAULT(String, feedbackType, ZH_WORDS_GETTER("prod.query.summary.feedbackType"));
	// ����վ
	API_DTO_FIELD_DEFAULT(String, workstationName, ZH_WORDS_GETTER("prod.query.summary.workstationName"));
	// �����������
	API_DTO_FIELD_DEFAULT(String, workorderCode, ZH_WORDS_GETTER("prod.query.summary.workorderCode"));
	// ��Ʒ���ϱ���
	API_DTO_FIELD_DEFAULT(String, itemCode, ZH_WORDS_GETTER("prod.query.summary.itemCode"));
	// ��Ʒ������
	API_DTO_FIELD_DEFAULT(String, itemName, ZH_WORDS_GETTER("prod.query.summary.itemName"));
	// ����ͺ�
	API_DTO_FIELD_DEFAULT(String, specification, ZH_WORDS_GETTER("prod.query.summary.specification"));
	// ��������
	API_DTO_FIELD_DEFAULT(Int32, feedbackQuantity, ZH_WORDS_GETTER("prod.query.summary.feedbackQuantity"));
	// ������
	API_DTO_FIELD_DEFAULT(String, userName, ZH_WORDS_GETTER("prod.query.summary.userName"));
	// ����ʱ��
	API_DTO_FIELD_DEFAULT(String, feedbackTime, ZH_WORDS_GETTER("prod.query.summary.feedbackTime"));
	// �����
	API_DTO_FIELD_DEFAULT(String, recordUser, ZH_WORDS_GETTER("prod.query.summary.recordUser"));
	// ״̬
	API_DTO_FIELD_DEFAULT(String, status, ZH_WORDS_GETTER("prod.query.summary.status"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_QUERY_
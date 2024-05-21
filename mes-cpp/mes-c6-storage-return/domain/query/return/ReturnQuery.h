#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/12/03 11:01:02

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
#ifndef _RETURNQUERY_H_
#define _RETURNQUERY_H_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ����ѯ�û���Ϣ�����ݴ���ģ��
 */
class ReturnQuery : public PageQuery
{
	// �����ʼ��
	DTO_INIT(ReturnQuery, PageQuery);
	// �˻������
	API_DTO_FIELD_DEFAULT(UInt64, returnId, ZH_WORDS_GETTER("return.fields.rtid"));
	// �˻�������
	API_DTO_FIELD(String, returnName, ZH_WORDS_GETTER("return.fields.rtname"), true, "01star");
	// �ɹ������
	API_DTO_FIELD_DEFAULT(UInt64, purchaseId, ZH_WORDS_GETTER("return.fields.rtid"));
	// ��Ӧ������
	API_DTO_FIELD(String, vendorName, ZH_WORDS_GETTER("return.fields.rtname"), true, "01star");

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_RETURNQUERY_H_
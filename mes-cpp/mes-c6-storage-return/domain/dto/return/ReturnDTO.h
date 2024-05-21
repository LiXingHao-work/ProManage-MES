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
#ifndef _RETURNDTO_H_
#define _RETURNDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
 * ����һ���޸Ĺ�Ӧ���˻���Ϣ�����ݴ���ģ��
 */
class ReturnDTO : public oatpp::DTO
{
	DTO_INIT(ReturnDTO, DTO);
	//
	// �˻������
	API_DTO_FIELD_DEFAULT(UInt64, returnId, ZH_WORDS_GETTER("return.fields.rtid"));
	/*DTO_FIELD(UInt64, rtid);
	DTO_FIELD_INFO(rtid) {
		info->description = ZH_WORDS_GETTER("return.field.rtid");
	}*/
	// �˻�������
	API_DTO_FIELD(String, returnName, ZH_WORDS_GETTER("return.fields.rtname"), true, "01star");
	// �ɹ������
	API_DTO_FIELD_DEFAULT(String, purchaseId, ZH_WORDS_GETTER("return.fields.rtid"));
	// ��Ӧ�̱���
	API_DTO_FIELD_DEFAULT(String, vendorCode, ZH_WORDS_GETTER("return.fields.rtid"));
	// ��Ӧ������
	API_DTO_FIELD(String, vendorName, ZH_WORDS_GETTER("return.fields.rtname"), true, "01star");
	// �˻�����
	API_DTO_FIELD(String, returndate, ZH_WORDS_GETTER("storage.fields.rtdate"), true, "2024-5-21");
	// ����״̬
	API_DTO_FIELD(Int32, status, ZH_WORDS_GETTER("storage.fields.status"), true, 0);
	// ����
};

/**
 * ����һ��������Ϣ��ҳ�������
 */
class ReturnPageDTO : public PageDTO<ReturnDTO::Wrapper>
{
	DTO_INIT(ReturnPageDTO, PageDTO<ReturnDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // _RETURNDTO_H_
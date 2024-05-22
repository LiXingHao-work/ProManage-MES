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
#ifndef _SAMPLE_DTO_
#define _SAMPLE_DTO_
#include "../../GlobalInclude.h"
#include "ApiHelper.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ��������
 */
class PworkTableDTO : public oatpp::DTO
{
	DTO_INIT(PworkTableDTO, DTO);
	
	//��¼IDrecord_id
	API_DTO_FIELD_DEFAULT(UInt64, record_id, ZH_WORDS_GETTER("ProduceWork.fields.record_id"));
	//API_DTO_FIELD(UInt64, record_id, ZH_WORDS_GETTER("ProduceWork.fields.record_id"), true, 0);

	// ��������
	API_DTO_FIELD(String, feedback_type, ZH_WORDS_GETTER("ProduceWork.fields.feedback_type"),true,"���б���");

	// ����վ����
	API_DTO_FIELD_DEFAULT(String, workstation_name, ZH_WORDS_GETTER("ProduceWork.fields.workstation_name"));

	// �����������
	API_DTO_FIELD_DEFAULT(String, workorder_code, ZH_WORDS_GETTER("ProduceWork.fields.workorder_code"));

	//��Ʒ���ϱ���
	API_DTO_FIELD_DEFAULT(String, item_code, ZH_WORDS_GETTER("ProduceWork.fields.item_code"));

	//��Ʒ��������
	API_DTO_FIELD_DEFAULT(String, item_name, ZH_WORDS_GETTER("ProduceWork.fields.item_name"));


	//����ͺ�
	API_DTO_FIELD(String, specification, ZH_WORDS_GETTER("ProduceWork.fields.specification"), true, "��ɫ");

	//��������
	API_DTO_FIELD(String, quantity_feedback, ZH_WORDS_GETTER("ProduceWork.fields.quantity_feedback"), true, "0");

	//������
	API_DTO_FIELD_DEFAULT(String, user_name, ZH_WORDS_GETTER("ProduceWork.fields.user_name"));

	//����ʱ��
	API_DTO_FIELD(String, feedback_time, ZH_WORDS_GETTER("ProduceWork.fields.feedback_time"), true, "��");

	//�����
	//API_DTO_FIELD_DEFAULT(String, , ZH_WORDS_GETTER("ProduceWork.fields."));

	//״̬(0���� 1ͣ��)
	API_DTO_FIELD_DEFAULT(String, status, ZH_WORDS_GETTER("ProduceWork.fields.status"));
	
};
class PworkDetailDTO : public PworkTableDTO {
	DTO_INIT(PworkDetailDTO, PworkTableDTO);

	//���������
	API_DTO_FIELD(String, quantity_uncheck, ZH_WORDS_GETTER("ProduceWork.fields.quantity_uncheck"), true, "û��"); 
	//����������
};
/**
 * ʾ����ҳ�������
 */
class SamplePageDTO : public PageDTO<PworkTableDTO::Wrapper>
{
	DTO_INIT(SamplePageDTO, PageDTO<PworkTableDTO::Wrapper>);

};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_
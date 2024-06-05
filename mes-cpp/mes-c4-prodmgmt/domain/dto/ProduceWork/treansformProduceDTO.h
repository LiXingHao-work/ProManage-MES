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
#ifndef _TS_DTO_
#define _TS_DTO_
#include "../../GlobalInclude.h"
#include "ApiHelper.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ������������
 */
class treansformProduceDTO : public oatpp::DTO
{
	DTO_INIT(treansformProduceDTO, DTO);

	//��������
	API_DTO_FIELD_DEFAULT(String, feedback_type, ZH_WORDS_GETTER("ProduceWork.add.feedback_type"));
	//API_DTO_FIELD(UInt64, record_id, ZH_WORDS_GETTER("ProduceWork.fields.record_id"), true, 0);

	// ��������  - ���ع�������
	API_DTO_FIELD(String, feedback_code, ZH_WORDS_GETTER("ProduceWork.add.feedback_code"), true, ZH_WORDS_GETTER("ProduceWork.moren.feedback_type"));

	// �������� - ���� ����������
	API_DTO_FIELD_DEFAULT(String, task_code, ZH_WORDS_GETTER("ProduceWork.add.task_code"));

	// ���ű���
	API_DTO_FIELD_DEFAULT(String, product_code, ZH_WORDS_GETTER("ProduceWork.add.product_code"));

	//��Ʒ����
	API_DTO_FIELD_DEFAULT(String, product_name, ZH_WORDS_GETTER("ProduceWork.add.product_na	me"));

	//��λ
	API_DTO_FIELD_DEFAULT(String, unit_of_measure, ZH_WORDS_GETTER("ProduceWork.add.unit_of_measure"));

	//�������
	API_DTO_FIELD(String, product_spc, ZH_WORDS_GETTER("ProduceWork.add.product_spc"), true, "��ɫ");

	//��������
	API_DTO_FIELD(String, quantity_feedback, ZH_WORDS_GETTER("ProduceWork.add.quantity_feedback"), true, "0");

	//���������
	API_DTO_FIELD_DEFAULT(String, quantity_uncheck, ZH_WORDS_GETTER("ProduceWork.add.quantity_uncheck"));

	//������
	API_DTO_FIELD(String, nick_name, ZH_WORDS_GETTER("ProduceWork.add.nick_nameA"), true, "��");

	//�����
	//API_DTO_FIELD_DEFAULT(String, nick_name, ZH_WORDS_GETTER("ProduceWork.add.nick_nameB"));

	//����ʱ��
	API_DTO_FIELD_DEFAULT(String, feedback_time, ZH_WORDS_GETTER("ProduceWork.add.feedback_time"));

	//��ע
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("ProduceWork.add.remark"));

};



#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_
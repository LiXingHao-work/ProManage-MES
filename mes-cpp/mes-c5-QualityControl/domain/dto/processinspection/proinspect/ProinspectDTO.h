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
#ifndef _PROINSPECT_DTO_H_
#define _PROINSPECT_DTO_H_
#include "../../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ʾ���������
 */
class  ProinspectDTO : public oatpp::DTO
{
	DTO_INIT(ProinspectDTO, DTO);
	// ȱ��ID
	DTO_FIELD(UInt64, record_id);
	DTO_FIELD_INFO(record_id) {
		info->description = ZH_WORDS_GETTER("qualitycontrol.defect.record_id");
	}
	// ���鵥����
	DTO_FIELD(String, qc_type);
	DTO_FIELD_INFO(qc_type) {
		info->description = ZH_WORDS_GETTER("qualitycontrol.defect.qc_type");
	}
	//���鵥ID
	DTO_FIELD(UInt64, qc_id);
	DTO_FIELD_INFO(qc_id) {
		info->description = ZH_WORDS_GETTER("qualitycontrol.defect.qc_id");
	}
	// ���鵥��ID
	DTO_FIELD(UInt64, line_id);
	DTO_FIELD_INFO(line_id) {
		info->description = ZH_WORDS_GETTER("qualitycontrol.defect.line_id");
	}
	//���鵥��ID
	DTO_FIELD(String, defect_name);
	DTO_FIELD_INFO(defect_name) {
		info->description = ZH_WORDS_GETTER("qualitycontrol.defect.defect_name");
	}
	//ȱ�ݵȼ�
	DTO_FIELD(String, defect_level);
	DTO_FIELD_INFO(defect_level) {
		info->description = ZH_WORDS_GETTER("qualitycontrol.defect.defect_level");
	}

	//��ע
	DTO_FIELD(String, remark);
	DTO_FIELD_INFO(remark) {
		info->description = ZH_WORDS_GETTER("qualitycontrol.defect.remark");
	}
};



#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_
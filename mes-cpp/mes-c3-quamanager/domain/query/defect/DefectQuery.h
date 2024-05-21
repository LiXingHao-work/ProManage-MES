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
class DefectQuery : public PageQuery
{
	DTO_INIT(DefectQuery, PageQuery);
	// ȱ������
	DTO_FIELD(String, defect_name);
	DTO_FIELD_INFO(defect_name) {
		info->description = ZH_WORDS_GETTER("defect.field.defect_name");
	}
	// ���������
	DTO_FIELD(String, index_type);
	DTO_FIELD_INFO(index_type) {
		info->description = ZH_WORDS_GETTER("defect.field.index_type");
	}
	// ȱ�ݵȼ�
	DTO_FIELD(String, defect_level);
	DTO_FIELD_INFO(defect_level) {
		info->description = ZH_WORDS_GETTER("defect.field.defect_level");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_DEFECT_QUERY_
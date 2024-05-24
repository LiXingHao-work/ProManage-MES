#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: hejianwei
 @Date: 2024/05/24 10:08:32

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
#ifndef _REPAIRCONTENT_DO_
#define _REPAIRCONTENT_DO_
#include "../DoInclude.h"

/**
 * dv_repaircontent_line���ݿ�ʵ����
 */
class RepaircontentDO
{
	// ��id
	CC_SYNTHESIZE(uint64_t, line_id, line_Id);
	// ά�޵�id
	CC_SYNTHESIZE(uint64_t, repair_id, repair_Id);
	// ��Ŀid
	CC_SYNTHESIZE(uint64_t, subject_id, subject_Id);
	// ��Ŀ����
	CC_SYNTHESIZE(string, subject_code, subject_Code);
	//��Ŀ���� 
	CC_SYNTHESIZE(string, subject_name, subject_Name);
	//��Ŀ����
	CC_SYNTHESIZE(string, subject_type, subject_Type);
	//��Ŀ����
	CC_SYNTHESIZE(string, subject_content, subject_Content);
	//��������
	CC_SYNTHESIZE(string, malfunction, Malfunction);
	//����������Դ
	CC_SYNTHESIZE(string, malfunction_url, Malfunction_url);
	//ά�����
	CC_SYNTHESIZE(string, repair_des, repair_Des);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);
public:
	RepaircontentDO() {
		line_id = 1;
		repair_id = 1;
		subject_id = 1;
		subject_code = "";
		subject_name = "";
		subject_type = "";
		subject_content = "";
		malfunction = "";
		malfunction_url = "";
		repair_des = "";
		remark = "";
	}
};

#endif // !_REPAIRCONTENT_DO_

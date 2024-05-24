#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:52:32

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
#ifndef _DVMAINTEMRECORD_DO_	
#define _DVMAINTEMRECORD_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */

class DvMaintenRecordDO
{
	//��¼ID
	CC_SYNTHESIZE(uint64_t, recordId, RecordId);
	//�ƻ�ID
	CC_SYNTHESIZE(uint64_t, planId, PlanId);
	//�ƻ�����
	CC_SYNTHESIZE(string, planCode, PlanCode);
	//�ƻ�����
	CC_SYNTHESIZE(string, planName, PlanName);
	//�ƻ�����
	CC_SYNTHESIZE(string, planType, PlanType);
	//�豸ID
	CC_SYNTHESIZE(uint64_t, machineryId, MachineryId);
	//�豸����
	CC_SYNTHESIZE(string, machineryCode, MachineryCode);
	//�豸����
	CC_SYNTHESIZE(string, machineryName, MachineryName);
	//Ʒ��
	CC_SYNTHESIZE(string, machineryBrand, MachineryBrand);
	//����ͺ�
	CC_SYNTHESIZE(string, machinerySpec, MachinerySpec);
	//״̬
	CC_SYNTHESIZE(string, status, Status);
	//��ע
	CC_SYNTHESIZE(string, remark, Remark);
	//Ԥ���ֶ�1
	CC_SYNTHESIZE(string, attr1, Attr1);
	//Ԥ���ֶ�2
	CC_SYNTHESIZE(string, attr2, Attr2);
	//Ԥ���ֶ�3
	CC_SYNTHESIZE(uint64_t, attr3, Attr3);
	//Ԥ���ֶ�4
	CC_SYNTHESIZE(uint64_t, attr4, Attr4);
	//������
	CC_SYNTHESIZE(string, createBy, CreateBy);
	//������
	CC_SYNTHESIZE(string, updateBy, UpdateBy);

public:
	DvMaintenRecordDO() {
		recordId = 0;
		planId = 0;
		planCode = "";
		planName = "";
		planType = "";
		machineryId = 0;
		machineryCode = "";
		machineryName = "";
		machineryBrand = "";
		machinerySpec = "";
		status = "";
		remark = "";
		attr1 = "";
		attr2 = "";
		attr3 = 0;
		attr4 = 0;
		createBy = "";
		updateBy = "";
	}
};



#endif // !_DVMAINTEMRECORD_DO_

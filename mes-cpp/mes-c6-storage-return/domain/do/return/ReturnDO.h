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
#ifndef _RETURN_DO_
#define _RETURN_DO_
#include "../DoInclude.h"

/**
 * ���ݿ�ʵ����
 */
class ReturnDO
{
	// �˻���ID
	CC_SYNTHESIZE(uint64_t, returnID, returnid);
	// �˻������
	CC_SYNTHESIZE(string, returnCode, returncode);
	// �˻�������
	CC_SYNTHESIZE(string, returnName, returnname);
	// �ɹ������
	CC_SYNTHESIZE(string, purchaseCode, purchasecode);
	// ��Ӧ�̱���
	CC_SYNTHESIZE(string, vendorCode, vendorcode);
	// ��Ӧ������
	CC_SYNTHESIZE(string, vendorName, vendorname);
	// �˻�����
	CC_SYNTHESIZE(string, returnDate, returndate);
	// ����״̬
	CC_SYNTHESIZE(string, status, status);
	// ���κ�
	CC_SYNTHESIZE(string, batchCode, batchcode);
	// ��ע
	CC_SYNTHESIZE(string, remark, remark);
	// ������
	CC_SYNTHESIZE(string, updateBy, updateby);
	// ����ʱ��
	CC_SYNTHESIZE(string, updateTime, updatetime);
	// ������
	CC_SYNTHESIZE(string, createBy, createby);
	// ����ʱ��
	CC_SYNTHESIZE(string, createTime, createtime);
	// ��Ӧ��ID
	CC_SYNTHESIZE(uint64_t, vendorID, vendorid);
	// ��Ӧ�̼��
	CC_SYNTHESIZE(string, vendorNick, vendornick);
	
public:
	ReturnDO() {
		returnID = 0;
		returnCode = "0";
		returnName = "returnName";
		purchaseCode = "1";
		vendorCode = "2";
		vendorName = "vendorName";
		returnDate = "1234-12-31";
		status = "PREPARE";
		batchCode = "1234";
		remark = "null";
		updateBy = "updateBy";
		updateTime = "updateTime";
		createBy = "createBy";
		createTime = "createTime";
		vendorID = 0;
		vendorNick = "vendorNick";
	}
};

#endif // !_RETURN_DO_

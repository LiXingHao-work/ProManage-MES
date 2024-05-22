#pragma once

#ifndef _INCOMING_DO_
#define _INCOMING_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class IncomingDO
{
	// ���ϼ��鵥���
	CC_SYNTHESIZE(string, incomingCode, IncomingCode);
	// ��Ӧ�̱���
	CC_SYNTHESIZE(string, vendorCode, VendorCode);
	// ��Ӧ������
	CC_SYNTHESIZE(string, vendorName, VendorName);
	// ��Ӧ�����κ�
	CC_SYNTHESIZE(string, vendorBatch, VendorBatch);
public:
	IncomingDO() {
		incomingCode = "123456";
		vendorCode = "1234567";
		vendorCode = "������";
		vendorBatch = "12345678";
	}
};

#endif // !_INCOMING_DO_

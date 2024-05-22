#pragma once
#ifndef _DETECTIONTEMPLATE_DO_
#define _DETECTIONTEMPLATE_DO_

#include "../DoInclude.h"

class DetectionTemplateDO {
	// ���ģ��ID
	CC_SYNTHESIZE(uint64_t, template_id, tId);
	// ���ģ����
	CC_SYNTHESIZE(string, template_code, tCode);
	// ���ģ������
	CC_SYNTHESIZE(string, template_name, tName);
	// �������
	CC_SYNTHESIZE(string, qc_types, tTypes);
	// �Ƿ�����
	CC_SYNTHESIZE(string, enable_flag, tEnFlag);
	// ��ע
	//CC_SYNTHESIZE(string, remark, tRemark);

public:
	DetectionTemplateDO() {
		// ���ģ��ID
		template_id = 0;
		// ���ģ����
		template_code = "";
		// ���ģ������
		template_name = "";
		// �������
		qc_types = "";
		// �Ƿ�����
		enable_flag = "";
		// ��ע
		//remark = "";
	}
};

#endif // !_DETECTIONTEMPLATE_DO_

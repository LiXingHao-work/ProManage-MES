#pragma once
/*
* 
*/
#ifndef _PLANSUBJECT_DO_
#define _PLANSUBJECT_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class PlanSubjectDO
{
	// ��Ŀ����
	CC_SYNTHESIZE(string, code, Code);
	// ��Ŀ����
	CC_SYNTHESIZE(string, name, Name);
	// ��Ŀ����
	CC_SYNTHESIZE(string, type, Type);
	// ��Ŀ����
	CC_SYNTHESIZE(string, content, Content);
	// ��Ŀ��׼
	CC_SYNTHESIZE(string, standard, Standard);
public:
	PlanSubjectDO() {
		code = "";
		name = "";
		type = "";
		content = "";
		standard = "";
	}
};

#endif // !_PLANSUBJECT_DO_

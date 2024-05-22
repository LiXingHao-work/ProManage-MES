#pragma once
#ifndef _DETECTIONTEMPLATE_SERVICE_
#define _DETECTIONTEMPLATE_SERVICE_
#include <list>
#include "../../dao/detectiontemplate/DetectionTemplateDAO.h"


class DetectionTemplateService
{
public:

	//
	bool removeData(uint64_t id);
	// ��ȡ���ģ���б���, ��ҳ��ѯ��������
	DetectionTemplatePageDTO::Wrapper listAllTemplateList(const DetectionTemplateQuery::Wrapper& query);
	// ��������
	uint64_t saveData(const DetectionTemplateDTO::Wrapper& dto);
};

#endif // !_TEST_SERVICE_#pragma once

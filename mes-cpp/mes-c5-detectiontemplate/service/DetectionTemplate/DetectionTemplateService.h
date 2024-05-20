#pragma once
#ifndef _DETECTIONTEMPLATE_SERVICE_
#define _DETECTIONTEMPLATE_SERVICE_

#include <list>
#include "domain/vo/DetectionTemplate/DetectionTemplateVO.h"
#include "domain/query/DetectionTemplate/DetectionTemplateQuery.h"
#include "domain/dto/DetectionTemplate/DetectionTemplateDTO.h"

class DetectionTemplateService {
public:
	// ��ȡ���ģ���б���, ��ҳ��ѯ��������
	DetectionTemplatePageDTO::Wrapper listAllTemplateList(const DetectionTemplateQuery::Wrapper& query);
};


#endif // !_DETECTIONTEMPLATE_SERVICE_

#pragma once
#ifndef _DETECTIONTEMPLATE_DAO_
#define _DETECTIONTEMPLATE_DAO_

#include "BaseDAO.h"
#include "../../domain/do/DetectionTemplate/DetectionTemplateDO.h"
#include "../../domain/query/DetectionTemplate/DetectionTemplateQuery.h"

class DetectionTemplateDAO : public BaseDAO {
public:
	// ͳ�Ƽ��ģ����������
	uint64_t count(const DetectionTemplateQuery::Wrapper& query);
	// ���ģ���б���, ��ҳ��ѯ����
	list<DetectionTemplateDO> selectTemplateListWithPage(const DetectionTemplateQuery::Wrapper& query);

};

#endif // !_DETECTIONTEMPLATE_DAO_

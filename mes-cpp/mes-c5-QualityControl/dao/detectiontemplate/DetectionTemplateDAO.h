#pragma once
#ifndef _DETECTIONTEMPLATE_DAO_
#define _DETECTIONTEMPLATE_DAO_
#include "BaseDAO.h"
#include "../../domain/do/DetectionTemplate/DetectionTemplateDO.h"
#include "../../domain/query/detectiontemplate/DetectionTemplateQuery.h"
/**
 * ʾ�������ݿ����ʵ��
 */
class DetectionTemplateDAO : public BaseDAO
{
public:

	// ͨ��IDɾ������
	//int deleteById(uint64_t id);
	// ͳ�Ƽ��ģ����������
	uint64_t count(const DetectionTemplateQuery::Wrapper& query);
	// ���ģ���б���, ��ҳ��ѯ����
	//list<DetectionTemplateDO> selectTemplateListWithPage(const DetectionTemplateQuery::Wrapper& query);
	// ��������
	//uint64_t insert(const DetectionTemplateDO& iObj);
};
#endif // !_Ddt_DAO_
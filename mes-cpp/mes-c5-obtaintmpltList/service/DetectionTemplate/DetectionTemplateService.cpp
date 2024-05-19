#include "stdafx.h"
#include "DetectionTemplateService.h"
#include "dao/DetectionTemplate/DetectionTemplateDAO.h"

DetectionTemplatePageDTO::Wrapper DetectionTemplateService::listAllTemplateList(const DetectionTemplateQuery::Wrapper& query) {
	// �������ض���
	auto pages = DetectionTemplatePageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	DetectionTemplateDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0) {
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<DetectionTemplateDO> result = dao.selectTemplateListWithPage(query);
	// ��DOת����DTO
	for (DetectionTemplateDO sub : result) {
		auto dto = DetectionTemplateDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, template_id, tId, template_code, tCode, template_name, tName, enable_flag, tEnFlag, remark, tRemark);
		pages->addData(dto);
	}
	return pages;
}

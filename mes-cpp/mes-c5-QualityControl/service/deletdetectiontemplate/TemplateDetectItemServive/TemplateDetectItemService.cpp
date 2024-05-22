#include "stdafx.h"
#include "TemplateDetectItemService.h"
#include "../../../dao/detectiontemplate/templatedetectitem/TemplateDetectItemDAO.h"

TemplateDetectItemPageDTO::Wrapper TemplateDetectItemService::listAllTemplateDetectItem(const TemplateDetectItemQuery::Wrapper& query)
{
	auto pages = TemplateDetectItemPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	//��ѯ����������
	/*uint64_t count = 13;
	if (count <= 0)
	{
		return pages;
	}*/

	pages->total = 10;
	pages->calcPages();
	TemplateDetectItemDAO dao;
	list<TemplateDetectItemDO> result = dao.selectTemplateDetectItemWithPage(query);
	 //��DOת����DTO
	for (auto sub : result)
	{
		auto dto = TemplateDetectItemDTO::createShared();
		//ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, name, Name, sex, Sex, age, Age)
		dto->record_id = sub.getRecord_id();
		dto->template_id = sub.getTemplate_id();
		dto->index_id = sub.getIndex_id();
		dto->index_code = sub.getIndex_code();
		dto->index_name = sub.getIndex_name();
		dto->index_type = sub.getIndex_type();
		dto->qc_tool = sub.getQc_tool();
		dto->check_method = sub.getCheck_method();
		dto->stander_val = sub.getStander_val();
		dto->unit_of_measure = sub.getUnit_of_measure();
		dto->threshold_max = sub.getThreshold_max();
		dto->threshold_min = sub.getThreshold_min();
		dto->doc_url = sub.getDoc_url();
		dto->remark = sub.getRemark();
		dto->attr1 = sub.getAttr1();
		dto->attr2 = sub.getAttr2();
		dto->attr3 = sub.getAttr3();
		dto->attr4 = sub.getAttr4();
		dto->create_by = sub.getCreate_by();
		dto->create_time = sub.getCreate_time();
		dto->update_by = sub.getUpdate_by();
		dto->update_time = sub.getUpdate_time();
		pages->addData(dto);

	}
	return pages;
	return {};
}

bool TemplateDetectItemService::updateTemplateDetectItem(const TemplateDetectItemDTO::Wrapper& dto)
{
	// ��װDO����
	TemplateDetectItemDO data;
	data.setRecord_id(dto->record_id);
	data.setIndex_name(dto->index_name);
	TemplateDetectItemDAO dao;
	return dao.updateTemplateDetectItem(data) == 1;
	return true;
}

uint64_t TemplateDetectItemService::saveTemplateDetectItem(const TemplateDetectItemDTO::Wrapper& dto)
{
	// ��װDO����
	TemplateDetectItemDO data;
	data.setRecord_id(dto->record_id);
	data.setTemplate_id(dto->template_id);
	data.setIndex_id(dto->index_id);
	data.setIndex_code(dto->index_code);
	data.setIndex_name(dto->index_name);
	data.setIndex_type(dto->index_type);
	data.setQc_tool(dto->qc_tool);
	data.setCheck_method(dto->check_method);
	data.setStander_val(dto->stander_val);
	data.setUnit_of_measure(dto->unit_of_measure);
	data.setThreshold_max(dto->threshold_max);
	data.setThreshold_min(dto->threshold_min);
	data.setDoc_url(dto->doc_url);
	data.setRemark(dto->remark);
	data.setAttr1(dto->attr1);
	data.setAttr2(dto->attr2);
	data.setAttr3(dto->attr3);
	data.setAttr4(dto->attr4);
	data.setCreate_by(dto->create_by);
	data.setCreate_time(dto->create_time);
	data.setUpdate_by(dto->update_by);
	data.setUpdate_time(dto->update_time);
	// ִ���������
	TemplateDetectItemDAO dao;
	return dao.insertTemplateDetectItem(data);
	return 0;
	return {};
}

bool TemplateDetectItemService::removeTemplateDetectItem(uint64_t record_id)
{
	TemplateDetectItemDAO dao;
	return dao.deleteByRecordId(record_id) == 1;
	return true;
}

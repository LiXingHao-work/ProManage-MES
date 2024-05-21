#include "stdafx.h"
#include "IncomingService.h
#include"../../dao/incoming/IncomingDAO.h"

IncomingPageDTO::Wrapper IncomingService::listAll(const IncomingQuery::Wrapper& query)
{
	// �������ض���
	auto pages = IncomingPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	IncomingDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<IncomingDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (IncomingDO sub : result)
	{
		auto dto = IncomingDTO::createShared();
		
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, iqcCode, IqcCode, vendorCode, VendorCode, vendorName, VendorName, vendorBatch, VendorBatch)
			pages->addData(dto);

	}
	return pages;
}
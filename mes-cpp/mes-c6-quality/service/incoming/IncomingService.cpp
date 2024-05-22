#include "stdafx.h"
#include "IncomingService.h"
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
		
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, incomingCode, IncomingCode, vendorCode, VendorCode, vendorName, VendorName, vendorBatch, VendorBatch)
			pages->addData(dto);

	}
	return pages;
}

uint64_t IncomingService::saveData(const IncomingDTO::Wrapper& dto)
{
	// ��װDO����
	IncomingDO data;

	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, IncomingCode, incomingCode, VendorCode, vendorCode, VendorName, vendorName,
		VendorBatch, vendorBatch);
		// ִ���������
		IncomingDAO dao;
	return dao.insert(data);
}

bool IncomingService::updateData(const IncomingDTO::Wrapper& dto)
{
	// ��װDO����
	IncomingDO data;
	
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, IncomingCode, incomingCode, VendorCode, vendorCode, VendorName, vendorName,
		VendorBatch, vendorBatch);		
	// ִ�������޸�
	IncomingDAO dao;
	return dao.update(data) == 1;
}

bool IncomingService::removeData(string iqc_code)
{
	IncomingDAO dao;
	return dao.deleteByIcCode(iqc_code) == 1;
}
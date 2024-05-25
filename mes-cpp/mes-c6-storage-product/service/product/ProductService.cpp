#include "stdafx.h"
#include "ProductService.h"
#include "../../dao/product/ProductDAO.h"

ProductPageDTO::Wrapper ProductTableService::listAll(const ProductQuery::Wrapper& query)
{
	// �������ض���
	auto pages = ProductPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// ��ѯ����������
	ProductTableDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// ��ҳ��ѯ����
	pages->total = count;
	pages->calcPages();
	list<ProductTableDO> result = dao.selectWithPage(query);
	// ��DOת����DTO
	for (ProductTableDO sub : result)
	{
		auto dto = ProductTableDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, pid, Pid, pnum, Pnum, pname, Pname, plist, Plist, pcnum, Pcnum, pcname, Pcname, pdate, Pdate, pstatus, Pstatus)
			pages->addData(dto);
	}
	return pages;
}

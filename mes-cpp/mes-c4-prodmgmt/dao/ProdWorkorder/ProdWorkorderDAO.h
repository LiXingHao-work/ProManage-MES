#pragma once
#ifndef _PRODWORKORDER_DAO_
#define _PRODWORKORDER_DAO_
#include "BaseDAO.h"
#include "../../domain/do/ProdWorkorder/AddProdWorkorderDO.h"
#include "../../domain/do/ProdWorkorder/GetProdWorkorderListDO.h"
#include "../../domain/do/ProdWorkorder/ProdWorkorderBomListDO.h"
#include "../../domain/do/ProdWorkorder/ProdWorkorderInfoDO.h"

#include "../../domain/query/ProdWorkorder/GetProdWorkorderListQuery.h"

class ProdWorkorderDAO : public BaseDAO {
public:
	// ͳ����������
	uint64_t count(const GetProdWorkorderListQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<GetProdWorkorderListDO> selectWithPage(const GetProdWorkorderListQuery::Wrapper& query);
	// ͨ��BOM��ID��ѯ����
	list<ProdWorkorderBomListDO> selectByBomId(const int& line_id);
	// ͨ������ID��ѯ����
	list<ProdWorkorderInfoDO> selectByWorkorderId(const ProdWorkorderInfoDO& Obj);
	// ��������
	uint64_t insert(const AddProdWorkorderDO& iObj);
};
#endif // !_PRODWORKORDER_DAO_
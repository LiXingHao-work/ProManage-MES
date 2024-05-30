#pragma once

#ifndef _PRODWORKORDER_DAO_
#define _PRODWORKORDER_DAO_
#include "BaseDAO.h"
#include "../../domain/do/ProdWorkorder/ProdWorkorderDO.h"

/**
 * �������������ݿ����ʵ��
 */
class ProdWorkorderDAO : public BaseDAO
{
public:
	// ͨ��ID�����������
	int completeById(uint64_t id);
	// ͨ��IDɾ����������
	int deleteById(uint64_t id);
	//ͨ��idȷ����������
	int comfirmById(uint64_t id);
};
#endif // !_PRODWORKORDER_DAO_

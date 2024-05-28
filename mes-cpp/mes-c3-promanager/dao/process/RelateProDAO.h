#pragma once
#ifndef _RELATEPRO_DAO_
#define  _RELATEPRO_DAO_
#include "BaseDAO.h"
#include "../../domain/do/pro/ProRouteProductDO.h"

/**
 * ������Ʒ���ݿ����ʵ��
 */
class RelateProDAO : public BaseDAO
{
public:
	// ���������Ʒ
	uint64_t insert(const ProRouteProductDO& iObj);
	// �޸Ĺ�����Ʒ
	int update(const ProRouteProductDO& uObj);
};
#endif // ! _RELATEPRO_DAO_

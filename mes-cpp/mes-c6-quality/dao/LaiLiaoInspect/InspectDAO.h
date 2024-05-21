#pragma once
#ifndef _INSPECT_DAO
#define _INSPECT_DAO
#include "BaseDAO.h"
#include "../../domain/do/LaiLiaoInspect/InspectDO.h"
#include "../../domain/query/LaiLiaoInspect/InspectQuery.h"

/**
 * ���ϼ�����Ϣ��Ϣ�����ݿ����
 */
class MaterialDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const MaterialQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<MaterialDO> selectWithPage(const MaterialQuery::Wrapper& query);
	// ��������
	uint64_t insert(const MaterialDO& iObj);
	// �޸�����
	int update(const MaterialDO& uObj);
	// ͨ��IDɾ������
	int deleteById(uint64_t id);
};
#endif // !_INSPECT_DAO


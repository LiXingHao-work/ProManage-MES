#pragma once
#ifndef _INSPECT_DAO
#define _INSPECT_DAO
#include "BaseDAO.h"
#include "../../domain/do/LaiLiaoInspect/InspectDO.h"
#include "../../domain/query/LaiLiaoInspect/InspectQuery.h"

/**
 * ���ϼ�����Ϣ��Ϣ�����ݿ����
 */
class InspectDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const InspectQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<InspectDO> selectWithPage(const InspectQuery::Wrapper& query);
	// ��������
	uint64_t insert(const InspectDO& iObj);
	// �޸�����
	int update(const InspectDO& uObj);
	// ͨ��IDɾ������
	int deleteById(uint64_t id);
};

//��ѯ����
class Inspect_detailDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const Inspect_detailQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<Inspect_detailDO> selectWithPage(const Inspect_detailQuery::Wrapper& query);
	// ��������
	uint64_t insert(const Inspect_detailDO& iObj);
	// �޸�����
	int update(const Inspect_detailDO& uObj);
	// ͨ��IDɾ������
	int deleteById(uint64_t id);
};


#endif // !_INSPECT_DAO


#pragma once
=
#ifndef _INCOMING_DAO_
#define _INCOMING_DAO_
#include "BaseDAO.h"
#include "../../domain/do/incoming/IncomingDO.h"
#include "../../domain/query/incoming/IncomingQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class IncomingDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const IncomingQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<IncomingDO> selectWithPage(const IncomingQuery::Wrapper& query);
	// ͨ��������ѯ����
	//list<IncomingDO> selectByName(const string& name);
	// ��������
	//uint64_t insert(const IncomingDO& iObj);
	// �޸�����
	//int update(const IncomingDO& uObj);
	// ͨ��IDɾ������
	//int deleteById(uint64_t id);
};
#endif // !_INCOMING_DAO_

#pragma once

#ifndef _SET_DAO_
#define _SET_DAO_
#include "BaseDAO.h"
#include "../../domain/do/pro/ProProcessDO.h"
#include "../../domain/do/pro/ProProcessContentDO.h"
#include "../../domain/query/set/SetProListQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class SetDAO : public BaseDAO
{
public:
	// ͳ����������
	uint64_t count(const SetProListQuery::Wrapper& query);
	// ��ҳ��ѯ����
	list<ProProcessContentDO> selectWithPage(const SetProListQuery::Wrapper& query);
	//// ͨ��id��ѯ����
	list<ProProcessContentDO> selectById(const uint64_t& id);
	// ��������
	uint64_t insertSet(const ProProcessDO& iObj);
	// ���벽������
	uint64_t insertstepSet(const ProProcessContentDO& iObj);
	// �޸�����
	int updateSet(const ProProcessDO& uObj);
};
#endif // !_SET_DAO_

#pragma once
#ifndef _PROCESS_DAO_
#define _PROCESS_DAO_
#include "BaseDAO.h"
#include "../../domain/do/pro/ProRouteDO.h"
#include "../../domain/query/process/ProcessListQuery.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class ProcessDAO : public BaseDAO
{
public:
	// ͳ�ƹ����б���������
	uint64_t count(const ProcessListQuery::Wrapper& query);
	// ��ҳ��ѯ�����б�
	list<ProRouteDO> selectWithPage(const ProcessListQuery::Wrapper& query);
	// ͨ��id��ѯ��������
	list<ProRouteDO> selectById(const ProcessDetailQuery::Wrapper& query);
	// ��ӹ���
	uint64_t insert(const ProRouteDO& iObj);
	// �޸Ĺ���
	int update(const ProRouteDO& uObj);
	
};
#endif // !_SAMPLE_DAO_

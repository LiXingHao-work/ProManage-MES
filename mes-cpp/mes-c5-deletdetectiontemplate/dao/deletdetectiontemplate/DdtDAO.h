#pragma once
#ifndef _DDT_DAO_
#define _DDT_DAO_
#include "BaseDAO.h"

/**
 * ʾ�������ݿ����ʵ��
 */
class DdtDAO : public BaseDAO
{
public:

	// ͨ��IDɾ������
	int deleteById(uint64_t id);
};
#endif // !_Ddt_DAO_
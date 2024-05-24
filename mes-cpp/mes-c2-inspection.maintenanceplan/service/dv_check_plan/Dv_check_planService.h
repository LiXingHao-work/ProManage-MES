#pragma once
/*
* 
*/
#ifndef _SAMPLE_SERVICE_
#define _SAMPLE_SERVICE_
#include <list>
//#include "domain/vo/sample/SampleVO.h"
//#include "domain/query/sample/SampleQuery.h"
//#include "domain/dto/sample/SampleDTO.h"

#include "domain/vo/query-ForeverOMC/MachineryPlanVO.h"
#include "domain/query/query-ForeverOMC/MachineryPlanQuery.h"
#include "domain/dto/query-ForeverOMC/MachineryPlanDTO.h"

/**
 * ʾ������ʵ�֣���ʾ������ʾ������ʵ��
 */
class Dv_check_planService
{
public:
	// ��ҳ��ѯ��������
	MachineryPlanPageDTO::Wrapper listAll(const MachineryPlanQuery::Wrapper& query);
	// ��������
	uint64_t saveData(const MachineryPlanPageDTO::Wrapper& dto);
	// �޸�����
	bool updateData(const MachineryPlanPageDTO::Wrapper& dto);
	// ͨ��IDɾ������
	bool removeData(uint64_t id);
};

#endif // !_SAMPLE_SERVICE_

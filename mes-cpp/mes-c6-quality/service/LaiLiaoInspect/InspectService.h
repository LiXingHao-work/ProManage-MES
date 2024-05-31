#pragma once
#ifndef _INSPECT_SERVICE_
#define _INSPECT_SERVICE_
#include <list>
#include "domain/vo/LaiLiaoInspect/InspectVO.h"
#include "domain/query/LaiLiaoInspect/InspectQuery.h"
#include "domain/dto/LaiLiaoInspect/InspectDTO.h"

/**
 * ������Ϣ�ķ������
 */
class InspectService
{
public:
	// ��ҳ��ѯ���ϼ����б�
	InspectPageDTO::Wrapper listAll(const InspectQuery::Wrapper& query);
	// ��ҳ��ѯ���ϼ��������
	Inspect_detailDTO::Wrapper list_detailone(const uint64_t iqc_id);
	// ��������
	uint64_t saveData(const Inspect_detailDTO::Wrapper& dto);
	// �޸�����
	bool updateData(const Inspect_detailDTO::Wrapper& dto);
	// ͨ��IDɾ������
	bool removeData(uint64_t id);
};

#endif // !_INSPECT_SERVICE_

#include "stdafx.h"
#include "SetController.h"


// 1 �����ļ�
StringJsonVO::Wrapper SetController::execProcessExport(const ProcessExportQuery::Wrapper& query)
{
	return {};
}
// 2 ��ӹ���
Uint64JsonVO::Wrapper SetController::execAddSet(const SetProAddTableDTO::Wrapper& dto)
{
	return {};
}
// 3 �޸Ĺ���
Uint64JsonVO::Wrapper SetController::execModifySet(const SetProAddTableDTO::Wrapper& dto)
{
	return {};
}
// 4 ��ȡ���ղ����б�
SetProListPageJsonVO::Wrapper SetController::execQuerySet(const SetProListQuery::Wrapper& query, const PayloadDTO& payload) {
	return {};
}
// 5 ��ӹ�����
Uint64JsonVO::Wrapper SetController::execAddStepSet(const SetProListDTO::Wrapper& dto)
{
	return {};
}
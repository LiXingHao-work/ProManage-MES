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
// 6 ��ȡ�����б�
ProListJsonVO::Wrapper SetController::execQueryProList(const ProListQuery::Wrapper& query)
{
	return ProListJsonVO::Wrapper();
}
// 7 ��ȡ���������б�
ProListJsonVO::Wrapper SetController::execQueryProNameList()
{
	return ProListJsonVO::Wrapper();
}
// 8 ��ȡ��������
ProDetailJsonVO::Wrapper SetController::execQueryProDetail(const ProDetailQuery::Wrapper& query)
{
	return ProDetailJsonVO::Wrapper();
}
// 9 �޸Ĺ�����
Uint64JsonVO::Wrapper SetController::execModifyStepSet(const SetProListDTO::Wrapper& dto)
{
	auto jvo = Uint64JsonVO::createShared();
	return jvo;
}
// 10 ɾ��������
Uint64JsonVO::Wrapper SetController::execDeleteStepSet(const SetProListDTO::Wrapper& dto)
{
	auto jvo = Uint64JsonVO::createShared();
	return jvo;
}
// 11 ����������
StringJsonVO::Wrapper SetController::execExportStepSet(const SetStepExportQuery::Wrapper& dto)
{
	return StringJsonVO::Wrapper();
}
// 12 ɾ������
Uint64JsonVO::Wrapper SetController::execDeleteSet(const SetProAddTableDTO::Wrapper& dto)
{
	auto jvo = Uint64JsonVO::createShared();
	return jvo;
}
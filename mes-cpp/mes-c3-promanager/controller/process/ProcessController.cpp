#include "stdafx.h"
#include "ProcessController.h"

//1 ��ѯ�����б�
ProcessListJsonVO::Wrapper ProcessController::execQueryProcessList(const ProcessListQuery::Wrapper& query)
{
	return {};
}

//2 ��ѯ��������
ProcessDetailJsonVO::Wrapper ProcessController::execQueryProcessDetail(const ProcessDetailQuery::Wrapper& query)
{
	return {};
}

//3 ������������
Uint64JsonVO::Wrapper ProcessController::execAddProcess(const ProcessAddDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();

	//��Ӧ���
	return jvo;
}
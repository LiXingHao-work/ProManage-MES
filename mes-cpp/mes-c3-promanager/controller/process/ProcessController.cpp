#include "stdafx.h"
#include "ProcessController.h"

// 1 ��ѯ�����б�
ProcessListJsonVO::Wrapper ProcessController::execQueryProcessList(const ProcessListQuery::Wrapper& query)
{
	return {};
}

// 2 ��ѯ��������
ProcessDetailJsonVO::Wrapper ProcessController::execQueryProcessDetail(const ProcessDetailQuery::Wrapper& query)
{
	return {};
}

// 3 ��ӹ���
Uint64JsonVO::Wrapper ProcessController::execAddProcess(const ProcessAddDTO::Wrapper& dto)
{
	auto jvo = Uint64JsonVO::createShared();
	return jvo;
}

// 4 �޸Ĺ���
Uint64JsonVO::Wrapper ProcessController::execModifyBasicProcess(const ProcessAddDTO::Wrapper& dto)
{
	auto jvo = Uint64JsonVO::createShared();
	return jvo;
}

// 5 ��ȡ���չ�����Ʒ�б�����+��ҳ��
ProductsPageJsonVO::Wrapper ProcessController::execQueryProducts(const ProcessProductsQuery::Wrapper& query)
{
	return {};
}

// 6 ɾ������
Uint64JsonVO::Wrapper ProcessController::execRemoveProcess(const UInt64& id)
{
	auto jvo = Uint64JsonVO::createShared();
	return jvo;
}
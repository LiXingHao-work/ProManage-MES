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
Uint64JsonVO::Wrapper ProcessController::execRemoveProcess(const List<UInt64>& id)
{
	auto jvo = Uint64JsonVO::createShared();
	return jvo;
}

//7 ���յ���
StringJsonVO::Wrapper ProcessController::execQueryProcess(const ProcessQuery::Wrapper& query)
{
	auto jvo = StringJsonVO::createShared();
	return jvo;
}
//8 ��ȡ��ɹ����б�
ProJsonVO::Wrapper ProcessController::execProTable(const ProQuery::Wrapper& query)
{
	return ProJsonVO::Wrapper();
}
//9 �����ɹ���
Uint64JsonVO::Wrapper ProcessController::execaddComProcess(const NewProcessDTO::Wrapper& dto)
{
	return {};
}
//10 �޸���ɹ���
Uint64JsonVO::Wrapper ProcessController::execModifyProcess(const ModifyProDTO::Wrapper& dto)
{
	return {};
}
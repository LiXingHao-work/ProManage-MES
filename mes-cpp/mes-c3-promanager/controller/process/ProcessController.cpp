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
// 11 ��ӹ��չ�����Ʒ
Uint64JsonVO::Wrapper ProcessController::execAddRelatePro(const AddRelateProDTO::Wrapper& dto)
{
	return {};
}
// 12 �޸Ĺ��չ�����Ʒ
Uint64JsonVO::Wrapper ProcessController::execModifyRelatePro(const ModRelateProDTO::Wrapper& dto)
{
	return {};
}
// 13 ��ȡ��Ʒ�Ƴ�����BOM�б�
ProMaterialPageJsonVO::Wrapper ProcessController::execQueryProMaterial(const ProMaterialQuery::Wrapper& query, const PayloadDTO& payload)
{
	return {};
}
// 14 ɾ����������
Uint64JsonVO::Wrapper ProcessController::execRemoveProRoute(const UInt64& id)
{
	return {};
}
// 15 ɾ�����չ�����Ʒ
Uint64JsonVO::Wrapper ProcessController::execRemoveRouteProduct(const UInt64& id)
{
	return {};
}
// 16 �������չ�����Ʒ
StringJsonVO::Wrapper ProcessController::execOutputRouteProduct(const outputRouteProductQuery::Wrapper& query, const PayloadDTO& payload)
{
	return {};
}
// 17 ɾ����Ʒ�Ƴ�����BOM
Uint64JsonVO::Wrapper ProcessController::execRemoveProcessBOM(const UInt64& id)
{
	auto jvo = Uint64JsonVO::createShared();
	return jvo;
}


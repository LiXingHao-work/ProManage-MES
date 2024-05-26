#include "stdafx.h"
#include "ProdWorkorderController.h"
#include "../mes-c4-prodmgmt/service/ProdWorkorder/ProdWorkorderService.h"



AddProdWorkorderJsonVO::Wrapper ProdWorkorderController::execAddProdWorkorder(const AddProdWorkorderDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = AddProdWorkorderJsonVO::createShared();
	// ����У��
	// �ǿ�У��

	// ����һ��Service
	ProdWorkorderService service;
	// ִ����������
	uint64_t id = service.saveData(dto);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//��Ӧ���
	return jvo;
}

GetProdWorkorderListPageJsonVO::Wrapper ProdWorkorderController::execQueryGetProdWorkorderList(const GetProdWorkorderListQuery::Wrapper& query, const PayloadDTO& payload)
{
	//// ����һ��Service
	//ProdWorkorderService service;
	//// ��ѯ����
	//auto result = service.listAll(query);
	//// ��Ӧ���
	//auto jvo = GetProdWorkorderListPageJsonVO::createShared();
	//jvo->success(result);
	//return jvo;
	return {};
}

ProdWorkorderInfoJsonVO::Wrapper ProdWorkorderController::execGetProdWorkorderInfo(const ProdWorkorderInfoDTO::Wrapper& dto)
{
	// ����һ��Service
	ProdWorkorderService service;
	// ��ѯ����
	auto result = service.listDetail(dto);
	// ��Ӧ���
	auto jvo = ProdWorkorderInfoJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

ProdWorkorderBomListJsonVO::Wrapper ProdWorkorderController::execGetProdWorkorderBomList(const ProdWorkorderBomListDTO::Wrapper& dto)
{
	// ����һ��Service
	ProdWorkorderService service;
	// ��ѯ����
	auto result = service.listBomDetail(dto);
	// ��Ӧ���
	auto jvo = ProdWorkorderBomListJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
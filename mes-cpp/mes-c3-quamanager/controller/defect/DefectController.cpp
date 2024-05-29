#include "stdafx.h"
#include "DefectController.h"
#include "../../service/defect/QcDefectService.h"

// 1 ��ȡȱ���б�����+��ҳ��
DefectPageJsonVO::Wrapper DefectController::execQueryDefect(const QcDefectQuery::Wrapper& query, const PayloadDTO& payload)
{
	// ����һ��Service
	DefectService service;
	// ��ѯ����
	auto result = service.listAll(query);
	// ��Ӧ���
	auto jvo = DefectPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}
// 2 ���ȱ��
Uint64JsonVO::Wrapper DefectController::execAddDefect(const DefectDTO::Wrapper& dto)
{
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	// �ǿ�У��
	if (!dto->defect_code || !dto->defect_name || !dto->index_type || !dto->defect_level)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ��ЧֵУ��
	if (dto->defect_code->empty() || dto->defect_name->empty() || dto->index_type->empty() || dto->defect_level->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// ����һ��Service
	DefectService service;
	// ִ����������
	uint64_t id = service.insert(dto);
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
// 3 �޸�ȱ��
Uint64JsonVO::Wrapper DefectController::execModifyDefect(const DefectUpdateDTO::Wrapper& dto)
{
	return {};
}
// 4 ɾ��ȱ��
Uint64JsonVO::Wrapper DefectController::execRemoveDefect(const String& removeList)
{
	return {};
}
// 5 ����ȱ��
std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse>
DefectController::execExportDefect(std::shared_ptr<oatpp::web::server::api::ApiController::IncomingRequest> request)
{
	return createResponse(Status::CODE_200, "export defect file content");
}
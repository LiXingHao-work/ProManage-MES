#include "stdafx.h"
#include "DetectionItemSettingsController.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "../../service/detectionitemsettings/DetectionItemSettingsService.h"
DetectionItemSettingsPageJsonVO::Wrapper DetectionItemSettingsController::execQueryqc(const DetectionItemSettingsQuery::Wrapper& query) {
	DetectionItemSettingsService service;
	auto res = service.listAll(query);
	auto jvo = DetectionItemSettingsPageJsonVO::createShared();
	jvo->success(res);
	return jvo;
	return {};
}

Uint64JsonVO::Wrapper DetectionItemSettingsController::execAddqc(const DetectionItemSettingsDTO::Wrapper& dto)
{
	auto jvo = Uint64JsonVO::createShared();
	if (!dto->code || !dto->name || !dto->type || !dto->tool) {
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	if (dto->code->empty() || dto->name->empty() || dto->type->empty() || dto->tool->empty()) {
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	DetectionItemSettingsService service;
	uint64_t id = service.saveData(dto);
	if (id >= 0) {
		jvo->success(UInt64(id));
	}
	else {
		jvo->fail(UInt64(id));
	}
	return jvo;
	return {};
}

Uint64JsonVO::Wrapper DetectionItemSettingsController::execModifyqc(const DetectionItemSettingsDTO::Wrapper& dto)
{
	auto jvo = Uint64JsonVO::createShared();
	if (dto->code->empty() || dto->name->empty() || dto->type->empty() || dto->tool->empty()) {
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	DetectionItemSettingsService service;
	if (service.updateData(dto)) {
		jvo->success(dto->id);
	}
	else {
		jvo->fail(dto->id);
	}
	return jvo;
	return{};
}

Uint64JsonVO::Wrapper DetectionItemSettingsController::execRemoveTheDetection(const UInt64& id)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!id || id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	DetectionItemSettingsService service;
	// ִ������ɾ��
	if (service.removeData(id.getValue(0))) {
		jvo->success(id);
	}
	else
	{
		jvo->fail(id);
	}
	// ��Ӧ���
	return jvo;
	return {};
}

StringJsonVO::Wrapper DetectionItemSettingsController::execExportDetectionItemSettings(const oatpp::List<UInt64>& id)
{
	return StringJsonVO::Wrapper();
}
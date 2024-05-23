#include "stdafx.h"
#include "ReturnController.h"
#include "oatpp/core/utils/ConversionUtils.hpp"
#include <iostream>
#include <sstream>
#include "tree/TreeUtil.h"
#include "service/return/ReturnService.h"
#include "../ApiDeclarativeServicesHelper.h"

// FastDFS��Ҫ�����ͷ
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"

ReturnPageJsonVO::Wrapper ReturnController::executeQueryAll(const ReturnQuery::Wrapper& query, const PayloadDTO& payload)
{
	return {};
}

ReturnDetailJsonVO::Wrapper ReturnController::executeQueryDetail(const ReturnDetailQuery::Wrapper& returnDetailQuery)
{
	return {};
}

Uint64JsonVO::Wrapper ReturnController::execAddDetail(const ReturnAdd::Wrapper& dto)
{
	return {};
}
// �޸ĵ���
Uint64JsonVO::Wrapper ReturnController::executeModifyReturn(const ReturnDTO::Wrapper& dto)
{
	return {};
}
// ִ�е���
Uint64JsonVO::Wrapper ReturnController::executeExecuteReturn(const UInt64& id)
{
	return {};
}
// ɾ������
Uint64JsonVO::Wrapper ReturnController::executeRemoveReturn(const UInt64& id)
{
	return {};
}
// ��������
std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> ReturnController::executeDownloadFile(const String& filename)
{
	// �����ļ�ȫ·�� // ���·���޷�����
	std::string fullPath = "C:/Users/RHY/Desktop/C6/zero-one-08mes/mes-cpp/mes-c6-storage-return/public/static/" + URIUtil::urlDecode(filename.getValue(""));
	// ��ȡ�ļ�
	auto fstring = String::loadFromFile(fullPath.c_str());

	// �ж��Ƿ��ȡ�ɹ�
	if (!fstring)
	{
		std::cerr << "Failed to open file: " << std::strerror(errno) << std::endl;
		return createResponse(Status::CODE_404, "File Not Found");
	}

	// ������Ӧͷ
	auto response = createResponse(Status::CODE_200, fstring);

	// ������Ӧͷ��Ϣ
	response->putHeader("Content-Disposition", "attachment; filename=" + filename.getValue(""));

	// Ӱ��ɹ����
	return response;
}
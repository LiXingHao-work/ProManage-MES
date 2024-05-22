/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2023/02/20 16:29:31

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
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

/**
 * ע�⣺����Ĳ��ִ��뱾Ӧ�÷ŵ�service���У�Ϊ�˷�����ʾ��д��һ����
 */

ReturnPageJsonVO::Wrapper ReturnController::executeQueryAll(const ReturnQuery::Wrapper& query)
{
	// ����һ��JsonVO����
	auto vo = ReturnPageJsonVO::createShared();
	// ����һ����ҳ����
	auto page = ReturnPageDTO::createShared();
	page->pageIndex = query->pageIndex;
	page->pageSize = query->pageSize;
	page->total = 20;
	page->calcPages();

	// ģ������ҳ����
	int64_t start = (page->pageIndex.getValue(1) - 1) * page->pageSize.getValue(1);
	int64_t end = start + page->pageSize.getValue(1);
	// �߽�ֵֵ����
	if (start >= page->total.getValue(0) || start < 0) {
		vo->fail(page);
		return vo;
	}
	if (end > page->total.getValue(0)) end = page->total.getValue(0);
	// ѭ�����ɲ�������
	for (int64_t i = start; i < end; i++)
	{
		auto return1 = ReturnDTO::createShared();
		return1->returnId = query->returnId;
		return1->returnName = "returnName";
		return1->purchaseId = "12345678901234567" + oatpp::utils::conversion::uint64ToStdStr(i);
		return1->vendorCode = "12345678901234567" + oatpp::utils::conversion::uint64ToStdStr(i);
		return1->vendorName = "vendorName";
		return1->returndate = "2024-5-21";
		return1->status = 0;
		page->addData(return1);
	}
	vo->success(page);
	return vo;
}

Uint64JsonVO::Wrapper ReturnController::executeModifyReturn(const ReturnDTO::Wrapper& dto)
{
	// ���巵�����ݶ���
	auto jvo = Uint64JsonVO::createShared();
	// ����У��
	if (!dto->returnId || dto->returnId <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// ����һ��Service
	ReturnService service;
	// ִ�������޸�
	// if (service.updateData(dto))  //��Ҫdao֧�֣���δ����
	if(true)//ֱ����Ӧ
	{
		jvo->success(dto->returnId);
	}
	else
	{
		jvo->fail(dto->returnId);
	}
	// ��Ӧ���
	return jvo;
}

Uint64JsonVO::Wrapper ReturnController::executeRemoveReturn(const UInt64& id)
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
	ReturnService service;
	// ִ������ɾ��
	// if (service.removeData(id.getValue(0))) 

	if(true)
	{
		jvo->success(id);
	}
	else
	{
		jvo->fail(id);
	}
	// ��Ӧ���
	return jvo;
}

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

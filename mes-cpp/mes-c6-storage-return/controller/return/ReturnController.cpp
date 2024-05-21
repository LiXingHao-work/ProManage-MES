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

StringJsonVO::Wrapper ReturnController::executeModifyReturn(const String& fileBody, const ReturnDTO::Wrapper& dto)
{
	// ��ͷ���ϴ���FastDFS�ļ�������
	ZO_CREATE_DFS_CLIENT_URL(dfs, urlPrefix);
	std::string fieldName = dfs.uploadFile(fileBody->data(), fileBody->size(), "png");
	std::cout << "upload fieldname is : " << fieldName << std::endl;

	// ƴ���ļ�����·��
	std::stringstream ss;
	ss << urlPrefix << fieldName;

	// TODO:���浥�����ݵ����ݿ�����Թ�

	// ������Ӧ����
	auto vo = StringJsonVO::createShared();
	vo->success(String(ss.str().c_str()));
	return vo;
}


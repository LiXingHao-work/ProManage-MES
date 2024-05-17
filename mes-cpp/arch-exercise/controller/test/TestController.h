#pragma once
#ifndef _TESTCONTROLLER_H_
#define _TESTCONTROLLER_H_

#include "ApiHelper.h"
#include "ServerInfo.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/query/PageQuery.h"

//#include "domain/query/sample/SampleQuery.h"
//#include "domain/dto/sample/SampleDTO.h"
//#include "domain/vo/sample/SampleVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)
class TestController :public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(TestController);
public://�ӿ�
	// path����
	ENDPOINT_INFO(getUserById) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("sample.get.summary"));
		API_DEF_ADD_PATH_PARAMS(Int64, "userId",
			ZH_WORDS_GETTER("sample.get.fields.uid.desc"),
			1,
			true);
	}
	ENDPOINT(API_M_GET, "/users/{userId}", getUserById, PATH(Int64, userId))
	{
		OATPP_LOGD("Test", "userId=%d", userId.getValue(0));
		return createResponse(Status::CODE_200, "OK");
	}

	// ��ѯ����
	ENDPOINT_INFO(getUsers) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("sample.get1.summary"));
		API_DEF_ADD_QUERY_PARAMS(Int32, "age",
			ZH_WORDS_GETTER("sample.get1.fields.age.desc"),
			100,
			true);
	}
	ENDPOINT(API_M_GET, "/users", getUsers, QUERY(Int32, age))
	{
		OATPP_LOGD("Test", "age=%d", age.getValue(0));
		return createResponse(Status::CODE_200, "OK");
	}

	// ��Ӧ����
	ENDPOINT_INFO(getPage) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("sample.get2.summary"));
		// �����ҳ����
		API_DEF_ADD_PAGE_PARAMS();
		// ������Ӧ����
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		//API_DEF_ADD_RSP_JSON(StringJsonVO::Wrapper);
	}
	ENDPOINT(API_M_GET, "/users1/page", getPage, QUERIES(QueryParams, params)) {
		// ������ѯ����
		API_HANDLER_QUERY_PARAM(query, PageQuery, params);
		// ��Ӧ���
		API_HANDLER_RESP_VO(executeGetPage(query));
	}
private: // ����ӿ�ִ�к���
	StringJsonVO::Wrapper executeGetPage(const PageQuery::Wrapper& query);
	  

};



#endif // !_TESTCONTROLLER_H_

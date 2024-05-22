#pragma once
#ifndef _WAREHOUSEMANAGEMENT_CONTROLLER_
#define _WAREHOUSEMANAGEMENT_CONTROLLER_
#include "Macros.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/query/warehousemanagement/WarehouseManagementQuery.h"
#include "domain/dto/warehousemanagement/WarehouseManagementDTO.h"
#include "domain/vo/warehousemanagement/WarehouseManagementVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 控制器，基础接口的使用
 */
class WarehouseManagementController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(WarehouseManagementController);
	// 3 定义接口
public:
	// 3.1 定义查询接口描述
	ENDPOINT_INFO(queryWarehouseManagement) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("warehousemanagement.get.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(WarehouseManagementPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "item_code", ZH_WORDS_GETTER("warehousemanagement.field.item_code"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "item_name", ZH_WORDS_GETTER("warehousemanagement.field.item_name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "batch_code", ZH_WORDS_GETTER("warehousemanagement.field.batch_code"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "warehouse_name", ZH_WORDS_GETTER("warehousemanagement.field.warehouse_name"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "vendor_code", ZH_WORDS_GETTER("warehousemanagement.field.vendor_code"), "", false);
		API_DEF_ADD_QUERY_PARAMS(String, "vendor_name", ZH_WORDS_GETTER("warehousemanagement.field.vendor_name"), "", false);

	}
	// 3.2 定义查询接口处理
	ENDPOINT(API_M_GET, "/WarehouseManagement", queryWarehouseManagement, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(userQuery, WarehouseManagementQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryWarehouseManagement(userQuery, authObject->getPayload()));
	}

	// 3.1 定义导出接口描述
	//API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("warehousemanagement.export.summary"), exportWarehouseManagement, StringJsonVO::Wrapper);
	// 3.2 定义导出接口处理
	//API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/WarehouseManagement/export", exportWarehouseManagement, BODY_DTO(oatpp::List<UInt64>, ids), execExportWarehouseManagement(ids));


private:
	// 3.3 分页查询数据
	WarehouseManagementPageJsonVO::Wrapper execQueryWarehouseManagement(const WarehouseManagementQuery::Wrapper& query, const PayloadDTO& payload);
	StringJsonVO::Wrapper execExportWarehouseManagement(const oatpp::List<UInt64>& ids);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _WAREHOUSEMANAGEMENT_CONTROLLER_
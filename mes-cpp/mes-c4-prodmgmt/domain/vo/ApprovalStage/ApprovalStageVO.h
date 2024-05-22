#pragma once
#ifndef _GETPRODUCTIONREPORTLIST_VO_
#define _GETPRODUCTIONREPORTLIST_VO_

#include "../../GlobalInclude.h"
#include "../../dto/ApprovalStage/AddProdWorkorderDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����������ʾJsonVO��������Ӧ���ͻ��˵�Json����
 * GetProductionReportList
 */
class GetProductionReportListJsonVO : public JsonVO<GetProductionReportListDTO::Wrapper> {
	DTO_INIT(GetProductionReportListJsonVO, JsonVO<GetProductionReportListDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_GETPRODUCTIONREPORTLIST_VO_
#ifndef _MACHINERY_PLAN_VO_
#define _MACHINERY_PLAN_VO_

#include "../../GlobalInclude.h"
#include "../../dto/query-ForeverOMC/machineryPlanDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* ���/�����豸�б���ʾJsonVO��������Ӧ���ͻ��˵�Json����
*/
class MachineryPlanJsonVO : public JsonVO<MachineryPlanDTO::Wrapper> {
	DTO_INIT(MachineryPlanJsonVO, JsonVO<MachineryPlanDTO::Wrapper>);
};

/**
* ���/�����豸�б��ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
*/
class MachineryPlanPageJsonVO : public JsonVO<MachineryPlanPageDTO::Wrapper> {
	DTO_INIT(MachineryPlanPageJsonVO, JsonVO<MachineryPlanPageDTO::Wrapper>);
};

/**
* ���/�����豸�б�������ʾJsonVO��������Ӧ���ͻ��˵�Json����
*/
class MachineryPlanDetailsJsonVO : public JsonVO<MachineryPlanDetailsDTO::Wrapper> {
	DTO_INIT(MachineryPlanDetailsJsonVO, JsonVO<MachineryPlanDetailsDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_MACHINERY_PLAN_VO_
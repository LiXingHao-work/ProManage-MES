#ifndef _MACHINERY_LIST_VO_
#define _MACHINERY_LIST_VO_

#include "../../GlobalInclude.h"
#include "../../dto/query-ForeverOMC/machineryListDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* ���/�����豸�б���ʾJsonVO��������Ӧ���ͻ��˵�Json����
*/
class MachineryListJsonVO : public JsonVO<MachineryListDTO::Wrapper> {
	DTO_INIT(MachineryListJsonVO, JsonVO<MachineryListDTO::Wrapper>);
};

/**
* ���/�����豸�б��ҳ��ʾJsonVO��������Ӧ���ͻ��˵�Json����
*/
class MachineryListPageJsonVO : public JsonVO<MachineryListPageDTO::Wrapper> {
	DTO_INIT(MachineryListPageJsonVO, JsonVO<MachineryListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_MACHINERY_LIST_VO_
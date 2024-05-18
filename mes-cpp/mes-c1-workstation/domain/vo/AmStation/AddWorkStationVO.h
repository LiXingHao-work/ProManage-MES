#pragma once

#ifndef _ADDWORKSTATION_VO_H_
#define _ADDWORKSTATION_VO_H_

#include "../../GlobalInclude.h"
#include "../../dto/AmStation/AddWorkStationDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ���û���Ϣ��ʾJsonVO����������Ӧ���ͻ���
 */
class AddWorkStationJsonVO : public JsonVO<AddWorkStationDTO::Wrapper>
{
	DTO_INIT(AddWorkStationJsonVO, JsonVO<AddWorkStationDTO::Wrapper>);
};



#include OATPP_CODEGEN_END(DTO)
#endif // _USERVO_H_
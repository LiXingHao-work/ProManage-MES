#pragma once

#ifndef _REMOVEWORKSTATIONLIST_VO_H_
#define _REMOVEWORKSTATIONLIST_VO_H_

#include "../../GlobalInclude.h"
#include "../../dto/GetList/RemoveWorkStationDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ���û���Ϣ��ʾJsonVO����������Ӧ���ͻ���
 */
class RemoveWorkStationJsonVO : public JsonVO<RemoveWorkStationDTO::Wrapper>
{
	DTO_INIT(RemoveWorkStationJsonVO, JsonVO<RemoveWorkStationDTO::Wrapper>);
};



#include OATPP_CODEGEN_END(DTO)
#endif // _USERVO_H_
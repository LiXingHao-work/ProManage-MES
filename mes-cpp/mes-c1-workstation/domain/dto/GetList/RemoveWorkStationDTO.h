#pragma once

#ifndef _REMOVEWORKSTATIONLIST_DTO_H_
#define _REMOVEWORKSTATIONLIST_DTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ɾ������վ
 */
class RemoveWorkStationDTO : public oatpp::DTO
{
	DTO_INIT(RemoveWorkStationDTO, DTO);
	// Ψһ��ʶ������վID��
	API_DTO_FIELD_DEFAULT(List<UInt64>, workstationId, ZH_WORDS_GETTER("getlist.fields.workstationId"));

};




#include OATPP_CODEGEN_END(DTO)
#endif // _USERDTO_H_
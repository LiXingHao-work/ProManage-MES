#pragma once

#ifndef _RECEIPTVO_VO_H
#define _RECEIPTVO_VO_H

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* ����һ����ȡ�����б����ʾVO
*/
class ReceiptTreeJsonVO : public JsonVO<List<ReceiptTreeDTO::Wrapper>>
{
	DTO_INIT(ReceiptTreeJsonVO, DTO);

};

#include OATPP_CODEGEN_END(DTO)

#endif // _RECEIPTVO_VO_H
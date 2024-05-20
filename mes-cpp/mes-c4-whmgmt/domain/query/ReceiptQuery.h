#pragma once

#ifndef _RECEIPT_QUERY_H
#define _RECEIPT_QUERY_H

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* ���ݲ�ѯ����װ��ѯ����
*/
class ReceiptTreeQuery : public oatpp::DTO
{
	DTO_INIT(ReceiptTreeQuery, DTO);
	// ���ݿ�ı� wm_item_recpt
	
	// ��ⵥ���
	API_DTO_FIELD_DEFAULT(String, recptCode, ZH_WORDS_GETTER("receipt.query.fields.recptCode"));

	// ��ⵥ����
	API_DTO_FIELD_DEFAULT(String, recptName, ZH_WORDS_GETTER("receipt.query.fields.recptName"));

	// ��Ӧ������
	API_DTO_FIELD_DEFAULT(String, vendorName, ZH_WORDS_GETTER("receipt.query.fields.vendorName"));

	// �������
	API_DTO_FIELD_DEFAULT(String, poCode, ZH_WORDS_GETTER("receipt.query.fields.poCode"));

	// ������� 
	API_DTO_FIELD_DEFAULT(String, recptDate, ZH_WORDS_GETTER("receipt.query.fields.recptDate"));

};

#include OATPP_CODEGEN_END(DTO)

#endif // _RECEIPT_QUERY_H
#pragma once
#ifndef _INSPECT_QUERY_
#define _INSPECT_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ����һ����ѯ���ϼ������Ϣ�����ݴ���ģ��
 */
class InspectQuery : public PageQuery
{
	DTO_INIT(InspectQuery, PageQuery);
	
	// ���ϼ��鵥���
	API_DTO_FIELD_DEFAULT(String, code, ZH_WORDS_GETTER("inspect.code"));
	// ��Ӧ�̱���
	API_DTO_FIELD_DEFAULT(String, vendor_code, ZH_WORDS_GETTER("inspect.vendor_code"));
	// ��Ӧ������
	API_DTO_FIELD_DEFAULT(String, vendor_name, ZH_WORDS_GETTER("inspect.vendor_name"));
	//��Ӧ�����κ�
	API_DTO_FIELD_DEFAULT(String, vd_batch, ZH_WORDS_GETTER("inspect.vd_batch"));
	//��Ʒ���ϱ���
	API_DTO_FIELD_DEFAULT(String, item_code, ZH_WORDS_GETTER("inspect.item_code"));
	//��Ʒ��������
	API_DTO_FIELD_DEFAULT(String, item_name, ZH_WORDS_GETTER("inspect.item_name"));
	//�����
	API_DTO_FIELD_DEFAULT(String, check_result, ZH_WORDS_GETTER("inspect.check_result"));
	//��������
	API_DTO_FIELD_DEFAULT(String, recive_date, ZH_WORDS_GETTER("inspect.recive_date"));
	//�������
	API_DTO_FIELD_DEFAULT(String, inspect_date, ZH_WORDS_GETTER("inspect.inspect_date"));
	//�����Ա
	API_DTO_FIELD_DEFAULT(String, inspector, ZH_WORDS_GETTER("inspect.inspector"));

};


//���ϼ�������
class Inspect_detailQuery :public oatpp::DTO
{
	DTO_INIT(Inspect_detailQuery, DTO);
	// ���ϼ��������id
	API_DTO_FIELD_DEFAULT(String, line_id, ZH_WORDS_GETTER("inspect.line_id"));

};

//�鿴����
class Inspect_tableQuery :public oatpp::DTO
{
	DTO_INIT(Inspect_tableQuery, DTO);
	// ���ϼ��������id
	API_DTO_FIELD_DEFAULT(String, line_id, ZH_WORDS_GETTER("inspect.line_id"));

};

//
#include OATPP_CODEGEN_END(DTO)
#endif // !_INSPECT_QUERY_

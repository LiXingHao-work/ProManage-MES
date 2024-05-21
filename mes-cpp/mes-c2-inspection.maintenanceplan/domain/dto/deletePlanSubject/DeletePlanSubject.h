#pragma once
/*
* 
*/
#ifndef _DELETEPLANSUBJECT_H_
#define _DELETEPLANSUBJECT_H_

#include "../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * �б�DTO�����Խ�DTO��װ��List
 * �б����������ԣ�����
 */

 // �����б�DTO����֧������ɾ�������������Ҳ��Ҫ�Ļ������԰������ųɹ�����
template <typename T>
class ListDTO : public oatpp::DTO
{
	DTO_INIT(ListDTO, oatpp::DTO)
		// �����б�
		API_DTO_FIELD(List<T>, item, ZH_WORDS_GETTER("list_dto"), false, {});
public:
	// ���һ������
	void addItem(const T& item) {
		this->item->push_back(item);
	}
};

/**
 * ɾ���豸DTO
 * ��Ʋο����ԣ�����
 */

 // �̳���ListDTO
class DeletePlanSubjectDTO : public ListDTO<oatpp::String>
{
	DTO_INIT(DeletePlanSubjectDTO, ListDTO<oatpp::String>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_REMOVEDEVICEDTO_H_

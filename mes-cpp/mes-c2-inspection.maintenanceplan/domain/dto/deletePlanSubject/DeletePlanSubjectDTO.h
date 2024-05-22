#pragma once
/*
* 
*/
#ifndef _DELETEPLANSUBJECT_H_
#define _DELETEPLANSUBJECT_H_

#include "../mes-c2-inspection.maintenanceplan/domain/GlobalInclude.h"

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
	//
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

//�������������������������ֶΣ�һ�Զ�ʱ��id+idList
// ����list��Ҫ��һ��������id
class DeletePlanSubjectOneToManyDTO :public ListDTO<oatpp::String>
{
	DTO_INIT(DeletePlanSubjectOneToManyDTO, ListDTO<oatpp::String>)
	API_DTO_FIELD_DEFAULT(UInt64, primaryKey, ZH_WORDS_GETTER("planSubject.inputDESC.delOneToMany.primaryKey"));
};

//----------------abf�����䣬ɾ�������Ե���Ӧ��֪������������������ҳ��ʱ�͸���������ѡ�͸����������;Ϳ�ʼ����

/*����ֻ��һ�������ı�id��*/
class DeleteTableUniqueDTO :public ListDTO<oatpp::UInt64>
{
	//List
	DTO_INIT(DeleteTableUniqueDTO, ListDTO<oatpp::UInt64>)
	//����
	API_DTO_FIELD_DEFAULT(String,tableName , ZH_WORDS_GETTER("planSubject.deleteTemplate.DESC.tableName"));
};

/*��������������˫������id��idList��*/
class DeleteTableSharedDTO :public ListDTO<oatpp::UInt64>
{
	//List����������������У�
	DTO_INIT(DeleteTableSharedDTO, ListDTO<oatpp::UInt64>)
	//������ı�����
	API_DTO_FIELD_DEFAULT(String, tableNameSec, ZH_WORDS_GETTER("deleteTemplate.DESC.tableNameSec"));
	//keyPri��������
	API_DTO_FIELD_DEFAULT(UInt64, keyPri, ZH_WORDS_GETTER("deleteTemplate.DESC.keyPri"));
	//����ı�����
	API_DTO_FIELD_DEFAULT(String, tableNamePri, ZH_WORDS_GETTER("deleteTemplate.DESC.tableNamePri"));




};

#include OATPP_CODEGEN_END(DTO)
//one - to - many
#endif // !_REMOVEDEVICEDTO_H_

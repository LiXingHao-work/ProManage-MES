#pragma once
/*
* 
*/
#ifndef _PLANSUBJECTDTO_H_
#define _PLANSUBJECTDTO_H_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 *    ���/�����ƻ����б�����ģ��
 */
class PlanSubjectTableDTO : public oatpp::DTO
{
	DTO_INIT(PlanSubjectTableDTO, DTO);
	//��Ŀ��ţ���ϸ����չ��
	static v_int64 Z__PROPERTY_OFFSET_code() {
		char buffer[sizeof(Z__CLASS)]; auto obj = static_cast<Z__CLASS*>((void*)buffer); auto ptr = &obj->code; return (v_int64)ptr - (v_int64)buffer;
	} static oatpp::data::mapping::type::BaseObject::Property* Z__PROPERTY_SINGLETON_code() {
		static oatpp::data::mapping::type::BaseObject::Property* property = new oatpp::data::mapping::type::BaseObject::Property(Z__PROPERTY_OFFSET_code(), "code", String::Class::getType()); return property;
	} static bool Z__PROPERTY_INIT_code(...) {
		Z__CLASS_GET_FIELDS_MAP()->pushBack(Z__PROPERTY_SINGLETON_code()); return true;
	} static String Z__PROPERTY_INITIALIZER_PROXY_code() {
		static bool initialized = Z__PROPERTY_INIT_code(1, 1); (void)initialized; return String();
	} String code = Z__PROPERTY_INITIALIZER_PROXY_code(); static bool Z__PROPERTY_INIT_code(int, ...) {
		Z__PROPERTY_INIT_code(); Z__PROPERTY_ADD_INFO_code(&Z__PROPERTY_SINGLETON_code()->info); return true;
	} static void Z__PROPERTY_ADD_INFO_code(oatpp::data::mapping::type::BaseObject::Property::Info* info) {
		info->description = YamlHelper().getString(&(ServerInfo::getInstance().getZhDictNode()), "planSubject.fields.subCode");
	};
	//API_DTO_FIELD_DEFAULT(String, code, ZH_WORDS_GETTER("planSubject.fields.subCode"));
	//��Ŀ����
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("planSubject.fields.subName"));
	//��Ŀ���� ��ֻ�����֣�
	API_DTO_FIELD_DEFAULT(String, type, ZH_WORDS_GETTER("planSubject.fields.subType"));
	//��Ŀ����
	API_DTO_FIELD_DEFAULT(String, content, ZH_WORDS_GETTER("planSubject.fields.subContent"));
	//��׼
	API_DTO_FIELD_DEFAULT(String, standard, ZH_WORDS_GETTER("planSubject.fields.subStandard"));

};

/*
*    ���/�����ƻ����б���ϸ������ģ��
*/
class PlanSubjectDetailDTO : public PlanSubjectTableDTO
{
	DTO_INIT(PlanSubjectDetailDTO, PlanSubjectTableDTO);
	//����չ��
	//��Ŀid
	API_DTO_FIELD_DEFAULT(Int64, id, ZH_WORDS_GETTER("planSubject.fields.subId"));
	//�Ƿ�����
	API_DTO_FIELD_DEFAULT(String, enable, ZH_WORDS_GETTER("planSubject.fields.enable"));
	//��ע
	API_DTO_FIELD_DEFAULT(String, remark, ZH_WORDS_GETTER("planSubject.fields.remark"));
};

/**
 *    ���/�����ƻ����б����ݣ���ҳ�������
 */
 class PlanSubjectTablePageDTO : public PageDTO<PlanSubjectTableDTO::Wrapper>
 {
 	DTO_INIT(PlanSubjectTablePageDTO, PageDTO<PlanSubjectTableDTO::Wrapper>);
 };

 /**
 *    ���/�����ƻ����б���ϸ�����ݣ���ҳ�������
 */
 class PlanSubjectDetailPageDTO : public PageDTO<PlanSubjectDetailDTO::Wrapper>
 {
	 DTO_INIT(PlanSubjectDetailPageDTO, PageDTO<PlanSubjectDetailDTO::Wrapper>);
 };
#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_

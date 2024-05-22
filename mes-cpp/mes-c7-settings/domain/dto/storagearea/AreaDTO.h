#pragma once
#ifndef __AREADTO_H__
#define __AREADTO_H__

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
* �������
*/
class AreaDTO: public oatpp::DTO
{
	DTO_INIT(AreaDTO, DTO)
	//Ψһ��ʶ
	API_DTO_FIELD(UInt64, id, ZH_WORDS_GETTER("storagearea.fields.areaId"), true, 1);
	//�ֿ��λ����
	API_DTO_FIELD(String, area_code, ZH_WORDS_GETTER("storagearea.fields.areacode"), true, "00000")
	//�ֿ��λ����
	API_DTO_FIELD(String, area_name, ZH_WORDS_GETTER("storagearea.fields.areaname"), true, "")
	//����ID
	API_DTO_FIELD(UInt64, location_id, ZH_WORDS_GETTER("storagearea.fields.locationId"),true,1)
	//�ֿ��λλ��x
	API_DTO_FIELD(Int32, position_x, ZH_WORDS_GETTER("storagearea.fields.positionx"), true, 0)
	//�ֿ��λλ��y
	API_DTO_FIELD(Int32, position_y, ZH_WORDS_GETTER("storagearea.fields.positiony"), true, 0)
	//�ֿ��λλ��z
	API_DTO_FIELD(Int32, position_z, ZH_WORDS_GETTER("storagearea.fields.positionz"), true, 0)
	//�Ƿ����ÿ�λ
	API_DTO_FIELD(String, enable_flag, ZH_WORDS_GETTER("storagearea.fields.enableFlag"), true, "Y")
	//��λ���
	API_DTO_FIELD(Float64, areasize, ZH_WORDS_GETTER("storagearea.fields.area"), true, 0.00)
	//���������
	API_DTO_FIELD(Float64, max_loa, ZH_WORDS_GETTER("storagearea.fields.maxLoa"), true, 0.00)
	//��ע
	API_DTO_FIELD(String, remarktext, ZH_WORDS_GETTER("storagearea.fields.remark"), true, "")
	//Ԥ���ֶ�1
	API_DTO_FIELD(String, attr1, ZH_WORDS_GETTER("storagearea.fields.attr_one"), true, "")
	//Ԥ���ֶ�2
	API_DTO_FIELD(String, attr2, ZH_WORDS_GETTER("storagearea.fields.attr_two"), true, "")
	//Ԥ���ֶ�3
	API_DTO_FIELD(Int32, attr3, ZH_WORDS_GETTER("storagearea.fields.attr_three"), true, 0)
	//Ԥ���ֶ�4
	API_DTO_FIELD(Int32, attr4, ZH_WORDS_GETTER("storagearea.fields.attr_four"), true, 0)
	//��λ������
	API_DTO_FIELD(String, create_by, ZH_WORDS_GETTER("storagearea.fields.createBy"), true, "")
	//��λ����ʱ��
	API_DTO_FIELD(String, create_time, ZH_WORDS_GETTER("storagearea.fields.createTime"), true, "")
	//��λ������
	API_DTO_FIELD(String, update_by, ZH_WORDS_GETTER("storagearea.fields.updateBy"), true, "")
    //��λ����ʱ��
	API_DTO_FIELD(String, update_time, ZH_WORDS_GETTER("storagearea.fields.updateTime"), true, "")
};
/*
* ��ҳ������󣨷�ҳ��
*/
class AreaPageDTO : public PageDTO<AreaDTO::Wrapper>
{
	DTO_INIT(AreaPageDTO, PageDTO<AreaDTO::Wrapper>)
};


#include OATPP_CODEGEN_END(DTO)

#endif //__AREADTO_H__

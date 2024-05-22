#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: xinye
 @Date: 2024/5/22 22:00:00

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

     https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/

#ifndef _WM_ITEM_RECPT_DTO_
#define _WM_ITEM_RECPT_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ������ⵥ�������
 */
class WmItemRecptDTO : public oatpp::DTO
{
    DTO_INIT(WmItemRecptDTO, DTO);
    // ��ⵥ���
    DTO_FIELD(Int32, recpt_id);
    DTO_FIELD_INFO(recpt_id) {
        info->description = ZH_WORDS_GETTER("wm_item_recpt.field.recpt_id");
    }
    // ��ⵥ����
    DTO_FIELD(String, recpt_code);
    DTO_FIELD_INFO(recpt_code) {
        info->description = ZH_WORDS_GETTER("wm_item_recpt.field.recpt_code");
    }
    // ��ⵥ����
    DTO_FIELD(String, recpt_name);
    DTO_FIELD_INFO(recpt_name) {
        info->description = ZH_WORDS_GETTER("wm_item_recpt.field.recpt_name");
    }
    // ���ϼ��鵥ID
    DTO_FIELD(Int32, iqc_id);
    DTO_FIELD_INFO(iqc_id) {
        info->description = ZH_WORDS_GETTER("wm_item_recpt.field.iqc_id");
    }
    // ���ϼ��鵥����
    DTO_FIELD(String, iqc_code);
    DTO_FIELD_INFO(iqc_code) {
        info->description = ZH_WORDS_GETTER("wm_item_recpt.field.iqc_code");
    }
    // �ɹ��������
    DTO_FIELD(String, po_code);
    DTO_FIELD_INFO(po_code) {
        info->description = ZH_WORDS_GETTER("wm_item_recpt.field.po_code");
    }
    // ��Ӧ��ID
    DTO_FIELD(Int32, vendor_id);
    DTO_FIELD_INFO(vendor_id) {
        info->description = ZH_WORDS_GETTER("wm_item_recpt.field.vendor_id");
    }
    // ��Ӧ�̴���
    DTO_FIELD(String, vendor_code);
    DTO_FIELD_INFO(vendor_code) {
        info->description = ZH_WORDS_GETTER("wm_item_recpt.field.vendor_code");
    }
    // ��Ӧ������
    DTO_FIELD(String, vendor_name);
    DTO_FIELD_INFO(vendor_name) {
        info->description = ZH_WORDS_GETTER("wm_item_recpt.field.vendor_name");
    }
    // ��Ӧ�̼��
    DTO_FIELD(String, vendor_nick);
    DTO_FIELD_INFO(vendor_nick) {
        info->description = ZH_WORDS_GETTER("wm_item_recpt.field.vendor_nick");
    }
    // �ֿ�ID
    DTO_FIELD(Int32, warehouse_id);
    DTO_FIELD_INFO(warehouse_id) {
        info->description = ZH_WORDS_GETTER("wm_item_recpt.field.warehouse_id");
    }
    // �ֿ����
    DTO_FIELD(String, warehouse_code);
    DTO_FIELD_INFO(warehouse_code) {
        info->description = ZH_WORDS_GETTER("wm_item_recpt.field.warehouse_code");
    }
    // �ֿ�����
    DTO_FIELD(String, warehouse_name);
    DTO_FIELD_INFO(warehouse_name) {
        info->description = ZH_WORDS_GETTER("wm_item_recpt.field.warehouse_name");
    }
    // ����ID
    DTO_FIELD(Int32, warehouse_area_id);
    DTO_FIELD_INFO(warehouse_area_id) {
        info->description = ZH_WORDS_GETTER("wm_item_recpt.field.warehouse_area_id");
    }
    // ��������
    DTO_FIELD(String, warehouse_area_code);
    DTO_FIELD_INFO(warehouse_area_code) {
        info->description = ZH_WORDS_GETTER("wm_item_recpt.field.warehouse_area_code");
    }
    // ��������
    DTO_FIELD(String, warehouse_area_name);
    DTO_FIELD_INFO(warehouse_area_name) {
        info->description = ZH_WORDS_GETTER("wm_item_recpt.field.warehouse_area_name");
    }
    // ��λID
    DTO_FIELD(Int32, warehouse_location_id);
    DTO_FIELD_INFO(warehouse_location_id) {
        info->description = ZH_WORDS_GETTER("wm_item_recpt.field.warehouse_location_id");
    }
    // ��λ����
    DTO_FIELD(String, warehouse_location_code);
    DTO_FIELD_INFO(warehouse_location_code) {
        info->description = ZH_WORDS_GETTER("wm_item_recpt.field.warehouse_location_code");
    }
    // ��λ����
    DTO_FIELD(String, warehouse_location_name);
    DTO_FIELD_INFO(warehouse_location_name) {
        info->description = ZH_WORDS_GETTER("wm_item_recpt.field.warehouse_location_name");
    }
    // �������
    DTO_FIELD(String, recpt_date);
    DTO_FIELD_INFO(recpt_date) {
        info->description = ZH_WORDS_GETTER("wm_item_recpt.field.recpt_date");
    }
    // ����״̬
    DTO_FIELD(String, status);
    DTO_FIELD_INFO(status) {
        info->description = ZH_WORDS_GETTER("wm_item_recpt.field.status");
    }
    // ��ע
    DTO_FIELD(String, remark);
    DTO_FIELD_INFO(remark) {
        info->description = ZH_WORDS_GETTER("wm_item_recpt.field.remark");
    }
    // ����1
    DTO_FIELD(String, attr1);
    DTO_FIELD_INFO(attr1) {
        info->description = ZH_WORDS_GETTER("wm_item_recpt.field.attr1");
    }
    // ����2
    DTO_FIELD(String, attr2);
    DTO_FIELD_INFO(attr2) {
        info->description = ZH_WORDS_GETTER("wm_item_recpt.field.attr2");
    }
    // ����3
    DTO_FIELD(String, attr3);
    DTO_FIELD_INFO(attr3) {
        info->description = ZH_WORDS_GETTER("wm_item_recpt.field.attr3");
    }
    // ����4
    DTO_FIELD(String, attr4);
    DTO_FIELD_INFO(attr4) {
        info->description = ZH_WORDS_GETTER("wm_item_recpt.field.attr4");
    }
    // ������
    DTO_FIELD(String, create_by);
    DTO_FIELD_INFO(create_by) {
        info->description = ZH_WORDS_GETTER("wm_item_recpt.field.create_by");
    }
    // ����ʱ��
    DTO_FIELD(String, create_time);
    DTO_FIELD_INFO(create_time) {
        info->description = ZH_WORDS_GETTER("wm_item_recpt.field.create_time");
    }
    // ������
    DTO_FIELD(String, update_by);
    DTO_FIELD_INFO(update_by) {
        info->description = ZH_WORDS_GETTER("wm_item_recpt.field.update_by");
    }
    // ����ʱ��
    DTO_FIELD(String, update_time);
    DTO_FIELD_INFO(update_time) {
        info->description = ZH_WORDS_GETTER("wm_item_recpt.field.update_time");
    }
};

/**
 * ������ⵥ��ҳ�������
 */
class WmItemRecptPageDTO : public PageDTO<WmItemRecptDTO::Wrapper>
{
    DTO_INIT(WmItemRecptPageDTO, PageDTO<WmItemRecptDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_WM_ITEM_RECPT_DTO_

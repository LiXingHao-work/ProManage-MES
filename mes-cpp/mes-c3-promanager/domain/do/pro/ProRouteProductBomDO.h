#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:52:32

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
#ifndef _ProRouteProductBom_DO_
#define _ProRouteProductBom_DO_
#include "../DoInclude.h"

/**
 * ʾ�����ݿ�ʵ����
 */
class ProRouteProductBomDO
{
	// ��¼ID
	CC_SYNTHESIZE(uint64_t, record_id, Record_id);
	// ����·��ID
	CC_SYNTHESIZE(uint64_t, route_id, Route_id);
	// ����ID
	CC_SYNTHESIZE(uint64_t, process_id, Process_id);
	// ��Ʒ����ID
	CC_SYNTHESIZE(uint64_t, product_id, Product_id);
	// ��Ʒ����ID
	CC_SYNTHESIZE(uint64_t, item_id, Item_id);
	// ��Ʒ���ϱ���
	CC_SYNTHESIZE(string, item_code, Item_code);
	// ��Ʒ��������
	CC_SYNTHESIZE(string, item_name, Item_name);
	// ����ͺ�
	CC_SYNTHESIZE(string, specification, Specification);
	// ��λ
	CC_SYNTHESIZE(string, unit_of_measure, Unit_of_measure);
	// ���ϱ���
	CC_SYNTHESIZE(double, quantity, Quantity);
	// ��ע
	CC_SYNTHESIZE(string, remark, Remark);
	// Ԥ���ֶ�1
	CC_SYNTHESIZE(string, attr1, Attr1);
	// Ԥ���ֶ�2
	CC_SYNTHESIZE(string, attr2, Attr2);
	// Ԥ���ֶ�3
	CC_SYNTHESIZE(int, attr3, Attr3);
	// Ԥ���ֶ�4
	CC_SYNTHESIZE(int, attr4, Attr4);
	// ������
	CC_SYNTHESIZE(string, create_by, Create_by);
	// ����ʱ��
	CC_SYNTHESIZE(string, create_time, Create_time);
	// ������
	CC_SYNTHESIZE(string, update_by, Update_by);
	// ����ʱ��
	CC_SYNTHESIZE(string, update_time, Update_time);
public:
	ProRouteProductBomDO() {
		record_id = 0;
		route_id = 0;
		process_id = 0;
		product_id = 0;
		item_id = 0;
		item_code = "";
		item_name = "";
		specification = "";
		unit_of_measure = "";
		quantity = 0.0;
		remark = "";
		attr1 = "";
		attr2 = "";
		attr3 = 0;
		attr4 = 0;
		create_by = "";
		create_time = "";
		update_by = "";
		update_time = "";
	}
};

#endif // !_ProRouteProductBom_DO_
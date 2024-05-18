#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Heng_Xin
 @Date: 2024/5/18 15:45:52

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
#ifndef _HX_CONTROLLER_
#define _HX_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/repairorder/RepairorderQuery.h"
#include "domain/dto/repairorder/RepairorderDTO.h"
#include "domain/vo/repairorder/RepairorderVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * ά�޵�������
 */
class RepairorderController : public oatpp::web::server::api::ApiController
{
    API_ACCESS_DECLARE(RepairorderController);
public:
    // ά�޵���ҳ��ѯ�ӿ�����
    ENDPOINT_INFO(queryRepairorder) {
        // ����ӿڱ���
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("repairorder.summary"));
        // ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
        API_DEF_ADD_AUTH();
        // ������Ӧ������ʽ
        API_DEF_ADD_RSP_JSON_WRAPPER(RepairorderPageJsonVO);
        // �����ҳ��ѯ��������
        API_DEF_ADD_PAGE_PARAMS();
        // ����������ѯ��������
        // ά�޵����
        API_DEF_ADD_QUERY_PARAMS(String, "repairCode", ZH_WORDS_GETTER("repairorder.query.fields.repair_code"), "0x3f", false);

        // ά�޵�����
        API_DEF_ADD_QUERY_PARAMS(String, "repairName", ZH_WORDS_GETTER("repairorder.query.fields.repair_name"), "bugRepair", false);

        // �豸����
        API_DEF_ADD_QUERY_PARAMS(String, "machineryCode", ZH_WORDS_GETTER("repairorder.query.fields.machinery_code"), "M0721", false);

        // �豸����
        API_DEF_ADD_QUERY_PARAMS(String, "machineryName", ZH_WORDS_GETTER("repairorder.query.fields.machinery_name"), "mk-2", false);

        // ά�޽��
        API_DEF_ADD_QUERY_PARAMS(String, "repairResult", ZH_WORDS_GETTER("repairorder.query.fields.repair_result"), "OK", false);

        // ����״̬
        API_DEF_ADD_QUERY_PARAMS(String, "status", ZH_WORDS_GETTER("repairorder.query.fields.status"), "cao", false);
    }
    // ����ά�޵���ҳ��ѯ�ӿڴ���
    ENDPOINT(API_M_GET, "/repairorder/page-query-repairorder-table", queryRepairorder, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
        // ������ѯ����ΪQuery����ģ��
        API_HANDLER_QUERY_PARAM(pageQuery, RepairorderQuery, queryParams);
        // ����ִ�к�����Ӧ���
        API_HANDLER_RESP_VO(execQueryRepairorder(pageQuery));
    }
private:
    // ά�޵���ҳ��ѯ����
    RepairorderPageJsonVO::Wrapper execQueryRepairorder(const RepairorderQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController)
#endif // _HX_CONTROLLER_
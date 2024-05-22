#pragma once
#ifndef _PROINSPECT_CONTROLLER_
#define _PROINSPECT_CONTROLLER_
#include "domain/vo/BaseJsonVO.h"
#include "../../domain/do/proinspect/ProinspectDO.h"
#include "../../domain/dto/proinspect/ProinspectDTO.h"
#include "../../domain/vo/proinspect/ProinspectVO.h"
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen
class ProinspectController : public oatpp::web::server::api::ApiController {
	// 2 ����������������
	API_ACCESS_DECLARE(ProinspectController);
	// 3 ����ӿ�
public:
	ENDPOINT_INFO(addrecord) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("qualitycontrol.defect.addre"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	// 3.2 ���������ӿڴ���
	ENDPOINT(API_M_POST, "/proinspect", addrecord, BODY_DTO(ProinspectDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execAddrecord(dto));
	}
	// 3.1 �����޸Ľӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("qualitycontrol.defect.setre"), execModifyrecord, Uint64JsonVO::Wrapper);
	// 3.2 �����޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/proinspect", execModifyrecord, BODY_DTO(ProinspectDTO::Wrapper, dto), execModifyrecord(dto));


	// 3.1 ����ɾ���ӿ�����
	ENDPOINT_INFO(removerecord) {
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("qualitycontrol.defect.delre"), Uint64JsonVO::Wrapper);
		// ��������·������˵��
		API_DEF_ADD_PATH_PARAMS(UInt64, "record_id", ZH_WORDS_GETTER("qualitycontrol.defect.record_id"), 1, true);
	}
	// 3.2 ����ɾ���ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/proinspect/{record_id}", removerecord, PATH(UInt64, record_id), execRemoverecord(record_id));

private:
	//��ʾ�������
	Uint64JsonVO::Wrapper execAddrecord(const ProinspectDTO::Wrapper& dto);
	// 3.3 �޸�����                           
	Uint64JsonVO::Wrapper execModifyrecord(const ProinspectDTO::Wrapper& dto);
	// 3.3 ɾ������
	Uint64JsonVO::Wrapper execRemoverecord(const UInt64& record_id);
};







// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_
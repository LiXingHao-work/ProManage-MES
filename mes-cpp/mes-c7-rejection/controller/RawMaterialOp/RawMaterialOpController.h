#pragma once
#ifndef _RawMaterialOp_CONTROLLER_
#define _RawMaterialOp_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "ServerInfo.h"
#include "domain/dto/RawMaterialOp/RawMaterialOpDTO.h"
#include "domain/query/RawMaterialOpQuery.h"
#include "domain/vo/RawMaterialOpVO.h"
#include "ApiHelper.h"

// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin

/**
 * ʾ������������ʾ�����ӿڵ�ʹ��
 */
class RawMaterialOpController : public oatpp::web::server::api::ApiController // 1 �̳п�����
{
	// 2 ����������������
	API_ACCESS_DECLARE(RawMaterialOpController);
	// 3 ����ӿ�
public:

	// ����ɾ�����ݽӿ�����
	ENDPOINT_INFO(removeRawMaterialOp)
	{
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("RawMaterialOp.delete.summary"), Uint64JsonVO::Wrapper);
		// ��������·������˵��
		API_DEF_ADD_PATH_PARAMS(UInt64, "id", ZH_WORDS_GETTER("RawMaterialOp.field.id"), 1, true);
	}
	//����ɾ�����ݽӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/RawMaterialOp/{id}", removeRawMaterialOp, PATH(UInt64, id), execRemoveRawMaterialOp(id));


	// 3.1 �����޸Ľӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("RawMaterialOp.put.summary"), modifyRawMaterialOp, Uint64JsonVO::Wrapper);
	// 3.2 �����޸Ľӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/RawMaterialOp/{oprator}", modifyRawMaterialOp, BODY_DTO(RawMaterialOpDTO::Wrapper, dto), execModifyRawMaterialOp(dto));



	// �����ļ����ؽӿ�
	ENDPOINT_INFO(downloadFile) {
		API_DEF_ADD_COMMON(ZH_WORDS_GETTER("RawMaterialOp.file.download.summary"), Void);
		API_DEF_ADD_QUERY_PARAMS(String, "filename", ZH_WORDS_GETTER("RawMaterialOp.file.download.filename"), "file/test.jpg", true);
	}
	// ����˵�
	ENDPOINT(API_M_GET, "/file/download", downloadFile, QUERY(String, filename)) {
		return execDownloadFile(filename);
	}




private:
	// ɾ���������ϵ����б�֧������ɾ����
	Uint64JsonVO::Wrapper execRemoveRawMaterialOp(const UInt64& id);

	// 3.3 �޸��������ϵ�������
	Uint64JsonVO::Wrapper execModifyRawMaterialOp(const RawMaterialOpDTO::Wrapper& dto);

	// ִ���ļ����ش���
	std::shared_ptr<OutgoingResponse> execDownloadFile(const String& filename);
};

// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_
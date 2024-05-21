package com.zeroone.star.project.j1.orgstructure.query.user;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.Date;

/**
 * <p>��Ȩ��&copy;01����</p>
 * <p>��ַ��01�����ܲ�</p>
 * @author Tme
 * @version 1.0.0
 */
@Data
@ApiModel("�û��б��ѯ����")
public class UserQuery {
    @ApiModelProperty(value = "�û�����", example = "admin")
    private String userName;
    @ApiModelProperty(value = "�ֻ�����", example = "18888888888")
    private String phonenumber;
    @ApiModelProperty(value = "�û��˺�״̬(0:���� 1:ͣ��)", example = "1")
    private String status;
    @ApiModelProperty(value = "����ʱ�䣺��ʼ����", example = "2024-05-20")
    private String beginDate;
    @ApiModelProperty(value = "����ʱ�䣺��������", example = "2024-05-21")
    private String endDate;


/**
 *��ɫID
 */
@ApiModelProperty(value = "��ɫ���",example = "1")
private Long roleId;
}

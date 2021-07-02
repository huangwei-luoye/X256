#ifndef GLOABL_H
#define GLOABL_H

typedef enum _COMMOND_TYPE : quint8
{
    ZHUANG_TAI_CHA_XUN = 0x21,
    CAN_SHU_SHE_ZHI = 0x22,
    KAI_SHI_CAI_JI = 0x23,
    KAI_SHI_SHANG_CHUAN = 0x24,
    DIAN_YA_KONG_ZHI = 0x25,
    DIAN_YA_ZU_JIAN = 0x26,
    SRC_FILE_SHANG_CHUAN = 0x27,
}CommondType;

#pragma pack(push,1)

typedef struct _BASE_COMMOND_HEAD{
    quint8 head1 = 0x55;
    quint8 head2 = 0xAA;
    quint32 liu_shui_hao;
    quint16 pack_length = 32;
    quint8 src_addr = 0x02;/*上位机*/
    quint8 dst_addr = 0x01;/*电压采集系统*/
    CommondType type;
    quint8 tong_xing_ji_zhi = 0x01;
}BaseCommodHead;

/*普通32字节命令，不携带任何有效数据*/
/*状态查询，开始采集、开始上传、电压控制、电压组件*/
typedef struct _BASE_COMMOND{
    BaseCommodHead bc_head;
    quint8 yuliu[20] = {0};
}BaseCommond;

/*状态查询回复*/
typedef struct _ZHUANG_TAI_ACK{
    BaseCommodHead bc_head;
    quint8 work_status;
    quint8 liucheng_status;
    quint8 adc_16status;/*16片ADC，每片对应一个bit 1：异常 0：正常*/
    quint32 dianya_output_status;/*26路电压输出状态，低26位有效 1：开启 0：关闭*/
    quint8 dianliu_result[52];/*26路电流结果*/
    quint8 dianya_result[52];/*26路电压结果*/
    quint32 dac_status;/*低26bit有效，1：异常 0：正常*/
    quint64 adc_52status;/*低52bit有效，1：异常 0：正常*/
    quint16 caiji_fpga_wendu;/*（FPGA温度 *503.975）/4096 - 273.15*/
    quint16 dianya_fpga_wendu;/*和上面一样*/
    quint8 yuliu[4];
}ZhuangTaiAck;

/*参数设置指令*/
typedef struct _CAN_SHU_SET{
    BaseCommodHead bc_head;
    quint16 caijidianshu;
    quint8 zengyizhi[256];
    quint8 dianyacanshu1[16];
    quint8 dianyacanshu2[12];
    quint8 dianyacanshu3[12];
    quint8 dianyacanshu4[12];
    quint8 yuliu[6] = {0};
}CanShuSetInfo;

/*参数设置应答,开始采集应答、电压控制应答、电压组件应答使用BaseCommond*/

/*开始上传应答*/
typedef struct _SHANG_CHUAN_ACK{
    BaseCommodHead bc_head;
    quint8 caiji_result[512];
    quint8 yuliu[4];
}ShangChuanAck;

/*原文件上传，端口数据全都为有效数据*/

#pragma pack(pop)


#endif // GLOABL_H

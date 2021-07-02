#ifndef MYHELPER_H
#define MYHELPER_H

#include <QDesktopWidget>
#include <QFile>
#include <QTextCodec>
#include <QMessageBox>
#include <QAbstractButton>
#include <QCoreApplication>
#include <QFileDialog>
#include <QTime>
#include <QProcess>
#include <QDir>
//#include <QSound>
#include <QApplication>
#include <QStyleFactory>
#include <QInputDialog>
#include <QStyle>
#include <QDebug>
#include <QTimer>

/*描述：辅助类，包含对话框，中文显示，文件处理等
 *作者：huangwei
 *时间：2013-12-12
*/

class myHelper:public QObject
{
public:

    static void SetStyle();//设置全局为plastique样式
    static void SetGB2312Code();//设置编码为GB2312
    static void SetUTF8Code();//设置编码为UTF8
    static void ShowMessageBoxInfo(QString info);//显示信息框，仅确定按钮
    static void ShowMessageBoxInfoX(QString info);
    static void ShowMessageBoxError(QString info);//显示错误框，仅确定按钮
    static void ShowMessageBoxErrorX(QString info);
    static int ShowMessageBoxQuesion(QString info);//显示询问框，确定和取消按钮
    static int ShowMessageBoxQuesionX(QString info);
    static QString ShowInputBox(QWidget *frm,QString info);//显示标准输入框
    static QByteArray HexStrToByteArray(QString str);//16进制字符串转字节数组
    static char ConvertHexChar(char ch);
    static QString ByteArrayToHexStr(QByteArray data);//字节数组转16进制字符串
    static int StrHexToDecimal(QString strHex);//16进制字符串转10进制
    static int StrDecimalToDecimal(QString strDecimal);//10进制字符串转10进制
    static int StrBinToDecimal(QString strBin);//2进制字符串转10进制
    static QString StrHexToStrBin(QString strHex);//16进制字符串转2进制字符串
    static QString DecimalToStrBin1(int decimal);//10进制转2进制字符串一个字节
    static QString DecimalToStrBin2(int decimal);//10进制转2进制字符串两个字节
    static uchar GetCheckCode(uchar data[],uchar len);//计算校验码（和）
    static uchar GetUChar(char data);//将溢出的char转为正确的uchar
    static void Sleep(int sec);//延时
    static void Delay(quint32 ms);
    static QString GetCurrentPath();//获取当前路径
    static void PlaySound();//播放声音
    static void SetSystemDateTime(int year,int month,int day,int hour,int min,int sec);//设置系统日期时间
    static void FormOnlyCloseInCenter(QWidget *frm);//窗体居中，并且只有关闭按钮，不能调整大小
    static void FormInCenter(QWidget *frm);//窗体居中显示
    static void FormNoMaxButton(QWidget *frm);//窗体没有最大化按钮
    static void FormOnlyCloseButton(QWidget *frm);//窗体只有关闭按钮
    static void FormNotResize(QWidget *frm);//窗体不能改变大小
    static QSize GetDesktopSize();//获取桌面大小
    static QString GetFileName(QString filter);//获取选择的文件
    static QStringList GetFileNames(QString filter);//获取选择的文件集合
    static QString GetFolderName();//获取选择的目录
    static QString GetFileNameWithExtension(QString strFilePath);//获取文件名，含拓展名
    static QStringList GetFolderFileNames(QStringList filter);//获取选择文件夹中的文件
    static bool FolderIsExist(QString strFolder);//文件夹是否存在
    static bool FileIsExist(QString strFile);//文件是否存在
    static bool CopyFile(QString sourceFile, QString targetFile);//复制文件
    static QList<QPointF> BumaTosrcma(const QByteArray &data);//补码转换成源码，两个字节为一个数据
    static QList<QPointF> BumaTosrcma(const QByteArray &data, quint32 start, quint32 end);//补码转换成源码，两个字节为一个数据
    static QList<qint16> BumaTosrcmaToList(const QByteArray &data);

};

#endif // MYHELPER_H

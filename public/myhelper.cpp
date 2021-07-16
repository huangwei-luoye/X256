#include "myhelper.h"

void SetStyle()
{
    QApplication::setStyle(QStyleFactory::create("Plastique"));
    //QApplication::setPalette(QApplication::style()->standardPalette());//替换应用程序的颜色组合
}

void myHelper::SetGB2312Code()
{
    QTextCodec *codec=QTextCodec::codecForName("GB2312");
    QTextCodec::setCodecForLocale(codec);
   // QTextCodec::setCodecForCStrings(codec);
    //QTextCodec::setCodecForTr(codec);
}

int myHelper::ShowMessageBoxQuesion(QString info)
{
    QMessageBox msg;
    msg.setStyleSheet("font:12pt '宋体'");
    msg.setWindowTitle("询问");
    msg.setText(info);
    msg.setIcon(QMessageBox::Question);
    msg.addButton("确定",QMessageBox::ActionRole);
    msg.addButton("取消",QMessageBox::RejectRole);

    return msg.exec();
}

int myHelper::ShowMessageBoxQuesionX(QString info)
{
    return QMessageBox::question(0,"询问",info,QMessageBox::Yes|QMessageBox::No);
}

QString myHelper::ShowInputBox(QWidget *frm, QString info)
{
    bool ok;
    return QInputDialog::getText(frm,"提示",info,QLineEdit::Password,"",&ok);
}

QByteArray myHelper::HexStrToByteArray(QString str)
{
    QByteArray senddata;
    int hexdata,lowhexdata;
    int hexdatalen = 0;
    int len = str.length();
    senddata.resize(len/2);
    char lstr,hstr;
    for(int i=0; i<len; )
    {
        hstr=str[i].toLatin1();
        if(hstr == ' ')
        {
            i++;
            continue;
        }
        i++;
        if(i >= len)
            break;
        lstr = str[i].toLatin1();
        hexdata = ConvertHexChar(hstr);
        lowhexdata = ConvertHexChar(lstr);
        if((hexdata == 16) || (lowhexdata == 16))
            break;
        else
            hexdata = hexdata*16+lowhexdata;
        i++;
        senddata[hexdatalen] = (char)hexdata;
        hexdatalen++;
    }
    senddata.resize(hexdatalen);
    return senddata;
}

char myHelper::ConvertHexChar(char ch)
{
    if((ch >= '0') && (ch <= '9'))
        return ch-0x30;
    else if((ch >= 'A') && (ch <= 'F'))
        return ch-'A'+10;
    else if((ch >= 'a') && (ch <= 'f'))
        return ch-'a'+10;
    else return (-1);
}

QString myHelper::ByteArrayToHexStr(QByteArray data)
{
    QString temp="";
    QString hex=data.toHex();
    for (int i=0;i<hex.length();i=i+2)
    {
        temp+=hex.mid(i,2)+" ";
    }
    return temp.trimmed().toUpper();
}

int myHelper::StrHexToDecimal(QString strHex)
{
    bool ok;
    return strHex.toInt(&ok,16);
}

int myHelper::StrDecimalToDecimal(QString strDecimal)
{
    bool ok;
    return strDecimal.toInt(&ok,10);
}

int myHelper::StrBinToDecimal(QString strBin)
{
    bool ok;
    return strBin.toInt(&ok,2);
}

QString myHelper::StrHexToStrBin(QString strHex)
{
    uchar decimal=StrHexToDecimal(strHex);
    QString bin=QString::number(decimal,2);

    uchar len=bin.length();
    if (len<8)
    {
        for (int i=0;i<8-len;i++)
        {
            bin="0"+bin;
        }
    }

    return bin;
}

QString myHelper::DecimalToStrBin1(int decimal)
{
    QString bin=QString::number(decimal,2);

    uchar len=bin.length();
    if (len<=8)
    {
        for (int i=0;i<8-len;i++)
        {
            bin="0"+bin;
        }
    }

    return bin;
}

QString myHelper::DecimalToStrBin2(int decimal)
{
    QString bin=QString::number(decimal,2);

    uchar len=bin.length();
    if (len<=16)
    {
        for (int i=0;i<16-len;i++)
        {
            bin="0"+bin;
        }
    }

    return bin;
}

uchar myHelper::GetCheckCode(uchar data[], uchar len)
{
    uchar temp=0;

    for (uchar i=0;i<len;i++)
    {
        temp+=data[i];
    }

    return temp%256;
}

uchar myHelper::GetUChar(char data)
{
    uchar temp;
    if (data > 127)
    {
        temp=data+256;
    }
    else
    {
        temp=data;
    }
    return temp;
}

void myHelper::Sleep(int sec)
{
    QTime dieTime = QTime::currentTime().addMSecs(sec);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void myHelper::Delay(quint32 ms)
{
    QEventLoop loop;
    QTimer::singleShot(ms, &loop, SLOT(quit()));

    loop.exec();
}

QString myHelper::GetCurrentPath()
{
    return QString(QCoreApplication::applicationDirPath()+"/");
}

void myHelper::PlaySound()
{
    //  QSound::play(soundName);
}

void myHelper::SetSystemDateTime(int year, int month, int day, int hour, int min, int sec)
{
    QProcess p(0);

    p.start("cmd");
    p.waitForStarted();
    p.write(QString("date %1-%2-%3\n").arg(year).arg(month).arg(day).toLatin1());
    p.closeWriteChannel();
    p.waitForFinished(1000);
    p.close();

    p.start("cmd");
    p.waitForStarted();
    p.write(QString("time %1:%2:%3.00\n").arg(hour).arg(min).arg(sec).toLatin1());
    p.closeWriteChannel();
    p.waitForFinished(1000);
    p.close();
}

void myHelper::FormOnlyCloseInCenter(QWidget *frm)
{
    //设置窗体居中
    QDesktopWidget desktop;
    int screenX=desktop.availableGeometry().width();
    int screenY=desktop.availableGeometry().height()-40;
    int frmX=frm->width();
    int frmY=frm->height();
    QPoint movePoint(screenX/2-frmX/2,screenY/2-frmY/2);
    frm->move(movePoint);

    //设置窗体不能调整大小
    frm->setFixedSize(frmX,frmY);

    //设置窗体只有最小化按钮
    frm->setWindowFlags(Qt::WindowCloseButtonHint);
}

void myHelper::FormInCenter(QWidget *frm)
{
    int screenX=qApp->desktop()->availableGeometry().width();
    int screenY=qApp->desktop()->availableGeometry().height()-60;
    int wndX=frm->width();
    int wndY=frm->height();
    QPoint movePoint((screenX-wndX)/2,(screenY-wndY)/2);
    frm->move(movePoint);
}

void myHelper::FormNoMaxButton(QWidget *frm)
{
    frm->setWindowFlags(Qt::WindowMinimizeButtonHint);
}

void myHelper::FormOnlyCloseButton(QWidget *frm)
{
    frm->setWindowFlags(Qt::WindowCloseButtonHint);
}

void myHelper::FormNotResize(QWidget *frm)
{
    frm->setFixedSize(frm->width(),frm->height());
}

QSize myHelper::GetDesktopSize()
{
    QDesktopWidget desktop;
    return QSize(desktop.availableGeometry().width(),desktop.availableGeometry().height());
}

QString myHelper::GetFileName(QString filter)
{
    return QFileDialog::getOpenFileName(NULL,"选择文件",QCoreApplication::applicationDirPath(),filter);
}

QStringList myHelper::GetFileNames(QString filter)
{
    return QFileDialog::getOpenFileNames(NULL,"选择文件",QCoreApplication::applicationDirPath(),filter);
}

QString myHelper::GetFolderName()
{
    return QFileDialog::getExistingDirectory();;
}

QString myHelper::GetFileNameWithExtension(QString strFilePath)
{
    QFileInfo fileInfo(strFilePath);
    return fileInfo.fileName();
}

QStringList myHelper::GetFolderFileNames(QStringList filter)
{
    QStringList fileList;
    QString strFolder = QFileDialog::getExistingDirectory();
    if (!strFolder.length()==0)
    {
        QDir myFolder(strFolder);

        if (myFolder.exists())
        {
            fileList= myFolder.entryList(filter);
        }
    }
    return fileList;
}

bool myHelper::FolderIsExist(QString strFolder)
{
    QDir tempFolder(strFolder);
    return tempFolder.exists();
}

bool myHelper::FileIsExist(QString strFile)
{
    QFile tempFile(strFile);
    return tempFile.exists();
}

bool myHelper::CopyFile(QString sourceFile, QString targetFile)
{
    if (FileIsExist(targetFile))
    {
        int ret=QMessageBox::information(NULL,"提示","文件已经存在，是否替换？",QMessageBox::Yes | QMessageBox::No);
        if (ret!=QMessageBox::Yes)
        {
            return false;
        }
    }
    return QFile::copy(sourceFile,targetFile);
}

QList<QPointF> myHelper::BumaTosrcma(const QByteArray &data)
{

    QList<QPointF> listPoint;
    quint16 shortData = 0;
    qint16 tempData = 0;
    quint16 mask = 0;
    qint32 j = 0;
    static double lainghuajindu = 0.000125;
    static double jiaozhunxishu = 0.6;

    for(qint32 i = 0; i < data.size()-1; i+=2)
    {
         shortData = 0;
         shortData = ((quint8)data.at(i)<<8);
         shortData |= (quint8)data.at(i+1)&0xFF;
         mask = shortData & (1<<15);
         tempData = mask?((shortData^0xFFFF)+1)*(-1):shortData;
         listPoint.append(QPointF(j*2,tempData*lainghuajindu*jiaozhunxishu));
         j++;
    }
    return listPoint;
}

QList<QPointF> myHelper::BumaTosrcma(const QByteArray &data, quint32 start, quint32 end)
{
    QList<QPointF> listPoint;
    quint16 shortData = 0;
    qint16 tempData = 0;
    quint16 mask = 0;
    qint32 j = 0;
    static double lainghuajindu = 0.000125;
    static double jiaozhunxishu = 0.6;

    for(qint32 i = start; i < end; i+=2)
    {
         shortData = 0;
         shortData = ((quint8)data.at(i)<<8);
         shortData |= (quint8)data.at(i+1)&0xFF;
         mask = shortData & (1<<15);
         tempData = mask?((shortData^0xFFFF)+1)*(-1):shortData;
         //listPoint.append(QPointF(j*2,tempData*lainghuajindu*jiaozhunxishu));
         listPoint.append(QPointF(j*2,tempData));
         j++;
    }
    return listPoint;
}

QList<qint16> myHelper::BumaTosrcmaToList(const QByteArray &data)
{
    QList<qint16> list;
    quint16 shortData = 0;
    qint16 tempData = 0;
    quint16 mask = 0;
    qint32 j = 0;

    for(qint32 i = 0; i < data.size()-1; i+=2)
    {
         shortData = 0;
         shortData = ((quint8)data.at(i)<<8);
         shortData |= (quint8)data.at(i+1)&0xFF;
         mask = shortData & (1<<15);
         tempData = mask?((shortData^0xFFFF)+1)*(-1):shortData;
         list.append(tempData);
         j++;
    }
    return list;
}

QList<QPointF> myHelper::PianYiMaToYuanMa(const QByteArray &data)
{
    QList<QPointF> list;
    quint16 shortData = 0;
    qint16 tempData = 0;
    quint16 mask = 0;
    qint32 j = 0;
    quint32 waveLength;

    if(data.size() > 2000){
        waveLength = 2000;
    }else{
        waveLength = data.size();
    }
    for(qint32 i = 0; i < waveLength; i+=2)
    {
         shortData = 0;
         shortData = ((quint8)data.at(i)<<8);
         shortData |= (quint8)data.at(i+1)&0xFF;
         if(shortData > 8192){
             tempData = (16384 - shortData) * (-1);
         }else{
             tempData = shortData;
         }
         list.append(QPointF(j*2,tempData));
         j++;
    }
    return list;


}

void SetUTF8Code()
{
   // QTextCodec *codec=QTextCodec::codecForName("UTF-8");
  //  QTextCodec::setCodecForLocale(codec);
  //  QTextCodec::setCodecForCStrings(codec);
  //  QTextCodec::setCodecForTr(codec);
}

void ShowMessageBoxInfo(QString info)
{
    QMessageBox msg;
    msg.setStyleSheet("font:12pt '宋体'");
    msg.setWindowTitle("提示");
    msg.setText(info);
    msg.setIcon(QMessageBox::Information);
    msg.addButton("确定",QMessageBox::ActionRole);
    msg.exec();
}

void ShowMessageBoxInfoX(QString info)
{
    QMessageBox::information(0,"提示",info,QMessageBox::Ok);
}

void ShowMessageBoxError(QString info)
{
    QMessageBox msg;
    msg.setStyleSheet("font:12pt '宋体'");
    msg.setWindowTitle("错误");
    msg.setText(info);
    msg.setIcon(QMessageBox::Critical);
    msg.addButton("确定",QMessageBox::ActionRole);
    msg.exec();
}

void ShowMessageBoxErrorX(QString info)
{
    QMessageBox::critical(0,"错误",info,QMessageBox::Ok);
}

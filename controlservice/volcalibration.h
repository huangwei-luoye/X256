#ifndef VOLCALIBRATION_H
#define VOLCALIBRATION_H
#include <QMap>
#include <QPair>

#define CALIBRATION_INI "./config/VolCalibration.ini"

class VolCalibration
{
public:
    VolCalibration();

    QMap<quint8, QPair<double, double> > DACCalibration() const;
    void setDACCalibration(const QMap<quint8, QPair<double, double> > &DACCalibration);

private:

    QMap<quint8, QPair<double, double> > m_DACCalibration;/*DAC 校准方程*/
};

#endif // VOLCALIBRATION_H

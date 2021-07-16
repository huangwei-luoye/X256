#include "volcalibration.h"

VolCalibration::VolCalibration()
{

}

QMap<quint8, QPair<double, double> > VolCalibration::DACCalibration() const
{
    return m_DACCalibration;
}

void VolCalibration::setDACCalibration(const QMap<quint8, QPair<double, double> > &DACCalibration)
{
    //m_DACCalibration = DACCalibration;
}

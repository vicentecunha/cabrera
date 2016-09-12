/*
 * Cabrera: anamnesis.h
 * Author: Vicente Cunha
 * Date: July 2016
 */

#ifndef ANAMNESIS_H
#define ANAMNESIS_H

#include "patient.h"

class Anamnesis
{
public:
    Anamnesis();
    Anamnesis(const QString& name,
              const QString& idString,
              Patient::sex_t,
              QDate birthday,
              const QString& notes,
              double weight,
              double height,
              const QStringList&);

    bool isInvalid = true;

    QString getName()        {return name;}
    long getId()             {return id;}
    Patient::sex_t getSex()  {return sex;}
    QDate getBirthday()      {return birthday;}
    QString getNotes()       {return notes;}
    double getHeight()       {return height;}
    double getWeight()       {return weight;}
    QString getCC()          {return cc;}
    QString getHPI()         {return hpi;}
    QString getPMH()         {return pmh;}
    QString getROScardio()   {return ROScardio;}
    QString getROSresp()     {return ROSresp;}
    QString getROSgastro()   {return ROSgastro;}
    QString getROSgenit()    {return ROSgenit;}
    QString getROSnerv()     {return ROSnerv;}
    QString getROScran()     {return ROScran;}
    QString getROSendo()     {return ROSendo;}
    QString getROSmusco()    {return ROSmusco;}
    QString getROSskin()     {return ROSskin;}
    QString getFamily()      {return family;}
    QString getChildhood()   {return childhood;}
    QString getSocial()      {return social;}
    QString getMedications() {return medications;}
    QString getAllergies()   {return allergies;}
    QString getSexual()      {return sexual;}
    QString getConclusion()  {return conclusion;}
    QString getSexStr();
    QString getIdStr();
    QString getHeightStr();
    QString getWeightStr();

    void setName(const QString& name)               {this->name = name;}
    void setId(long id)                             {this->id = id;}
    void setSex(Patient::sex_t sex)                 {this->sex = sex;}
    void setBirthday(QDate birthday)                {this->birthday = birthday;}
    void setNotes (const QString& notes)            {this->notes = notes;}
    void setHeight(double height)                   {this->height = height;}
    void setWeight(double weight)                   {this->weight = weight;}
    void setCC         (const QString& cc)          {this->cc = cc;}
    void setHPI        (const QString& hpi)         {this->hpi = hpi;}
    void setPMH        (const QString& pmh)         {this->pmh = pmh;}
    void setROScardio  (const QString& ROScardio)   {this->ROScardio = ROScardio;}
    void setROSresp    (const QString& ROSresp)     {this->ROSresp = ROSresp;}
    void setROSgastro  (const QString& ROSgastro)   {this->ROSgastro = ROSgastro;}
    void setROSgenit   (const QString& ROSgenit)    {this->ROSgenit = ROSgenit;}
    void setROSnerv    (const QString& ROSnerv)     {this->ROSnerv = ROSnerv;}
    void setROScran    (const QString& ROScran)     {this->ROScran = ROScran;}
    void setROSendo    (const QString& ROSendo)     {this->ROSendo = ROSendo;}
    void setROSmusco   (const QString& ROSmusco)    {this->ROSmusco = ROSmusco;}
    void setROSskin    (const QString& ROSskin)     {this->ROSmusco = ROSskin;}
    void setFamily     (const QString& family)      {this->family = family;}
    void setChildhood  (const QString& childhood)   {this->childhood = childhood;}
    void setSocial     (const QString& social)      {this->social = social;}
    void setMedications(const QString& medications) {this->medications = medications;}
    void setAllergies  (const QString& allergies)   {this->allergies = allergies;}
    void setSexual     (const QString& sexual)      {this->sexual = sexual;}
    void setConclusion (const QString& conclusion)  {this->conclusion = conclusion;}
    void setIdFromString      (const QString&);
    void setSexFromString     (const QString&);
    void setBirthdayFromString(const QString&);
    void setHeightFromString  (const QString&);
    void setWeightFromString  (const QString&);

private:
    QString name;
    long id;
    Patient::sex_t sex;
    QDate birthday;
    QString notes;
    double height = 0;
    double weight = 0;
    QString cc;
    QString hpi;
    QString pmh;
    QString ROScardio;
    QString ROSresp;
    QString ROSgastro;
    QString ROSgenit;
    QString ROSnerv;
    QString ROScran;
    QString ROSendo;
    QString ROSmusco;
    QString ROSskin;
    QString family;
    QString childhood;
    QString social;
    QString medications;
    QString allergies;
    QString sexual;
    QString conclusion;
};

#endif // ANAMNESIS_H

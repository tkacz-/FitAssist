#ifndef PROFILE_H
#define PROFILE_H

#include <QString>
#include <QDataStream>

class Profile
{
private:
    float weight;
    short height;
    short age;
    QString gender;
    float activity;

    double bmi;
    QString conclusion;
    double minWeight;
    double maxWeight;
    double bmr;
    double water;

private:
    //Calculate BMI
    double calculateBMI();

    //Conclision of BMI
    QString conclusionBMI(double res);

    //Calculate optimal weight
    void calculateOptimalWeight(double &min, double &max);

    //Calculate optimal calorie
    double calculateBMR();

    //Calculate norm of water
    double calculateWater();

public:
    Profile();

    Profile(float w, short h, short age, QString g, float a);

    //Calculate all profile norms
    void calculateNorms();

    void setWeigth(float w);
    float getWeigth() const;

    void setHeigth(short w);
    short getHeigth() const;

    void setAge(short age);
    short getAge() const;

    void setGender(QString g);
    QString getGender() const;

    void setActivity(float a);
    float getActivity() const;

    void setBMI(double temp);
    double getBMI() const;

    void setConclusion(QString temp);
    QString getConclusion() const;

    void setOptimalWeightMin(double min);
    double getOptimalWeightMin() const;

    void setOptimalWeightMax(double max);
    double getOptimalWeightMax() const;

    void setBMR(double bmr);
    double getBMR() const;

    void setWater(double water);
    double getWater() const;
};

//ostream, << overloading
inline QDataStream &operator<<(QDataStream &out, const Profile &p)
{
    out << p.getWeigth() << p.getHeigth() << p.getAge() << p.getGender()
        << p.getActivity() << p.getBMI() << p.getConclusion() << p.getOptimalWeightMin()
        << p.getOptimalWeightMax() << p.getBMR() << p.getWater();
    return out;
}

//istream, >> overloading
inline QDataStream &operator>>(QDataStream &in, Profile &p)
{
    float weight;
    short height;
    short age;
    QString gender;
    float activity;

    double bmi;
    QString conclusion;
    double minWeight;
    double maxWeight;
    double bmr;
    double water;

    in >> weight >> height >> age >> gender >> activity >> bmi >> conclusion
            >> minWeight >> maxWeight >> bmr >> water;

    p = Profile(weight,height,age,gender,activity);
    p.setBMI(bmi);
    p.setConclusion(conclusion);
    p.setOptimalWeightMin(minWeight);
    p.setOptimalWeightMax(maxWeight);
    p.setBMR(bmr);
    p.setWater(water);

    return in;
}

#endif // PROFILE_H

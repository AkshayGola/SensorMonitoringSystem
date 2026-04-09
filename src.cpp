#include <vector>
#include <string>
#include <iostream>
using namespace std;

enum SENSOR_TYPE {
    TEMPERATURE,
    PRESSURE,
    LOCATION
};

class sensor {
    protected:
        vector<Observer *> Observerlist;
        string sensor_id;
        SENSOR_TYPE type;
    public:
        void addObserver(Observer * newObserver) {
            Observerlist.push_back(newObserver);
        }

        void deleteObserver(Observer * remObserver) {
            // TBD
        }

        virtual SENSOR_TYPE getSensorType () = 0;

        string getSensorID () {
            return sensor_id;
        }
};

class tempSensor: public sensor {
    private:
        float value;
    public:
        tempSensor ()
        {
            type = TEMPERATURE;
        }
        float getSensorValue () {
            return value;
        }

        bool updateSensorValue (int sensorValue) {
            value = sensorValue;
        }
};

class pressureSensor: public sensor {
    private:
        float value;
    public:
        pressureSensor ()
        {
            type = PRESSURE;
        }

        float getSensorValue () {
            return value;
        }

        bool updateSensorValue (int sensorValue) {
            value = sensorValue;
        }
};

class locationSensor: public sensor {
    private:
        pair<float, float> value;
        SENSOR_TYPE type;
        vector<Observer *> Observerlist; 
    public:
        locationSensor ()
        {
            type = LOCATION;
        }
        pair<float, float> getSensorValue () {
            return value;
        }

        bool updateSensorValue (pair<float, float> sensorValue) {
            value = sensorValue;
        }
};

class Observer {

    public:
        virtual void update () = 0;
};

class MonitoringSystem: public Observer {

    public:
        void update (sensor * sensor_param) {
            cout << "sensor with sensorID" << sensor_param->getSensorID() << "reached threshold!\n";
        }
};

void main () {

}
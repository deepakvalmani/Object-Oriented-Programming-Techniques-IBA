#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <string>

using namespace std;

class Sensor
{
public:
    int sensorId;
    string location;
    string sensorType; //(e.g., temperature, humidity)
    double value;
    Sensor()
    {
    }

    Sensor(int id, string loc, string type, double val)
    {
        sensorId = id;
        location = loc;
        sensorType = type;
        value = val;
    }
};

class Alert
{
public:
    int priority;
    string message;
    string alertType; // Type of alert (INFO, WARNING, ERROR, CRITICAL)

    Alert()
    {
    }
    Alert(int p, string msg, string alert)
    {
        priority = p;
        message = msg;
        alertType = alert;
    }

    bool operator<(const Alert &other) const
    {
        return priority < other.priority;
    }
};

class SensorProcessor
{
private:
    queue<Sensor> SensorQueue;
    priority_queue<Alert> AlertQueue;

public:
    void addSensorReading(const Sensor &reading)
    {
        SensorQueue.push(reading);
    }

    void addAlert(const Alert &alert)
    {
        AlertQueue.push(alert);
    }

    void processNextAlert()
    {
        if (AlertQueue.empty())
        {
            cout << "Bhag jao" << endl;
            return;
        }
        Alert topAlert = AlertQueue.top();
        AlertQueue.pop();

        cout << "Processing Alert: [Priority " << topAlert.priority << "] "
             << topAlert.alertType << " - " << topAlert.message << endl;
    }

    // Return a Sensor by value. If not found, return default Sensor with id -1
    Sensor findSensorById(int Id)
    {
        int n = SensorQueue.size();
        Sensor result; 
        result.sensorId = -1; // mark as not found

        for (int i = 0; i < n; i++)
        {
            Sensor current = SensorQueue.front();
            SensorQueue.pop();
            SensorQueue.push(current);

            if (current.sensorId == Id && result.sensorId == -1)
            {
                result = current;
            }
        }

        return result;
    }

    vector<Sensor> findSensorByLocation(const string &loc)
    {
        vector<Sensor> result;

        int n = SensorQueue.size();

        for (int i = 0; i < n; i++)
        {
            Sensor current = SensorQueue.front();
            SensorQueue.pop();

            if (current.location == loc)
            {
                result.push_back(current);
            }

            SensorQueue.push(current);
        }

        return result;
    }
};

int main()
{
    SensorProcessor sp;

    sp.addSensorReading(Sensor(101, "CS Block", "Temperature", 27.5));
    sp.addSensorReading(Sensor(102, "CS Block", "Humidity", 55.2));
    sp.addSensorReading(Sensor(103, "Library", "Temperature", 24.0));
    sp.addSensorReading(Sensor(104, "Admin Block", "Humidity", 60.7));
    sp.addSensorReading(Sensor(105, "Library", "Humidity", 50.1));

    cout << "=== Sensors Added Successfully ===\n\n";

    cout << "=== Find Sensor By ID ===\n";
    Sensor s = sp.findSensorById(103);

    if (s.sensorId != -1)
    {
        cout << "Sensor Found:\n";
        cout << "ID: " << s.sensorId
             << ", Location: " << s.location
             << ", Type: " << s.sensorType
             << ", Value: " << s.value << endl;
    }
    else
    {
        cout << "Sensor not found!\n";
    }

    cout << "\n=== Find Non-Existing Sensor By ID ===\n";
    Sensor s2 = sp.findSensorById(999);

    if (s2.sensorId != -1)
    {
        cout << "Sensor Found (unexpected)\n";
    }
    else
    {
        cout << "Sensor with ID 999 not found!\n";
    }

    cout << "\n=== Sensors in Library ===\n";
    vector<Sensor> librarySensors = sp.findSensorByLocation("Library");

    if (librarySensors.empty())
    {
        cout << "No sensors found in Library.\n";
    }
    else
    {
        for (int i = 0; i < (int)librarySensors.size(); i++)
        {
            cout << "ID: " << librarySensors[i].sensorId
                 << ", Type: " << librarySensors[i].sensorType
                 << ", Value: " << librarySensors[i].value << endl;
        }
    }

    cout << "\n=== Sensors in Gym ===\n";
    vector<Sensor> gymSensors = sp.findSensorByLocation("Gym");

    if (gymSensors.empty())
    {
        cout << "No sensors found in Gym.\n";
    }
    else
    {
        for (int i = 0; i < (int)gymSensors.size(); i++)
        {
            cout << "ID: " << gymSensors[i].sensorId
                 << ", Type: " << gymSensors[i].sensorType
                 << ", Value: " << gymSensors[i].value << endl;
        }
    }

    cout << "\n=== Adding Alerts ===\n";
    sp.addAlert(Alert(2, "Temperature slightly high in CS Block", "WARNING"));
    sp.addAlert(Alert(5, "Fire detected in Library!", "CRITICAL"));
    sp.addAlert(Alert(1, "Routine system check", "INFO"));
    sp.addAlert(Alert(3, "Humidity high in Admin Block", "ERROR"));

    cout << "\n=== Processing Alerts ===\n";
    sp.processNextAlert();
    sp.processNextAlert();
    sp.processNextAlert();
    sp.processNextAlert();

    cout << "\n=== Processing Alert When Queue Empty ===\n";
    sp.processNextAlert();

    return 0;
}

#include <iostream>
using namespace std;

class Artifact
{
private:
    string name;
    string registrationID;
    string discoverer;
    string origin;

public:
    Artifact(string name, string registrationID, string discoverer, string origin)
    {
        this->name = name;
        this->registrationID = registrationID;
        this->discoverer = discoverer;
        this->origin = origin;
    }
    void GetName(string name)
    {
        this->name = name;
    }
    void GetregistrationID(string registrationID)
    {
        this->registrationID = registrationID;
    }
    void GetNdiscoverer(string discoverer)
    {
        this->discoverer = discoverer;
    }
    void Getorigin(string origin)
    {
        this->origin = origin;
    }

    string getArtifactInfo()
    {
        // cout<<"Name: "<<name<<endl;
        // cout<<"RegstrationID: "<<registrationID<<endl;
        // cout<<"Discoverer: "<<discoverer<<endl;
        // cout<<"Origin: "<<origin<<endl;

        string s = "";
        s += "Name: " + name + "\n";
        s += "RegistrationID: " + registrationID + "\n";
        s += "Discoverer: " + discoverer + "\n";
        s += "Origin: " + origin + "\n";
        return s;
    }
};

int main()
{
    Artifact artifacts[5] = {
        Artifact("Jim", "A001", "Pierre-Francois", "Egypt"),
        Artifact("Tony", "A002", "Local Farmers", "China"),
        Artifact("david", "A003", "Bedouin Shepherds", "Israel"),
        Artifact("Machu", "A004", "Hiram Bingham", "Peru"),
        Artifact("huntman", "A005", "Greek Divers", "Greece")
    };

    for (int i = 0; i < 5; i++)
    {
        cout << "Artifact " << i + 1 << " Information:\n";
        cout << artifacts[i].getArtifactInfo() << endl;
    }

    return 0;
}
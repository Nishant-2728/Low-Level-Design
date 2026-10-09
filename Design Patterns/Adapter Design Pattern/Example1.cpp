#include <bits/stdc++.h>
using namespace std;

class Reports{
public:
    virtual string getJSONData(const string& data)=0;
    virtual ~Reports(){}
};

class XMLDataProvider{  //Adaptee
public:
    string getXMLData(const string& data){
        size_t sep=data.find(":");    //Expect data in "name:id" format
        string name=data.substr(0,sep);
        string id=data.substr(sep+1);
        
        return "<user>"
               "<name>"+name +"</name>"
               "<id>"+id +"</id>"
               "</user>";
    }
};

class XMLDataProviderAdapter: public Reports{  //Adapter
private:
    XMLDataProvider* xmlprovider;
public:
    XMLDataProviderAdapter(XMLDataProvider* provider){
        this->xmlprovider=provider;
    }
    
    string getJSONData(const string& data) override{
        string xml= xmlprovider->getXMLData(data);
        
        size_t startName=xml.find("<name>")+6;
        size_t endName=xml.find("</name>");
        string name=xml.substr(startName,endName-startName);
        
        size_t startId=xml.find("<id>")+4;
        size_t endId=xml.find("</id>");
        string id=xml.substr(startId,endId-startId);
        
        return "{\"name\":\""+name+"\",\"id\":"+ id + "}";
    }
};

class Client{
public:
    void getReport(Reports* report,string rawData){
        cout<<"Processed JSON: "<<report->getJSONData(rawData)<<"\n";
    }
};

int main(){
	XMLDataProvider* xmlProv= new XMLDataProvider();
	
	Reports* adapter= new XMLDataProviderAdapter(xmlProv);
	
	string rawData="Alice:42";
	
	Client* user1=new Client();
	user1->getReport(adapter,rawData);
	
	delete adapter;
	delete xmlProv;
}

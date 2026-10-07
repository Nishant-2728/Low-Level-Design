#include <bits/stdc++.h>
using namespace std;

class Subscriber{
public:
    virtual void update()=0;
    virtual ~Subscriber(){}
};


class Channel{
public:
    virtual void subscribe(Subscriber* s)=0;
    virtual void unsubscribe(Subscriber* s)=0;
    virtual void notifySubscribers()=0;
    virtual ~Channel(){}
};


class YoutubeChannel: public Channel{
private:
    vector<Subscriber*>subscribers;
    string name;
    string latestVideo;
public:
    YoutubeChannel(const string& name){
        this->name=name;
    }
    void subscribe(Subscriber* s) override{
        if(find(subscribers.begin(),subscribers.end(),s)==subscribers.end()){
            subscribers.push_back(s);
        }
    }
    void unsubscribe(Subscriber* s) override{
        auto it=find(subscribers.begin(),subscribers.end(),s);
        if(it!=subscribers.end()){
            subscribers.erase(it);
        }
    }
    void notifySubscribers() override{
        for(Subscriber* s: subscribers){
            s->update();
        }
    }
    void uploadVideo(const string& title){
        this->latestVideo=title;
        cout<<name<<" uploaded a video titled \""<<title<<"\"\n";
        notifySubscribers();
    }
    string getVideoData(){
        return " Checkout out new video: "+latestVideo+"\n";
    }
};


class User: public Subscriber{
private:
    string name;
    YoutubeChannel* channel;
public:
    User(const string& s,YoutubeChannel* channelname){
        this->name=s;
        this->channel=channelname;
    }
    void update() override{
        cout<<"Hey "<<name<<","<<this->channel->getVideoData();
    }
};

int main(){
	YoutubeChannel* newChannel= new YoutubeChannel("Take U Forward");
	
	Subscriber* subscriber1= new User("Rohan",newChannel);
	Subscriber* subscriber2= new User("Sanjay",newChannel);
	
	newChannel->subscribe(subscriber1);
	newChannel->subscribe(subscriber2);
	
	newChannel->uploadVideo("Sliding Window");
	
	newChannel->unsubscribe(subscriber1);
	
	newChannel->uploadVideo("Binary Search");
}

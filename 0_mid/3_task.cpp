#include <iostream>
using namespace std;

class Body
{
    string nameTag;

public:
    Body(string nT) : nameTag(nT)
    {
        cout << "Body created of " << nameTag << "\n";
    }
    void owner() const
    {
        cout << "Body in use of : " << nameTag << "\n";
    }
};

class Heart
{
    Body *body; // Aggregation: Car has a pointer to Engine, but does not own it
public:
    Heart(Body *b) : body(b)
    {
        cout << "Heart agaya!\n";
    }

    void showDetails() const
    {
        if (body)
            body->owner();
        cout << "body ready to live\n";
    }
};

class Brain{
    Body myBody;
};

int main()
{
    Body myBody("ahsan");
    Heart FarooqHeart(&myBody); // Engine exists independently of Car
    myBody.owner();
    return 0;
}
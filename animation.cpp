#include "animation.hpp"

animation::animation(string nom)
{
    
}

animation::~animation()
{

}

void animation::getRect()
{
    cout << " nombre de rect: " << listeRectAni.size() << endl; 
    for(int i = 0; i < listeRectAni.size(); i++)
    {
        
    }
}
void animation::setRect(SDL_Rect ptr)
{
    this->listeRectAni.push_back(ptr);
}



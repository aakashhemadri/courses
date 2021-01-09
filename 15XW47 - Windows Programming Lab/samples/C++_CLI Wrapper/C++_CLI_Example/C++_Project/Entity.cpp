#include "Entity.h"
#include <iostream>
using namespace std;
namespace Native
{
   Entity::Entity(const char* name, float xPos, float yPos)
      : m_Name(name), m_XPos(xPos), m_YPos(yPos)
   {
      cout << "  C++ Project: Created the Entity object \"" << m_Name <<"\"" << endl;
   }
   void Entity::Move(float deltaX, float deltaY)
   {
      cout << "  C++ Project: Before move " << m_Name << " to (" << m_XPos << ", " << m_YPos << ")." << endl;
      m_XPos += deltaX;
      m_YPos += deltaY;
      cout << "  C++ Project: Moved " << m_Name << " to (" << m_XPos << ", " << m_YPos << ")." << endl;
   }
}
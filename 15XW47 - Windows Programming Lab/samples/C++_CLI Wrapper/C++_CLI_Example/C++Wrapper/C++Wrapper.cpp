// This is the main DLL file.

#include "stdafx.h"

#include "C++Wrapper.h"
namespace Managed
{
   ManagedEntity::ManagedEntity(String^ name, float xPos, float yPos)
   {
      Console::WriteLine("CLI Wrapper: Creating a wrapper object");
      m_EntityObject = new Native::Entity(string_to_char_array(name), xPos, yPos);
      Console::WriteLine("CLI Wrapper: Name of entity object is {0}", char_array_to_string(m_EntityObject->m_Name));
   }

   void ManagedEntity::Move(float deltaX, float deltaY)
   {
      Console::WriteLine("CLI Wrapper: Move method from wrapper is called");
      m_EntityObject->Move(deltaX, deltaY);
   }
}
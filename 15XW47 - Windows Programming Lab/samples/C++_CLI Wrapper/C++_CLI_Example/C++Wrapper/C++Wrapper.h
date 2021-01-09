// C++Wrapper.h

#pragma once
#include "../C++_Project/Entity.h"

using namespace System;
using namespace System::Runtime::InteropServices;

namespace Managed {

	public ref class ManagedEntity
	{
   private:
      Native::Entity* m_EntityObject;
   public:
      ManagedEntity(Native::Entity* entityObject): m_EntityObject(entityObject)
      {}

      ManagedEntity(String ^name, float xPos, float yPos);

      ~ManagedEntity() 
      {
         if (m_EntityObject != nullptr)
            delete m_EntityObject;
      }      

      Native::Entity* GetInstance()
      {
         return m_EntityObject;
      }

      
      void Move(float deltaX, float deltaY);

      property float XPosition
      {
         float get()
         {
            return m_EntityObject->GetXPosition();
         }     
         void set(float value)
         {

         }
      }

      property float YPosition
      {
         float get()
         {
            return m_EntityObject->GetYPosition();
         }
         void set(float value)
         {
            
         }
      }

      static const char* string_to_char_array(String^ string)  //Marshalling: Converts a .NET String to a const char* that can be used in C++
      {
         const char* str = (const char*)(Marshal::StringToHGlobalAnsi(string)).ToPointer();
         return str;
      }

      static String^ char_array_to_string(const char* str)  //Unmarshalling: Converts a const char* to a .NET String that can be used in C#
      {
         String^ string = gcnew String(str);
         return string;
      }
	};
}

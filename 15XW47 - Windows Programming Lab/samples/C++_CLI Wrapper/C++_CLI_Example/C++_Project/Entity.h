#pragma once
namespace Native
{
   class Entity
   {
   public:
      const char* m_Name;
   private:
      float m_XPos, m_YPos;
   public:
      Entity(const char* name, float xPos, float yPos);

      void Move(float deltaX, float deltaY);
      float GetXPosition() const { return m_XPos; };
      float GetYPosition() const { return m_YPos; };
   };
}
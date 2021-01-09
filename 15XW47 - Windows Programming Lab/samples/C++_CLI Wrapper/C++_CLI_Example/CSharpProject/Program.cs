using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Managed;

namespace CSharpProject
{
   class Program
   {
      static void Main(string[] args)
      {
         ManagedEntity mEntity = new ManagedEntity("C++/CLI Example Entity ", 5, 10);
         mEntity.Move(5, -10);
         Console.WriteLine(mEntity.XPosition + " " + mEntity.YPosition);
         Console.Read();
      }
   }
}

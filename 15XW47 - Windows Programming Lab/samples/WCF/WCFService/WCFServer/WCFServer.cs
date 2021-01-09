using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.ServiceModel;

namespace WCFServer
{
   public class WCFServer : IWCFServer.IWCFServer
   {
      public string GetMessage(string name)
      {
         return "Hello " + name;
      }
   }
}

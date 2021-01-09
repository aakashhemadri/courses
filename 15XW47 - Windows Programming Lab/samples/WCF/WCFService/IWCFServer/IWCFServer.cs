using System;
using System.Collections.Generic;
using System.Linq;
using System.ServiceModel;
using System.Text;
using System.Threading.Tasks;

namespace IWCFServer
{
   [ServiceContract]
   public interface IWCFServer
    {
       [OperationContract]
      string GetMessage(string name);
    }
}

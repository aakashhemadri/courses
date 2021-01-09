using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.ServiceModel;

namespace WCFServiceHost
{
   class Program
   {
      static void Main(string[] args)
      {
         NetTcpBinding binding = new NetTcpBinding();
         Uri baseAddress = new Uri("net.tcp://localhost:8080/wcfserver");

         using (ServiceHost serviceHost = new ServiceHost(typeof(WCFServer.WCFServer), baseAddress))
         {
            serviceHost.AddServiceEndpoint(typeof(IWCFServer.IWCFServer), binding, baseAddress);
            serviceHost.Open();

            Console.WriteLine("The WCF server is ready at {0}.", baseAddress);
            Console.WriteLine("Press <ENTER> to terminate service...");
            Console.WriteLine();
            Console.ReadLine();
         }
      }
   }
}

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Runtime.Remoting.Channels;
using System.Runtime.Remoting.Channels.Tcp;
using System.ServiceModel;

namespace HelloRemotingServiceClient
{
   public partial class WCFClient : Form
   {
      private IWCFServer.IWCFServer server;
      public WCFClient()
      {
         InitializeComponent();
         NetTcpBinding binding = new NetTcpBinding();
         string uri = "net.tcp://localhost:8080/wcfserver";
         EndpointAddress address = new EndpointAddress(uri);
         ChannelFactory<IWCFServer.IWCFServer> channelFactory =
            new ChannelFactory<IWCFServer.IWCFServer>(binding, address);

         server = channelFactory.CreateChannel();
      }

      private void button1_Click_1(object sender, EventArgs e)
      {
         label1.Text = server.GetMessage(textBox1.Text);
      }
   }
}

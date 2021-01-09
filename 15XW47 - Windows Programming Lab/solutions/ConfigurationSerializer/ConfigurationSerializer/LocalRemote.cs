using System;
using System.Collections.Generic;
using System.Net.Sockets;
using System.Text;

namespace ConfigurationSerializer
{
    [Serializable]
    public class LocalRemote: Remote
    {
        public LocalRemote()
        {
            this.Name = "origin";
            this.URI = "path/to/repository";
            this.Protocol = "file://";
        }
        public LocalRemote(String Name, String URI) => (this.Name, this.URI, this.Protocol) = (Name, URI, "file://");
    }
}

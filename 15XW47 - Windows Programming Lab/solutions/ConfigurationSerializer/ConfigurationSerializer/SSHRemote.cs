using System;
using System.Collections.Generic;
using System.Net.Sockets;
using System.Text;

namespace ConfigurationSerializer
{
    [Serializable]
    public class SSHRemote: Remote
    {
        public SSHRemote()
        {
            this.Name = "origin";
            this.URI = "git@domain.com:user/repository";
            this.Protocol = "ssh://";
        }
        public SSHRemote(String Name, String URI) => (this.Name, this.URI, this.Protocol) = (Name, URI, "ssh://");
    }
}

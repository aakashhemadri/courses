using System;
using System.Collections.Generic;
using System.Text;

namespace ConfigurationSerializer
{
    [Serializable]
    public class HTTPRemote : Remote
    {
        public HTTPRemote()
        {
            this.Name = "origin";
            this.URI = "https://domain.com:user/repository.git";
            this.Protocol = "https://";
        }
        public HTTPRemote(String Name, String URI) => (this.Name, this.URI, this.Protocol) = (Name, URI, "https://");
    }
}

using System;
using System.Xml.Serialization;

namespace ConfigurationSerializer
{
    [XmlInclude(typeof(SSHRemote)), XmlInclude(typeof(LocalRemote)), XmlInclude(typeof(HTTPRemote))]
    [Serializable]
    public class Remote
    {
        public Remote()
        {
            this.Name = "origin";
            this.URI = System.IO.Path.GetDirectoryName(System.Reflection.Assembly.GetExecutingAssembly().CodeBase);
            this.Protocol = "file://";
        }
        public Remote(String Name, String URI, String Protocol)
        {
            this.Name = Name;
            this.URI = URI;
            this.Protocol = Protocol;
        }
        public Remote(String Name, String URI)
        {
            this.Name = Name;
            this.URI = URI;
        }
        [XmlElement]
        public String Name { get; set; }
        [XmlElement]
        public String URI { get; set; }
        [XmlAttribute]
        public String Protocol { get; set; }

        public override string ToString()
        {
            return new String("\tRemote Name: " + this.Name.ToString() + "\n\tURI: " + this.Protocol.ToString() + this.URI.ToString());
        }
        public override bool Equals(object obj)
        {
            return base.Equals(obj);
        }
        public override int GetHashCode()
        {
            return base.GetHashCode();
        }
    }
}

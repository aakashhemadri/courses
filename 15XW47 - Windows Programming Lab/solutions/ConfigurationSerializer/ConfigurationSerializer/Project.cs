using System;
using System.Xml.Serialization;

namespace ConfigurationSerializer
{
    [Serializable]
    public class Project
    {
        [XmlElement]
        public String ProjectName { get; set; }
        [XmlAttribute]
        public String Version { get; set; }
        public Project() : this(ProjectName: "Untitled", "V0.0.1") {}
        public Project(String ProjectName, String Version)
        {
            this.ProjectName = ProjectName;
            this.Version = Version;
        }
        public override string ToString()
        {
            return new String("Project Name: " + this.ProjectName.ToString() + "\nVersion: " + this.Version.ToString() );
        }
        public override bool Equals(object obj)
        {
            Project P = (Project)obj;
            return this.ProjectName.Equals(P.ProjectName) && this.Version.Equals(P.Version);
        }
        public override int GetHashCode()
        {
            return base.GetHashCode(); 
        }
        
    }
}


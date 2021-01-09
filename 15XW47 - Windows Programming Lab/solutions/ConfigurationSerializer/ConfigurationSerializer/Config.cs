using System;
using System.Collections.Generic;
using System.IO;
using System.Xml.Serialization;

namespace ConfigurationSerializer
{
    [Serializable]
    public class Config
    {
        [XmlElement]
        public Project App { get; set; }
        [XmlElement]
        public String License { get; set; }
        [XmlElement]
        public String Author { get; set; }
        [XmlArray]
        public List<Remote> Remotes{get; set;}

        public Config()
        {
            this.App = new Project();
            this.License = "None";
            this.Author = "Nil";
            this.Remotes = new List<Remote>();
        }
        public Config(Project App, String License, String Author, List<Remote> Remotes)
        {
            this.App = App;
            this.License = License;
            this.Author = Author;
            this.Remotes = Remotes;
        }
        public override String ToString()
        {
            return new String(this.App.ToString() + '\n' 
                + this.Author.ToString() + '\n'
                + this.License.ToString() + "\nRemotes:\n"
                + String.Join("\n", this.Remotes));

        }
        public override bool Equals(object obj)
        {
            Config C = (Config)obj;
            return this.App.Equals(C.App) && this.License.Equals(C.License) && this.Author.Equals(C.Author) && this.Remotes.Equals(C.Remotes);
        }
        public override int GetHashCode()
        {
            return base.GetHashCode();
        }
        public bool Serialize()
        {
            XmlSerializer Writer = new XmlSerializer(typeof(Config));
            FileStream file = null;
            try
            {
                file = File.Create(Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments) + "//ConfigSerialization.xml");
                Writer.Serialize(file, this);
            }
            catch (PathTooLongException ex)
            {
                Console.WriteLine(ex.ToString());
                return false;
            }
            catch (IOException ex)
            {
                Console.WriteLine(ex.ToString());
                return false;
            }
            finally
            {
                if (file != null)
                {
                    file.Close();
                }
            }
            return true;
        }
        public Config DeSerialize(String Path)
        {
            XmlSerializer Reader = new XmlSerializer(typeof(Config));
            StreamReader file = null;
            Config obj = new Config();
            try
            {
                file = new StreamReader(Path);
                obj = (Config)Reader.Deserialize(file);
            }
            catch (PathTooLongException ex)
            {
                Console.WriteLine(ex.ToString());
                return null;
            }
            catch (IOException ex)
            {
                Console.WriteLine(ex.ToString());
                return null;
            }
            finally
            {
                if (file != null)
                {
                    file.Close();
                }
            }
            return obj;
        }
    }
}

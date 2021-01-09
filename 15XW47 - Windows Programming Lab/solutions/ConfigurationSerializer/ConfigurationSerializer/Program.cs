using System;
using System.IO;
using System.Collections.Generic;
using System.Xml.Serialization;
/* This app tries to emulate a configuration manager\serializer
 * for handling
 * Define a configuration class having atleast two string variables, one integer, one float, one user defined class object, 
 * one list<base> variable having objects of atleast 3 different classes derived from the base. 
 * Try to xml serialize and deserialize this configuration class object.
 */
namespace ConfigurationSerializer
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
            Config ConfigHandler = new Config(new Project("The Awesome Project", "v1.0.0"),
                "MIT",
                "Aakash Hemadri <aakashhemadri123@gmail.com>",
                new List<Remote>() {
                    new SSHRemote("origin", "git@github.com:aakashhemadri/csharp"),
                    new LocalRemote("local", "C:\\Users\\WinUser\\My Documents\\csharp"),
                    new HTTPRemote("origin_alt", "github.com/aakashhemadri/csharp.git")

                });
            if (ConfigHandler.Serialize())
            {
                Console.WriteLine("Serialization Successful!");
                Config NewConfigHandler = new Config();
                if((NewConfigHandler = NewConfigHandler.DeSerialize(
                    Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments) 
                    + "//ConfigSerialization.xml")) == null )
                {
                    Console.WriteLine("DeSerialization Failed!");
                }
                else
                {
                    Console.WriteLine(NewConfigHandler.ToString());
                    Console.WriteLine("DeSerialization Successful!");
                }
            }
            else
            {
                Console.WriteLine("Serialization Failed!");
            }
        }
    }
}

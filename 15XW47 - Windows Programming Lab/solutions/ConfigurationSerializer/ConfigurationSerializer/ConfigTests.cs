using NUnit.Framework;
using System;
using System.Collections.Generic;
using System.Text;

namespace ConfigurationSerializer.Test
{
    [TestFixture]
    class ConfigTests
    {
        private Config ConfigHandler = null;
        public ConfigTests()
        {
            this.ConfigHandler = new Config(new Project("The Awesome Project", "v1.0.0"),
                "MIT",
                "Aakash Hemadri <aakashhemadri123@gmail.com>",
                new List<Remote>() {
                    new SSHRemote("origin", "git@github.com:aakashhemadri/csharp"),
                    new LocalRemote("local", "C:\\Users\\WinUser\\My Documents\\csharp"),
                    new HTTPRemote("origin_alt", "github.com/aakashhemadri/csharp.git")

                });
        }

        [Test]
        public void Test_Serializer()
        {
            Assert.IsTrue(ConfigHandler.Serialize());
        }

        [Test]
        public void Test_DeSerialize()
        {
            Assert.Equals(ConfigHandler.DeSerialize(Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments)
                    + "//ConfigSerialization.xml"), ConfigHandler);
        }
    }
}

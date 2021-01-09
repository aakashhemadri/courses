using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.Serialization.Formatters.Binary;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace SerializationSample
{
    class Program
    {
        static void Main(string[] args)
        {
            //step1: Create a object which has to be serialized
            BookStore bstore = new BookStore();
            Book b1 = new Book();
            b1.BookTitle = new BookTitleDetails();
            b1.BookTitle.Title = "How to Serialize in C#";
            b1.BookTitle.Language = "English";
            b1.Author = "Lakshma Reddy";
            b1.Category = BookCategory.Technical;
            b1.Price = 200;
            b1.Year = 2020;

            Book b2 = new Book();
            b2.BookTitle = new BookTitleDetails();
            b2.BookTitle.Title = "How to Money Heist";
            b2.BookTitle.Language = "Spanish";
            b2.Author = "Alex Pina";
            b2.Category = BookCategory.Fiction;
            b2.Price = 2000;
            b2.Year = 2017;

            bstore.books = new Book[] { b1, b2 };
            //Step2: Create a stream
            TextWriter tw = new StreamWriter(@"D:\\Training_BookStore.xml");
            //Step3: Create a formatter/serializer
            XmlSerializer xmlSerializer = new XmlSerializer(typeof(BookStore));
            xmlSerializer.Serialize(tw, bstore);
            tw.Close();

            //Deserialization
            TextReader tr = new StreamReader(@"D:\\Training_BookStore.xml");
            BookStore bstore1= (BookStore)xmlSerializer.Deserialize(tr);
            tr.Close();
            Console.WriteLine(bstore1.ToString());

            // Binary Serializer
            Stream stream = File.OpenWrite(@"D:\\Trainings_BinaryBookStore.bin");
            BinaryFormatter binaryFormatter = new BinaryFormatter();
            binaryFormatter.Serialize(stream, bstore);
            stream.Close();
            //Deserialization
            Stream s1 = File.OpenRead(@"D:\\Trainings_BinaryBookStore.bin");
            BookStore bstore2 = (BookStore)binaryFormatter.Deserialize(s1);
            s1.Close();
            Console.WriteLine(bstore2.ToString());
            Console.Read();

        }
    }
}

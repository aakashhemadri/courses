using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Policy;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace SerializationSample
{
    public enum BookCategory
    {
        Technical,
        Fiction
    }
    [Serializable]
    public class BookTitleDetails
    {
        [XmlElement]
        public string Title
        {
            get;
            set;
        }
        [XmlAttribute]
        public string Language
        {
            get;
            set;
        }
        public override string ToString()
        {
            StringBuilder sb = new StringBuilder();
            sb.Append(Title);
            sb.Append(" ");
            sb.Append(Language);
            sb.Append(" ");
            return sb.ToString();
        }
    }
    [Serializable]
    public class Book
    {
        [XmlElement]
        public BookTitleDetails BookTitle
        {
            get;
            set;
        }
        [XmlAttribute]
        public BookCategory Category
        {
            get;
            set;
        }
        [XmlElement]
        public string Author
        {
            get;
            set;
        }
        [XmlElement]
        public double Price
        {
            get;
            set;
        }
        [XmlElement]
        public int Year
        {
            get;
            set;
        }
        public override string ToString()
        {
            StringBuilder sb = new StringBuilder();
            sb.Append(BookTitle.ToString());
            sb.Append(" ");
            sb.Append(Category);
            sb.Append(" ");
            sb.Append(Author);
            sb.Append(" ");
            sb.Append(Price);
            sb.Append(" ");
            sb.Append(Year);
            sb.Append(" ");
            
            return sb.ToString();
        }
    }
    [Serializable]
    public class BookStore
    {
        [XmlArray]
        public Book[] books
        {
            get;
            set;
        }
        public override string ToString()
        {
            StringBuilder sb = new StringBuilder();
            foreach(Book b in books)
            {
                sb.Append(b.ToString());
                sb.Append("\r\n");
            }
            return sb.ToString();
        }

    }
}

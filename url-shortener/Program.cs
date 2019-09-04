using System;
using System.Collections.Generic;

namespace url_shortener
{
    class Program
    {
        static void Main(string[] args)
        {
            int Input = 0;
            string UserEnteredUrl;
            string NewPath;
            IUrlManipulator Manipulator = null;
            IList<string> SeparatedUrlParts;

            do{
                Console.WriteLine("Press 1 to shorten a url or press 2 to get the full url.");
            }while ( Int32.TryParse(Console.ReadKey().ToString(), out Input) && (Input == 1 || Input == 2));
           
            Console.WriteLine("Please enter your url:");

            UserEnteredUrl = Console.ReadLine();
            //TODO:: Add check for valid url -- do while with regex inside a method as the condition

            SeparatedUrlParts = SeparatePathFormUrl(UserEnteredUrl);

            if(SeparatedUrlParts.Count == 2){
                switch(Input){
                    case 1:
                        Manipulator = new Shortener();
                        break; 
                    case 2:
                        Manipulator = new RetriveFull();
                        break;
                }
            } 
            // the index at 1 will always be the second half of the url (the part we want to change)
            NewPath = Manipulator.Change(SeparatedUrlParts[1]);

            Console.WriteLine("Yourid new url is: " + SeparatedUrlParts[0] + NewPath);
            
        }
        public static  IList<string> SeparatePathFormUrl(string url){
            IList<string> PartsList = new List<string>();
            int separator = url.IndexOf('/',10);
            PartsList.Add(url.Substring(0 , separator)); 
            PartsList.Add(url.Substring(separator+1)); 
            return PartsList;
        }
    }
    public class DatabaseModel
    {
        public int id {get; set;}
        public string uri {get; set;}
    }
    
    public interface IUrlManipulator{
        string Change(string value);

    }
    public class Shortener : IUrlManipulator{
        private DatabaseConnection DBConn;
        public Shortener(){
            DBConn = new DatabaseConnection();
        }
        public string Change(string value){
            int id = DBConn.GetFeildByUri(value);
            return Parse(id);
        }
        private string Parse(int id){
            return "";
        }

    }
    public class RetriveFull : IUrlManipulator{
        private DatabaseConnection DBConn;
        public RetriveFull(){
            DBConn = new DatabaseConnection();
        }
        public string Change(string value){
            int id = Parse(value);
            return DBConn.GetFeildById(id);
        }
        private int Parse(string id){
            return 0;
        }
    }
    public class DatabaseConnection{

        public string GetFeildById(int id){




            return "";
        }
        public int GetFeildByUri(string uri){




            return 0;
        }
    }

}
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO.Ports;
using System.Windows.Forms;

namespace arduinoController
{
    class Program
    {
        static void Main(string[] args)
        {
            String command = "h";
            String number = "";
            int numMan = 0;
            bool loopManager = true;

            //Instantiate the communications
            //Create a port with some basic settings

            SerialPort port = new SerialPort("COM3", 9600, Parity.None, 8, StopBits.One);

            //Open the port for communication
            port.Open();
            while (loopManager == true) {

                var kbInput = Console.ReadKey();
                switch (kbInput.Key) {
                    case ConsoleKey.W:
                        command = "4";
                        numMan += 10;
                        number = command + numMan.ToString();
                        Console.WriteLine("w");
                    break;

                    case ConsoleKey.S:
                        command = "4";
                        numMan -= 10;
                        number = command + numMan.ToString();
                        Console.WriteLine("s");
                    break;
                    case ConsoleKey.UpArrow:
                        command = "1";
                        numMan += 10;
                        number = command + numMan.ToString();
                        break;
                    case ConsoleKey.DownArrow:
                        command = "1";
                        numMan += 10;
                        number = command + numMan.ToString();
                        break;
                    case ConsoleKey.LeftArrow:
                        command = "2";
                        numMan -= 10;
                        number = command + numMan.ToString();
                        break;
                    case ConsoleKey.RightArrow:
                        command = "2";
                        numMan += 10;
                        number = command + numMan.ToString();
                        break;
                    case ConsoleKey.Spacebar:
                        number = "10";
                        port.Write("10");
                        port.Write("20");
                        port.Write("30");
                        port.Write("40");
                        Console.WriteLine("Kill");
                        break;
                }


                port.Write(number);

            }
            port.Close();

            Console.ReadKey();
        }

        private void sendSampleData()
        {
            /*//Instantiate the communications
            //Create a port with some basic settings

            SerialPort port = new SerialPort("COM3", 9600, Parity.None, 8, StopBits.One);
            wasd
            //Open the port for communication
            port.Open();

            port.Write("1126");

            port.Close();

            Console.ReadKey();*/
        }
    }
}

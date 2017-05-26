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
            int altitudePower = 0;
            int yawPower = 0;
            int rollPower = 0; 
            int pitchPower = 0;
            bool loopManager = true;

            //Instantiate the communications
            //Create a port with some basic settings

            SerialPort port = new SerialPort("COM3", 9600, Parity.None, 8, StopBits.One);

            //Open the port for communication
            port.Open();
            while (loopManager == true)
            {

                var kbInput = Console.ReadKey();
                switch (kbInput.Key)
                {
                    case ConsoleKey.W:
                        command = "3";
                        yawPower += 10;
                        number = command + yawPower.ToString();
                        Console.WriteLine("w");
                        break;

                    case ConsoleKey.S:
                        command = "3";
                        yawPower -= 10;
                        number = command + yawPower.ToString();
                        Console.WriteLine("s");
                        break;
                    case ConsoleKey.UpArrow:
                        command = "4";
                        altitudePower += 10;
                        number = command + altitudePower.ToString();
                        break;
                    case ConsoleKey.DownArrow:
                        command = "4";
                        altitudePower += 10;
                        number = command + altitudePower.ToString();
                        break;
                    case ConsoleKey.LeftArrow:
                        command = "1";
                        pitchPower -= 10;
                        number = command + pitchPower.ToString();
                        break;
                    case ConsoleKey.RightArrow:
                        command = "1";
                        pitchPower += 10;
                        number = command + pitchPower.ToString();
                        break;
                    case ConsoleKey.Spacebar:
                        number = "40";
                        //port.Write(number);
                        /*number = "30";
                        port.Write(number);
                        number = "20";
                        port.Write(number);
                        number = "10";
                        port.Write(number);*/
                        altitudePower = 0;
                        pitchPower = 0;
                        yawPower = 0;
                        rollPower = 0;
                        Console.WriteLine("Kill");
                        break;
                }


                port.Write(number);
                Console.WriteLine(number);

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
